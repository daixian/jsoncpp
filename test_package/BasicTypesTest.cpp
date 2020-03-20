#include "gtest/gtest.h"
#define XUEXUE_JSON_SUPPORT_OPENCV
#define XUEXUE_JSON_SUPPORT_EIGEN
#include "xuexuejson/Serialize.hpp"
#include "Poco/Format.h"
#include <thread>
#include <boost/format.hpp>

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

class BasicTypes_int64_t : XUEXUE_JSON_OBJECT
{
  public:
    //这个类必须要包含一个无参构造
    BasicTypes_int64_t(int64_t data = 0) : data(data) {}
    ~BasicTypes_int64_t() {}

    //只包含一个int64数据
    int64_t data;

    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const
    {
        value.SetObject();
        value.AddMember("data", xuexue::json::Serialize::toValue(data, xuexue::json::Value(), allocator), allocator);
        return std::move(value);
    }
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const
    {
        value.SetObject();
        value.AddMember(L"data", xuexue::json::Serialize::toValue(data, xuexue::json::ValueW(), allocator), allocator);
        return std::move(value);
    }
    virtual void getObj(const xuexue::json::Value& value)
    {
        if (value.HasMember("data")) {
            xuexue::json::Serialize::getObj(value["data"], data);
        }
    }
    virtual void getObj(const xuexue::json::ValueW& value)
    {
        if (value.HasMember(L"data")) {
            xuexue::json::Serialize::getObj(value[L"data"], data);
        }
    }
};

TEST(BasicTypes, int64_t_123)
{
    BasicTypes_int64_t o(static_cast<int64_t>(123));

    string text = JsonMapper::toJson(o);
    BasicTypes_int64_t o2 = JsonMapper::toObject<BasicTypes_int64_t>(text);
    ASSERT_TRUE(o.data == o2.data);
}

TEST(BasicTypes, int64_t_LONG_MIN)
{
    ASSERT_TRUE(static_cast<int64_t>(LONG_MIN) == LONG_MIN);
    BasicTypes_int64_t o(static_cast<int64_t>(LONG_MIN));

    string text = JsonMapper::toJson(o);
    BasicTypes_int64_t o2 = JsonMapper::toObject<BasicTypes_int64_t>(text);
    ASSERT_TRUE(o.data == o2.data);
}

//------------------------------------------------------------------------------
// 这包含一个对象嵌套测试和基本类型测试

class ClassA : XUEXUE_JSON_OBJECT
{
  public:
    ClassA() {}
    ~ClassA() {}

    Eigen::Vector3d v0;
    cv::Vec3d v1;

    XUEXUE_JSON_OBJECT_M2(v0, v1);

  private:
};

class ClassB : XUEXUE_JSON_OBJECT
{
  public:
    ClassB() {}
    ~ClassB() {}

    string str;
    bool b = false;
    unsigned char uc;
    char c;
    unsigned short usi = 0;
    short si = 0;
    unsigned int ui = 0;
    int i = 0;
    uint64_t uli = 0;
    int64_t li = 0;
    ClassA oa;

    XUEXUE_JSON_OBJECT_M11(str, b, uc, c, usi, si, ui, i, uli, li, oa);

  private:
};

TEST(BasicTypes, classNest_BaseTypeMin)
{
    ClassB ob;
    ob.str = "12312是是";
    ob.b = true;
    ob.uc = UCHAR_MAX;
    ob.c = CHAR_MIN;
    ob.usi = USHRT_MAX;
    ob.si = SHRT_MIN;
    ob.ui = UINT_MAX;
    ob.i = INT_MIN;
    ob.uli = ULONG_MAX;
    ob.li = LONG_MIN;

    ob.oa.v0 = Eigen::Vector3d(123, 3123543, 53456);
    ob.oa.v1 = cv::Vec3d(345, 321, 76);

    string text = JsonMapper::toJson(ob);
    ClassB ob2 = JsonMapper::toObject<ClassB>(text);
    std::cout << text << std::endl;

    ASSERT_TRUE(ob.str == ob2.str);
    ASSERT_TRUE(ob.b == ob2.b);
    ASSERT_TRUE(ob.uc == ob2.uc);
    ASSERT_TRUE(ob.c == ob2.c);
    ASSERT_TRUE(ob.usi == ob2.usi);
    ASSERT_TRUE(ob.si == ob2.si);
    ASSERT_TRUE(ob.ui == ob2.ui);
    ASSERT_TRUE(ob.i == ob2.i);
    ASSERT_TRUE(ob.uli == ob2.uli);
    ASSERT_TRUE(ob.li == ob2.li) << ob.li << "<->" << ob2.li;

    ASSERT_TRUE(ob.oa.v0 == ob2.oa.v0);
    ASSERT_TRUE(ob.oa.v1 == ob2.oa.v1);

    //string的长度小于15字节的话或许可以这样比较?
    //应该不行0xcc是未初始化地址，release下可能会出错
    // /GZ选项编译代码时，未初始化的变量将自动分配给该值（字节级别）
    //ASSERT_TRUE(std::memcmp(&ob, &ob2, sizeof(ob)) == 0);
}

TEST(BasicTypes, classNest_BaseTypeMax)
{
    ClassB ob;
    ob.str = "字符串额= =";
    ob.b = true;
    ob.uc = UCHAR_MAX;
    ob.c = CHAR_MAX;
    ob.usi = USHRT_MAX;
    ob.si = SHRT_MAX;
    ob.ui = UINT_MAX;
    ob.i = INT_MAX;
    ob.uli = ULONG_MAX;
    ob.li = LONG_MAX;

    ob.oa.v0 = Eigen::Vector3d(123, 3123543, 53456);
    ob.oa.v1 = cv::Vec3d(345, 321, 76);

    string text = JsonMapper::toJson(ob);
    ClassB ob2 = JsonMapper::toObject<ClassB>(text);
    std::cout << text << std::endl;

    ASSERT_TRUE(ob.str == ob2.str);
    ASSERT_TRUE(ob.b == ob2.b);
    ASSERT_TRUE(ob.uc == ob2.uc);
    ASSERT_TRUE(ob.c == ob2.c);
    ASSERT_TRUE(ob.usi == ob2.usi);
    ASSERT_TRUE(ob.si == ob2.si);
    ASSERT_TRUE(ob.ui == ob2.ui);
    ASSERT_TRUE(ob.i == ob2.i);
    ASSERT_TRUE(ob.uli == ob2.uli);
    ASSERT_TRUE(ob.li == ob2.li) << ob.li << "<->" << ob2.li;

    ASSERT_TRUE(ob.oa.v0 == ob2.oa.v0);
    ASSERT_TRUE(ob.oa.v1 == ob2.oa.v1);
}