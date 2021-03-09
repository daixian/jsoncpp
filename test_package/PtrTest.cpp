#include "gtest/gtest.h"
#include "xuexuejson/JsonMapper.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

class A : XUEXUE_JSON_OBJECT
{
  public:
    int i;
    std::string str;

    XUEXUE_JSON_OBJECT_M2(i, str)
};

class B : XUEXUE_JSON_OBJECT
{
  public:
    A mem1;
    std::shared_ptr<A> mem2;

    XUEXUE_JSON_OBJECT_M2(mem1, mem2)
};

TEST(Ptr, shared_ptr)
{
    B b;
    b.mem1.i = 123;
    b.mem1.str = "3131321";
    b.mem2 = std::make_shared<A>();
    b.mem2->i = 666;
    b.mem2->str = "°¥";

    std::string json = JsonMapper::toJson(b);
    B b2 = JsonMapper::toObject<B>(json);

    ASSERT_EQ(b.mem1.i, b2.mem1.i);
    ASSERT_EQ(b.mem1.str, b2.mem1.str);
    ASSERT_EQ(b.mem2->i, b2.mem2->i);
    ASSERT_EQ(b.mem2->str, b2.mem2->str);
}

class C : XUEXUE_JSON_OBJECT
{
  public:
    std::unique_ptr<A> mem1;

    XUEXUE_JSON_OBJECT_M1(mem1)
};

TEST(Ptr, unique_ptr)
{
    C c;
    c.mem1 = std::unique_ptr<A>(new A());
    c.mem1->i = 666;
    c.mem1->str = "°¥";

    std::string json = JsonMapper::toJson(c);
    C c2 = JsonMapper::toObject<C>(json);

    ASSERT_EQ(c.mem1->i, c2.mem1->i);
    ASSERT_EQ(c.mem1->str, c2.mem1->str);
}