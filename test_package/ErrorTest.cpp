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

TEST(Error, emptystr)
{
    ASSERT_THROW((JsonMapper::toObject<map<int, string>>("")), std::exception);
}

// 如果是一段数字那么是没有错误的
TEST(Error, text_21312)
{
    bool isThrow = false;
    try {
        int mis3 = JsonMapper::toObject<int>("21312");
        ASSERT_EQ(mis3, 21312);
    }
    catch (const std::exception& e) {
        isThrow = true;
    }
    ASSERT_FALSE(isThrow);
}
