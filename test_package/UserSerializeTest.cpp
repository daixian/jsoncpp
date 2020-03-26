
//����������һ����������
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

// =================================  JsonSerializable�ӿ�ģ�� =====================================
//֧������ָ������
template <class T>
Value&& Serialize::toValue(const std::shared_ptr<T>& obj, Value&& jv, rapidjson::MemoryPoolAllocator<>& allocator)
{
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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

    //�������಻��һ������
    if (!std::is_base_of<JsonSerializeSuper, T>::value) {
        return;
    }
    //����ǻ�����ô���ٴ���ȡ����
    JsonSerializeSuper* superPtr = (JsonSerializeSuper*)(obj.get());
    void* newObj = superPtr->instance();
    if (newObj != nullptr) {
        obj = std::shared_ptr<T>((T*)newObj);
        ptr = (JsonSerializable*)(obj.get());
        ptr->getObj(value); //�����������ķ���
    }
}

template <class T>
void Serialize::getObj(const ValueW& value, std::shared_ptr<T>& obj)
{
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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

    //�������಻��һ������
    if (!std::is_base_of<JsonSerializeSuper, T>::value) {
        return;
    }
    //����ǻ�����ô���ٴ���ȡ����
    JsonSerializeSuper* superPtr = (JsonSerializeSuper*)(obj.get());
    void* newObj = superPtr->instance();
    if (newObj != nullptr) {
        obj = std::shared_ptr<T>((T*)newObj);
        ptr = (JsonSerializableW*)(obj.get());
        ptr->getObj(value); //�����������ķ���
    }
}

//�Զ���ӿ�ģ���������Ҫ��������������
template <class T>
Value&& Serialize::toValue(const T& obj, Value&& jv, rapidjson::MemoryPoolAllocator<>& allocator)
{
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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

//�Զ���ӿ�ģ���������Ҫ��������������
template <class T>
ValueW&& Serialize::toValue(const T& obj, ValueW&& jv, rapidjson::MemoryPoolAllocator<>& allocator)
{
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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
    //�������,�������JsonSerializable�ӿ���ô�ͷ���
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