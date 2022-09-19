#include "gtest/gtest.h"

#include "xuexuejson/JsonMapper.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

enum MyEnumE
{
    MyEE1 = 3,
    MyEE2,
    MyEE3

};

/**
 * @brief 最普通的写法.不写继承int
 */
enum class MyEnumC
{
    MyEC1 = 5,
    MyEC2,
    MyEC3

};

class MyClassA : XUEXUE_JSON_OBJECT
{
  public:
    MyClassA() {}
    ~MyClassA() {}

    enum MyEnum : int
    {
        E1 = 0,
        E2,
        E3

    };

    enum class MyEnum2 : int
    {
        EC1 = 0,
        EC2,
        EC3

    };

    //一个外部的枚举
    MyEnumE myee = MyEnumE::MyEE1;

    //一个外部的带class枚举
    MyEnumC mye = MyEnumC::MyEC1;

    //类中的枚举
    MyEnum e = E1;

    //类中的带class的枚举
    MyEnum2 ec = MyEnum2::EC1;

    XUEXUE_JSON_OBJECT_M4(myee, mye, e, ec)

  private:
};

TEST(Enum, MyClassA)
{
    MyClassA dto;
    dto.myee = MyEnumE::MyEE2;
    dto.mye = MyEnumC::MyEC2;
    dto.e = MyClassA::MyEnum::E3;
    dto.ec = MyClassA::MyEnum2::EC2;

    //这是代码实现原理
    ASSERT_TRUE(std::is_enum<MyEnumE>::value);
    ASSERT_TRUE(std::is_enum<MyEnumC>::value);
    ASSERT_TRUE(std::is_enum<MyClassA::MyEnum>::value);
    ASSERT_TRUE(std::is_enum<MyClassA::MyEnum2>::value);

    string json = JsonMapper::toJson(dto);
    MyClassA dto2 = JsonMapper::toObject<MyClassA>(json);

    ASSERT_EQ(dto.myee, dto2.myee);
    ASSERT_EQ(dto.mye, dto2.mye);
    ASSERT_EQ(dto.e, dto2.e);
    ASSERT_EQ(dto.ec, dto2.ec);
}