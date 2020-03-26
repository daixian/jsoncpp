
//假如现在有一个第三方库
class OtherLibType
{
  public:
    float x;
    float y;
    float z;
};

#define XUEXUE_JSON_SUPPORT_OPENCV
#define XUEXUE_JSON_SUPPORT_EIGEN
#define XUEXUE_JSON_USER_SERIALIZE
#include "xuexuejson/JsonMapper.hpp"

namespace xuexue {
namespace json {

// =================================  JsonSerializable接口模板 =====================================
//支持智能指针类型
template <class T>
Value&& Serialize::toValue(const std::shared_ptr<T>& obj, Value&& jv, rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializable, T>::value) {

        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)obj.get();
            jv.SetObject();
            jv.AddMember("x", ptr->x, allocator);
            jv.AddMember("y", ptr->y, allocator);
            jv.AddMember("z", ptr->z, allocator);
            return std::move(jv);
        }

        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializable* ptr = (JsonSerializable*)(obj.get());
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
ValueW&& Serialize::toValue(const std::shared_ptr<T>& obj, ValueW&& jv, rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {

        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)obj.get();
            jv.SetObject();
            jv.AddMember("x", ptr->x, allocator);
            jv.AddMember("y", ptr->y, allocator);
            jv.AddMember("z", ptr->z, allocator);
            return std::move(jv);
        }

        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializableW* ptr = (JsonSerializableW*)(obj.get());
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
void Serialize::getObj(const Value& value, std::shared_ptr<T>& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializable, T>::value) {

        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)obj.get();
            Serialize::getObj(value["x"], ptr->x);
            Serialize::getObj(value["y"], ptr->y);
            Serialize::getObj(value["z"], ptr->z);
            return;
        }

        return;
    }
    if (obj == nullptr)
        obj = std::make_shared<T>();
    JsonSerializable* ptr = (JsonSerializable*)(obj.get());
    ptr->getObj(value);

    //如果这个类不是一个基类
    if (!std::is_base_of<JsonSerializeSuper, T>::value) {
        return;
    }
    //如果是基类那么就再次提取数据
    JsonSerializeSuper* superPtr = (JsonSerializeSuper*)(obj.get());
    void* newObj = superPtr->instance();
    if (newObj != nullptr) {
        obj = std::shared_ptr<T>((T*)newObj);
        ptr = (JsonSerializable*)(obj.get());
        ptr->getObj(value); //调用这个子类的方法
    }
}

template <class T>
void Serialize::getObj(const ValueW& value, std::shared_ptr<T>& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {

        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)obj.get();
            Serialize::getObj(value["x"], ptr->x);
            Serialize::getObj(value["y"], ptr->y);
            Serialize::getObj(value["z"], ptr->z);
            return;
        }

        return;
    }
    if (obj == nullptr)
        obj = std::make_shared<T>();
    JsonSerializableW* ptr = (JsonSerializableW*)(obj.get());
    ptr->getObj(value);

    //如果这个类不是一个基类
    if (!std::is_base_of<JsonSerializeSuper, T>::value) {
        return;
    }
    //如果是基类那么就再次提取数据
    JsonSerializeSuper* superPtr = (JsonSerializeSuper*)(obj.get());
    void* newObj = superPtr->instance();
    if (newObj != nullptr) {
        obj = std::shared_ptr<T>((T*)newObj);
        ptr = (JsonSerializableW*)(obj.get());
        ptr->getObj(value); //调用这个子类的方法
    }
}

//自定义接口模板里面必须要含有这两个函数
template <class T>
Value&& Serialize::toValue(const T& obj, Value&& jv, rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializable, T>::value) {

        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)&obj;
            jv.SetObject();
            jv.AddMember("x", ptr->x, allocator);
            jv.AddMember("y", ptr->y, allocator);
            jv.AddMember("z", ptr->z, allocator);
            return std::move(jv);
        }

        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializable* ptr = (JsonSerializable*)&obj;
    return ptr->toValue(std::move(jv), allocator);
}

//自定义接口模板里面必须要含有这两个函数
template <class T>
ValueW&& Serialize::toValue(const T& obj, ValueW&& jv, rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {

        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)&obj;
            jv.SetObject();
            jv.AddMember(L"x", ptr->x, allocator);
            jv.AddMember(L"y", ptr->y, allocator);
            jv.AddMember(L"z", ptr->z, allocator);
            return std::move(jv);
        }

        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializableW* ptr = (JsonSerializableW*)&obj;
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
void getObj(const Value& value, T& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializable, T>::value) {
        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)&obj;
            Serialize::getObj(value["x"], ptr->x);
            Serialize::getObj(value["y"], ptr->y);
            Serialize::getObj(value["z"], ptr->z);
            return;
        }

        return;
    }
    JsonSerializable* ptr = (JsonSerializable*)&obj;
    ptr->getObj(value);
}
template <class T>
void getObj(const ValueW& value, T& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {

        if (std::is_base_of<OtherLibType, T>::value) {
            OtherLibType* ptr = (OtherLibType*)&obj;
            Serialize::getObj(value[L"x"], ptr->x);
            Serialize::getObj(value[L"y"], ptr->y);
            Serialize::getObj(value[L"z"], ptr->z);
            return;
        }

        return;
    }
    JsonSerializableW* ptr = (JsonSerializableW*)&obj;
    ptr->getObj(value);
}

} // namespace json
} // namespace xuexue

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

#include "gtest/gtest.h"

TEST(UserSerialize, OtherLibType)
{
    OtherLibType o;
    o.x = 123.231;
    o.y = 32.43;
    o.z = 143.312231;

    string text = JsonMapper::toJson(o);
    OtherLibType o2 = JsonMapper::toObject<OtherLibType>(text);
    ASSERT_TRUE(o.x == o2.x);
    ASSERT_TRUE(o.y == o2.y);
    ASSERT_TRUE(o.z == o2.z);
}