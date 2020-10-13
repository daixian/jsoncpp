#include "gtest/gtest.h"

#include "xuexuejson/Serialize.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

TEST(Error, wrongjson)
{
    ASSERT_THROW((JsonMapper::toObject<string>("{ a : 1 }")), std::exception);
}

TEST(Error, wrongjson2)
{
    ASSERT_THROW((JsonMapper::toObject<map<int, string>>("{ a : 1 }")), std::exception);
}

TEST(Error, wrongjson3)
{
    //TODO:这里实际是个错的json,但是有适配解析就给它解析了
    map<int, string> obj = JsonMapper::toObject<map<int, string>>("{ \"a\" : 1 }");
    ASSERT_EQ(obj.size(), 1);
}

TEST(Error, wrongjson4)
{
    //这个json能被解析,但是没有符合的内容,所以不会有异常,是个空数组.
    std::vector<int> obj = JsonMapper::toObject<std::vector<int>>("{ \"a\" : 1 }");
    ASSERT_EQ(obj.size(), 0);
}

TEST(Error, emptystr)
{
    ASSERT_THROW((JsonMapper::toObject<map<int, string>>("")), std::exception);
}

TEST(Error, textNum)
{
    bool isThrow = false;
    try {
        //这个不会被算作是错误
        int mis3 = JsonMapper::toObject<int>("21312");
        ASSERT_EQ(mis3, 21312);
    }
    catch (const std::exception& e) {
        isThrow = true;
    }
    ASSERT_FALSE(isThrow);
}