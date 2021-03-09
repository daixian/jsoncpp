#include "gtest/gtest.h"

#include "xuexuejson/Serialize.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

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

    MyEnum e = E1;

    MyEnum2 ec = MyEnum2::EC1;

    XUEXUE_JSON_OBJECT_M2(e, ec)

  private:
};

TEST(Enum, MyClassA)
{
    MyClassA dto;
    dto.e = MyClassA::MyEnum::E3;
    dto.ec = MyClassA::MyEnum2::EC2;

    ASSERT_TRUE(std::is_enum<MyClassA::MyEnum>::value);
    ASSERT_TRUE(std::is_enum<MyClassA::MyEnum2>::value);

    string json = JsonMapper::toJson(dto);
    MyClassA dto2 = JsonMapper::toObject<MyClassA>(json);

    ASSERT_EQ(dto.e, dto2.e);
    ASSERT_EQ(dto.ec, dto2.ec);
}