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