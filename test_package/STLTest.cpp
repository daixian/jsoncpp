#include "gtest/gtest.h"
#include "xuexuejson/Serialize.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

TEST(STL, ListTest)
{
    list<string> ls;
    for (size_t i = 0; i < 100; i++) {
        ls.push_back("这个是一条内容" + std::to_string(i));
    }
    for (size_t i = 0; i < 100; i++) {

        string texe = JsonMapper::toJson(ls, true);
        list<string> ls2;
        JsonMapper::toObject(texe, ls2);

        list<string> ls3 = std::move(JsonMapper::toObject<list<string>>(texe));
        auto it2 = ls2.begin();
        auto it3 = ls3.begin();
        for (auto& item : ls) {
            ASSERT_EQ(item, *it2);
            ASSERT_EQ(item, *it3);
            ++it2;
            ++it3;
        }
    }
}

TEST(STL, ArrayTest)
{
    array<string, 100> arr;
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = ("这个是一条内容" + std::to_string(i));
    }
    for (size_t i = 0; i < 100; i++) {

        string texe = JsonMapper::toJson(arr, true);
        array<string, 100> arr2;
        JsonMapper::toObject(texe, arr2);

        array<string, 100> arr3 = JsonMapper::toObject<array<string, 100>>(texe);

        for (size_t i = 0; i < arr.size(); i++) {
            ASSERT_EQ(arr[i], arr2[i]);
            ASSERT_EQ(arr[i], arr3[i]);
        }
    }
}

class VectorData : public testing::Test
{
  protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }

  public:
    class Data : XUEXUE_JSON_OBJECT
    {
      public:
        Data()
        {
            for (size_t i = 0; i < 20; i++) {
                vs.push_back(string("这个是一条内容") + to_string(i) + string("❀❀❀❀"));
            }
            for (size_t i = 0; i < 20; i++) {
                vvs.push_back(vs);
            }
            for (size_t i = 0; i < 20; i++) {
                vvvs.push_back(vvs);
            }
        }
        ~Data() {}

        vector<string> vs;
        vector<vector<string>> vvs;
        vector<vector<vector<string>>> vvvs;

        XUEXUE_JSON_OBJECT_M3(vs, vvs, vvvs)
    };

    Data data;
};

TEST_F(VectorData, vectorTest)
{
    for (size_t i = 0; i < 10; i++) {
        string text = JsonMapper::toJson(data);
        Data data2 = JsonMapper::toObject<Data>(text);

        for (size_t i = 0; i < data.vs.size(); i++) {
            ASSERT_EQ(data.vs[i], data2.vs[i]);
        }
        for (size_t i = 0; i < data.vvs.size(); i++) {
            ASSERT_EQ(data.vvs[i], data2.vvs[i]);
        }
        for (size_t i = 0; i < data.vvvs.size(); i++) {
            ASSERT_EQ(data.vvvs[i], data2.vvvs[i]);
        }
    }
}

TEST(STL, EmptyTest)
{
    vector<string> vs;
    string texe = JsonMapper::toJson(vs, false);
    ASSERT_EQ(texe, "[]");
    vector<string> vs2 = JsonMapper::toObject<vector<string>>(texe);
    ASSERT_EQ(vs2.size(), 0);

    map<int, string> mis;
    texe = JsonMapper::toJson(mis, true);
    ASSERT_EQ(texe, "{}");
    map<int, string> mis2 = JsonMapper::toObject<map<int, string>>(texe);
    ASSERT_EQ(mis2.size(), 0);

    //这是一个类型不匹配的错误
    string str;
    Serialize::getObj(Value(kNullType), str);
}
