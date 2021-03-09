#include "gtest/gtest.h"
#include "xuexuejson/JsonMapper.hpp"
#include <thread>

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

TEST(BasicTypes, int)
{
    ASSERT_EQ(JsonMapper::toObject<int>("21312"), 21312);
    ASSERT_EQ(JsonMapper::toJson(21312), "21312");
}

TEST(BasicTypes, INT_MAX_TEST)
{
    ASSERT_EQ(JsonMapper::toObject<int>("2147483647"), INT_MAX);
    ASSERT_EQ(JsonMapper::toJson(INT_MAX), "2147483647");
}

TEST(BasicTypes, INT_MIN_TEST)
{
    ASSERT_EQ(JsonMapper::toObject<int>("-2147483648"), INT_MIN);
    ASSERT_EQ(JsonMapper::toJson(INT_MIN), "-2147483648");
}

TEST(BasicTypes, float)
{
    ASSERT_EQ(JsonMapper::toObject<float>("2.5"), 2.5);
    ASSERT_EQ(JsonMapper::toJson(2.5), "2.5");
}

TEST(BasicTypes, int_float)
{
    //整数写法的浮点也要支持
    ASSERT_EQ(JsonMapper::toObject<float>("2"), 2);
    ASSERT_EQ(JsonMapper::toJson(2.0f), "2.0");
}

TEST(BasicTypes, int_double)
{
    //整数写法的浮点也要支持
    ASSERT_EQ(JsonMapper::toObject<double>("2"), 2);
    ASSERT_EQ(JsonMapper::toJson(2.0), "2.0");
}

TEST(BasicTypes, bool)
{
    ASSERT_EQ(JsonMapper::toObject<bool>("\"true\""), true);
    string text = JsonMapper::toJson(true);
    ASSERT_EQ(JsonMapper::toJson(true), "true");
}

TEST(BasicTypes, char)
{
    ASSERT_EQ(JsonMapper::toObject<char>("21312"), (char)21312);
    ASSERT_EQ(JsonMapper::toJson((char)100), "100");
}

//------------------------------------------------------------------------------

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
    ASSERT_EQ(o.data, o2.data);
}

TEST(BasicTypes, int64_t_LONG_MIN)
{
    ASSERT_EQ(static_cast<int64_t>(LONG_MIN), LONG_MIN);
    BasicTypes_int64_t o(static_cast<int64_t>(LONG_MIN));

    string text = JsonMapper::toJson(o);
    BasicTypes_int64_t o2 = JsonMapper::toObject<BasicTypes_int64_t>(text);
    ASSERT_EQ(o.data, o2.data);
}

//------------------------------------------------------------------------------
// 这包含一个对象嵌套测试和基本类型测试

class ClassA : XUEXUE_JSON_OBJECT
{
  public:
    ClassA() {}
    ~ClassA() {}

    string str;
    bool b = false;
    unsigned char uc = 0;
    char c = 0;
    unsigned short usi = 0;
    short si = 0;
    unsigned int ui = 0;
    int i = 0;
    uint64_t uli = 0;
    int64_t li = 0;

    XUEXUE_JSON_OBJECT_M10(str, b, uc, c, usi, si, ui, i, uli, li)

  private:
};

class ClassB : XUEXUE_JSON_OBJECT
{
  public:
    ClassB() {}
    ~ClassB() {}

    string str;
    bool b = false;
    unsigned char uc = 0;
    char c = 0;
    unsigned short usi = 0;
    short si = 0;
    unsigned int ui = 0;
    int i = 0;
    uint64_t uli = 0;
    int64_t li = 0;
    ClassA oa;

    XUEXUE_JSON_OBJECT_M11(str, b, uc, c, usi, si, ui, i, uli, li, oa)

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

    ob.oa.str = "12312是是";
    ob.oa.b = true;
    ob.oa.uc = UCHAR_MAX;
    ob.oa.c = CHAR_MIN;
    ob.oa.usi = USHRT_MAX;
    ob.oa.si = SHRT_MIN;
    ob.oa.ui = UINT_MAX;
    ob.oa.i = INT_MIN;
    ob.oa.uli = ULONG_MAX;
    ob.oa.li = LONG_MIN;

    string text = JsonMapper::toJson(ob);
    ClassB ob2 = JsonMapper::toObject<ClassB>(text);
    std::cout << text << std::endl;

    ASSERT_EQ(ob.str, ob2.str);
    ASSERT_EQ(ob.b, ob2.b);
    ASSERT_EQ(ob.uc, ob2.uc);
    ASSERT_EQ(ob.c, ob2.c);
    ASSERT_EQ(ob.usi, ob2.usi);
    ASSERT_EQ(ob.si, ob2.si);
    ASSERT_EQ(ob.ui, ob2.ui);
    ASSERT_EQ(ob.i, ob2.i);
    ASSERT_EQ(ob.uli, ob2.uli);
    ASSERT_EQ(ob.li, ob2.li);

    ASSERT_EQ(ob.oa.str, ob2.oa.str);
    ASSERT_EQ(ob.oa.b, ob2.oa.b);
    ASSERT_EQ(ob.oa.uc, ob2.oa.uc);
    ASSERT_EQ(ob.oa.c, ob2.oa.c);
    ASSERT_EQ(ob.oa.usi, ob2.oa.usi);
    ASSERT_EQ(ob.oa.si, ob2.oa.si);
    ASSERT_EQ(ob.oa.ui, ob2.oa.ui);
    ASSERT_EQ(ob.oa.i, ob2.oa.i);
    ASSERT_EQ(ob.oa.uli, ob2.oa.uli);
    ASSERT_EQ(ob.oa.li, ob2.oa.li);

    //string的长度小于15字节的话或许可以这样比较?
    //应该不行0xcc是未初始化地址，release下可能会出错
    // /GZ选项编译代码时，未初始化的变量将自动分配给该值（字节级别）
    //ASSERT_EQ(std::memcmp(&ob, &ob2, sizeof(ob)) , 0);
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

    ob.oa.str = "12312是是";
    ob.oa.b = true;
    ob.oa.uc = UCHAR_MAX;
    ob.oa.c = CHAR_MAX;
    ob.oa.usi = USHRT_MAX;
    ob.oa.si = SHRT_MAX;
    ob.oa.ui = UINT_MAX;
    ob.oa.i = INT_MAX;
    ob.oa.uli = ULONG_MAX;
    ob.oa.li = LONG_MAX;

    string text = JsonMapper::toJson(ob);
    ClassB ob2 = JsonMapper::toObject<ClassB>(text);
    std::cout << text << std::endl;

    ASSERT_EQ(ob.str, ob2.str);
    ASSERT_EQ(ob.b, ob2.b);
    ASSERT_EQ(ob.uc, ob2.uc);
    ASSERT_EQ(ob.c, ob2.c);
    ASSERT_EQ(ob.usi, ob2.usi);
    ASSERT_EQ(ob.si, ob2.si);
    ASSERT_EQ(ob.ui, ob2.ui);
    ASSERT_EQ(ob.i, ob2.i);
    ASSERT_EQ(ob.uli, ob2.uli);
    ASSERT_EQ(ob.li, ob2.li) << ob.li << "<->" << ob2.li;

    ASSERT_EQ(ob.oa.str, ob2.oa.str);
    ASSERT_EQ(ob.oa.b, ob2.oa.b);
    ASSERT_EQ(ob.oa.uc, ob2.oa.uc);
    ASSERT_EQ(ob.oa.c, ob2.oa.c);
    ASSERT_EQ(ob.oa.usi, ob2.oa.usi);
    ASSERT_EQ(ob.oa.si, ob2.oa.si);
    ASSERT_EQ(ob.oa.ui, ob2.oa.ui);
    ASSERT_EQ(ob.oa.i, ob2.oa.i);
    ASSERT_EQ(ob.oa.uli, ob2.oa.uli);
    ASSERT_EQ(ob.oa.li, ob2.oa.li) << ob.oa.li << "<->" << ob2.oa.li;
}

TEST(BasicTypes, toDocument)
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

    ob.oa.str = "12312是是";
    ob.oa.b = true;
    ob.oa.uc = UCHAR_MAX;
    ob.oa.c = CHAR_MIN;
    ob.oa.usi = USHRT_MAX;
    ob.oa.si = SHRT_MIN;
    ob.oa.ui = UINT_MAX;
    ob.oa.i = INT_MIN;
    ob.oa.uli = ULONG_MAX;
    ob.oa.li = LONG_MIN;

    string text = JsonMapper::toJson(ob, false);

    //测试一下toDocument方法
    auto doc = JsonMapper::toDocument(ob);
    string text_doc = JsonHelper::toJson(doc, false);
    EXPECT_TRUE(text == text_doc);
}

TEST(BasicTypes, toDocument2)
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

    ob.oa.str = "12312是是";
    ob.oa.b = true;
    ob.oa.uc = UCHAR_MAX;
    ob.oa.c = CHAR_MIN;
    ob.oa.usi = USHRT_MAX;
    ob.oa.si = SHRT_MIN;
    ob.oa.ui = UINT_MAX;
    ob.oa.i = INT_MIN;
    ob.oa.uli = ULONG_MAX;
    ob.oa.li = LONG_MIN;

    string text = JsonMapper::toJson(ob, false);

    //测试一下toDocument方法
    Document doc;
    JsonMapper::toDocument(ob, doc);
    string text_doc = JsonHelper::toJson(doc, false);
    EXPECT_TRUE(text == text_doc);
}

TEST(BasicTypes, toDocumentW)
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

    ob.oa.str = "12312是是";
    ob.oa.b = true;
    ob.oa.uc = UCHAR_MAX;
    ob.oa.c = CHAR_MIN;
    ob.oa.usi = USHRT_MAX;
    ob.oa.si = SHRT_MIN;
    ob.oa.ui = UINT_MAX;
    ob.oa.i = INT_MIN;
    ob.oa.uli = ULONG_MAX;
    ob.oa.li = LONG_MIN;

    wstring text = JsonMapper::toJsonW(ob, false);

    //测试一下toDocument方法
    auto doc = JsonMapper::toDocumentW(ob);
    wstring text_doc = JsonHelper::toJsonW(doc, false);
    EXPECT_TRUE(text == text_doc);
}

TEST(BasicTypes, toDocumentW2)
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

    ob.oa.str = "12312是是";
    ob.oa.b = true;
    ob.oa.uc = UCHAR_MAX;
    ob.oa.c = CHAR_MIN;
    ob.oa.usi = USHRT_MAX;
    ob.oa.si = SHRT_MIN;
    ob.oa.ui = UINT_MAX;
    ob.oa.i = INT_MIN;
    ob.oa.uli = ULONG_MAX;
    ob.oa.li = LONG_MIN;

    wstring text = JsonMapper::toJsonW(ob, false);

    //测试一下toDocument方法
    DocumentW doc;
    JsonMapper::toDocumentW(ob, doc);
    wstring text_doc = JsonHelper::toJsonW(doc, false);
    EXPECT_TRUE(text == text_doc);
}