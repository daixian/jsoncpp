#include "gtest/gtest.h"

#define XUEXUE_JSON_SUPPORT_EIGEN
#include "xuexuejson/Serialize.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

class cvComponent : XUEXUE_JSON_SUPER_OBJECT
{
  public:
    cvComponent() {}
    virtual ~cvComponent() {}

    /// <summary>
    /// 组件类型
    /// </summary>
    std::string type;

    XUEXUE_JSON_OBJECT_M1(type)
    //实现XUEXUE_JSON_SUPER
    virtual void* instance() const;
};

/// <summary>
/// Line组件
/// </summary>
class cvLine : public cvComponent
{
  public:
    cvLine() {}
    virtual ~cvLine() {}

    /// <summary> 颜色 </summary>
    xuexue::json::unity3d::Color32 color;

    /// <summary> 点0. </summary>
    Eigen::Vector3d pos0;

    /// <summary> 点1. </summary>
    Eigen::Vector3d pos1;

    XUEXUE_JSON_OBJECT_M4(type, color, pos0, pos1)
};

class cvObject : XUEXUE_JSON_OBJECT
{
  public:
    cvObject() {}
    virtual ~cvObject() {}

    /// <summary> 物体名字. </summary>
    std::string name;

    /// <summary> 所有包含的组件. </summary>
    std::vector<std::shared_ptr<cvComponent>> components;

    /// <summary> 子节点. </summary>
    std::vector<cvObject> children;

    XUEXUE_JSON_OBJECT_M3(name, components, children)
  private:
};

void* cvComponent::instance() const
{
    if (type == "cvLine") {
        return new cvLine();
    }

    return nullptr;
}

TEST(Eigen, cvObject)
{
    std::shared_ptr<cvLine> line = std::make_shared<cvLine>();
    line->type = "cvLine";
    line->color = {21, 123, 32};
    line->pos0 = {123, 321, 4321};
    line->pos1 = {32, 12, 22};

    string text = JsonMapper::toJson(line);

    std::shared_ptr<cvComponent> com = line;
    string text2 = JsonMapper::toJson(com);

    //cvComponent* pcom = &line;
    //string text3 = JsonMapper::toJson(*pcom);

    cvObject obj;
    obj.components.push_back(line);

    text = JsonMapper::toJson(obj);
    cvObject o2 = JsonMapper::toObject<cvObject>(text);
    ASSERT_EQ(o2.components.size(), obj.components.size());

    cvLine* line2 = static_cast<cvLine*>((o2.components[0]).get());
    ASSERT_TRUE(line->color == line2->color);
    ASSERT_TRUE(line->pos0 == line2->pos0);
    ASSERT_TRUE(line->pos1 == line2->pos1);
    ASSERT_TRUE(line->type == line2->type);
}