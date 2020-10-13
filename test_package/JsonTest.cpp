#include "gtest/gtest.h"
#include "xuexuejson/Serialize.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

TEST(Json, rpTest)
{
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();
    doc.AddMember(L"item", Serialize::toValue(L"31231312213", ValueW(), allocator), allocator);
    //保存到string
    wstring text = JsonHelper::toJsonW(doc);

    wstring obj2;
    Serialize::getObj(doc[L"item"], obj2);
    //v.Set(123132);
}

TEST(Json, typeAdapte)
{
    //string->i
    vector<string> vs;
    for (size_t i = 0; i < 100; i++) {
        vs.push_back(std::to_string(i));
    }
    string texe = JsonMapper::toJson(vs, false);

    //把一个string的用int接下来
    vector<int> vs2 = JsonMapper::toObject<vector<int>>(texe);

    for (size_t i = 0; i < vs.size(); i++) {
        ASSERT_EQ(std::to_string(vs2[i]), vs[i]);
    }

    texe = JsonMapper::toJson("true", false);
    bool b = false;
    b = JsonMapper::toObject<bool>(texe);
    ASSERT_EQ(b, true);

    texe = JsonMapper::toJson("false", false);
    b = JsonMapper::toObject<bool>(texe);
    ASSERT_EQ(b, false);
}

TEST(Json, unity3dColor32)
{
    unity3d::Color32 color(255, 123, 32);
    string text = JsonMapper::toJson(color);
    unity3d::Color32 o2 = JsonMapper::toObject<unity3d::Color32>(text);
    ASSERT_TRUE(color == o2);
}
