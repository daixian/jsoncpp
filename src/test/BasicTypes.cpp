#include "gtest/gtest.h"
#define XUEXUE_JSON_SUPPORT_OPENCV
#define XUEXUE_JSON_SUPPORT_EIGEN
#include "../xuexuejson/Serialize.hpp"
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

    int64_t data;
    XUEXUE_JSON_OBJECT_M1(data)
};
TEST(BasicTypes, int64_t_123)
{
    BasicTypes_int64_t o{123};

    string text = JsonMapper::toJson(o);
    BasicTypes_int64_t o2 = JsonMapper::toObject<BasicTypes_int64_t>(text);
    ASSERT_TRUE(o.data == o2.data);
}

TEST(BasicTypes, int64_t_LONG_MIN)
{
    BasicTypes_int64_t o{LONG_MIN};

    string text = JsonMapper::toJson(o);
    BasicTypes_int64_t o2 = JsonMapper::toObject<BasicTypes_int64_t>(text);
    ASSERT_TRUE(o.data == o2.data);
}