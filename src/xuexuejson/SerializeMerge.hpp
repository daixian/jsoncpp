#pragma once
#include "SerializeBase.hpp"

/**************************  这里补充所有的特殊扩展序列化方法 **************************/
//默认定义支持这些大库里的类型，如果不需要则注销掉这两行
#ifdef OPENCV_CORE_HPP
#    define XUEXUE_JSON_SUPPORT_OPENCV
#endif
#ifdef EIGEN_GEOMETRY_MODULE_H
#    define XUEXUE_JSON_SUPPORT_EIGEN
#endif

#ifdef XUEXUE_JSON_SUPPORT_EIGEN
#    include "extension/SerializeEigen.hpp"
#endif

#ifdef XUEXUE_JSON_SUPPORT_OPENCV
#    include "extension/SerializeOpenCV.hpp"
#endif

//这个不需要依赖库所以可以直接打开
#include "extension/SerializeUnity3D.hpp"

//在此处加入你自己的扩展代码文件....

/**********************************************************************************/

namespace xuexue {
namespace json {

//合并的支持的可序列化对象和一些容器等等
namespace Serialize {

// =================================  JsonSerializable对象T接口模板 =====================================
//支持智能指针shared_ptr类型
template <class T>
static inline Value&& toValue(const std::shared_ptr<T>& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (obj == nullptr || !std::is_base_of<JsonSerializable, T>::value) {
        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializable* ptr = (JsonSerializable*)(obj.get());
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
static inline void getObj(const Value& value, std::shared_ptr<T>& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializable, T>::value) {
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

//智能指针类型shared_ptr支持
template <class T>
static inline ValueW&& toValue(const std::shared_ptr<T>& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (obj == nullptr || !std::is_base_of<JsonSerializableW, T>::value) {
        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializableW* ptr = (JsonSerializableW*)(obj.get());
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
static inline void getObj(const ValueW& value, std::shared_ptr<T>& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {
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

//支持智能指针unique_ptr类型
template <class T>
static inline Value&& toValue(const std::unique_ptr<T>& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (obj == nullptr || !std::is_base_of<JsonSerializable, T>::value) {
        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializable* ptr = (JsonSerializable*)(obj.get());
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
static inline void getObj(const Value& value, std::unique_ptr<T>& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializable, T>::value) {
        return;
    }
    if (obj == nullptr)
        obj = std::unique_ptr<T>(new T());
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
        obj = std::unique_ptr<T>((T*)newObj);
        ptr = (JsonSerializable*)(obj.get());
        ptr->getObj(value); //调用这个子类的方法
    }
}

//智能指针类型unique_ptr支持
template <class T>
static inline ValueW&& toValue(const std::unique_ptr<T>& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (obj == nullptr || !std::is_base_of<JsonSerializableW, T>::value) {
        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializableW* ptr = (JsonSerializableW*)(obj.get());
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
static inline void getObj(const ValueW& value, std::unique_ptr<T>& obj)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {
        return;
    }
    if (obj == nullptr)
        obj = std::unique_ptr<T>(new T());
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
        obj = std::unique_ptr<T>((T*)newObj);
        ptr = (JsonSerializableW*)(obj.get());
        ptr->getObj(value); //调用这个子类的方法
    }
}

//=============================  自定义接口模板里面必须要含有这两个函数 =============================
template <class T>
static inline Value&& toValue(const T& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口
    if (!std::is_base_of<JsonSerializable, T>::value) {

        //如果是枚举int,判断放进来算了
        if (std::is_enum<T>::value) {
            const int* ptr = (const int*)&obj;
            jv.SetInt(*ptr);
            return std::move(jv);
        }

        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializable* ptr = (JsonSerializable*)&obj;
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
static inline void getObj(const Value& value, T& obj)
{
    //如果是枚举int
    if (std::is_enum<T>::value &&
        value.IsInt()) {
        int* ptr = (int*)&obj;
        *ptr = value.GetInt();
        return;
    }

    if (!value.IsObject()) //它应该是一个Object?
        return;

    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializable, T>::value) {
        return;
    }
    JsonSerializable* ptr = (JsonSerializable*)&obj;
    ptr->getObj(value);
}

//自定义接口模板里面必须要含有这两个函数
template <class T>
static inline ValueW&& toValue(const T& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {

        //如果是枚举int,判断放进来算了
        if (std::is_enum<T>::value) {
            const int* ptr = (const int*)&obj;
            jv.SetInt(*ptr);
            return std::move(jv);
        }

        jv.SetNull();
        return std::move(jv);
    }
    JsonSerializableW* ptr = (JsonSerializableW*)&obj;
    return ptr->toValue(std::move(jv), allocator);
}

template <class T>
static inline void getObj(const ValueW& value, T& obj)
{
    //如果是枚举int
    if (std::is_enum<T>::value &&
        value.IsInt()) {
        int* ptr = (int*)&obj;
        *ptr = value.GetInt();
        return;
    }

    if (!value.IsObject()) //它应该是一个Object?
        return;

    //检察类型,如果不是JsonSerializable接口那么就返回
    if (!std::is_base_of<JsonSerializableW, T>::value) {
        return;
    }
    JsonSerializableW* ptr = (JsonSerializableW*)&obj;
    ptr->getObj(value);
}

// ========================================    容器模板    ==========================================

// std::vector的模板 (kArrayType)
template <typename T>
static inline Value&& toValue(const std::vector<T>& obj, Value&& value,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (rapidjson::SizeType i = 0; i < obj.size(); i++) {
        value.PushBack(toValue(obj[i], Value(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T>
static inline void getObj(const Value& value, std::vector<T>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    obj.clear();
    for (rapidjson::SizeType i = 0; i < value.Size(); i++) {
        T o;
        getObj(value[i], o);
        obj.push_back(o);
    }
}

template <typename T>
static inline ValueW&& toValue(const std::vector<T>& obj, ValueW&& value,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (rapidjson::SizeType i = 0; i < obj.size(); i++) {
        value.PushBack(toValue(obj[i], ValueW(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T>
static inline void getObj(const ValueW& value, std::vector<T>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    obj.clear();
    for (rapidjson::SizeType i = 0; i < value.Size(); i++) {
        T o;
        getObj(value[i], o);
        obj.push_back(o);
    }
} // std::deque的模板 (kArrayType)
template <typename T>
static inline Value&& toValue(const std::deque<T>& obj, Value&& value,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (rapidjson::SizeType i = 0; i < obj.size(); i++) {
        value.PushBack(toValue(obj[i], Value(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T>
static inline void getObj(const Value& value, std::deque<T>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    obj.clear();
    for (rapidjson::SizeType i = 0; i < value.Size(); i++) {
        T o;
        getObj(value[i], o);
        obj.push_back(o);
    }
}

template <typename T>
static inline ValueW&& toValue(const std::deque<T>& obj, ValueW&& value,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (rapidjson::SizeType i = 0; i < obj.size(); i++) {
        value.PushBack(toValue(obj[i], ValueW(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T>
static inline void getObj(const ValueW& value, std::deque<T>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    obj.clear();
    for (rapidjson::SizeType i = 0; i < value.Size(); i++) {
        T o;
        getObj(value[i], o);
        obj.push_back(o);
    }
}

// std::list的模板 (kArrayType)
template <typename T>
static inline Value&& toValue(const std::list<T>& obj, Value&& value,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (auto& iobj : obj) {
        value.PushBack(toValue(iobj, Value(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T>
static inline void getObj(const Value& value, std::list<T>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    obj.clear();
    for (rapidjson::SizeType i = 0; i < value.Size(); i++) {
        T o;
        getObj(value[i], o);
        obj.push_back(o);
    }
}

template <typename T>
static inline ValueW&& toValue(const std::list<T>& obj, ValueW&& value,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (auto& iobj : obj) {
        value.PushBack(toValue(iobj, ValueW(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T>
static inline void getObj(const ValueW& value, std::list<T>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    obj.clear();
    for (size_t i = 0; i < value.Size(); i++) {
        T o;
        getObj(value[i], o);
        obj.push_back(o);
    }
}

// std::array的模板 (kArrayType)
template <typename T, size_t _Size>
static inline Value&& toValue(const std::array<T, _Size>& obj, Value&& value,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (size_t i = 0; i < obj.size(); i++) {
        value.PushBack(toValue(obj[i], Value(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T, size_t _Size>
static inline void getObj(const Value& value, std::array<T, _Size>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    for (rapidjson::SizeType i = 0; i < value.Size(); i++) {
        getObj(value[i], obj[i]);
    }
}

template <typename T, size_t _Size>
static inline ValueW&& toValue(const std::array<T, _Size>& obj, ValueW&& value,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetArray();
    for (rapidjson::SizeType i = 0; i < obj.size(); i++) {
        value.PushBack(toValue(obj[i], ValueW(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T, size_t _Size>
static inline void getObj(const ValueW& value, std::array<T, _Size>& obj)
{
    if (!value.IsArray()) //它应该是一个array
        return;
    for (rapidjson::SizeType i = 0; i < value.Size(); i++) {
        getObj(value[i], obj[i]);
    }
}

// std::map的模板 (kObjectType)
template <typename T, typename K>
static inline Value&& toValue(const std::map<T, K>& map, Value&& value,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetObject();
    for (auto kvp : map) {
        value.AddMember(toValue(kvp.first, Value(), allocator),
                        toValue(kvp.second, Value(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T, typename K>
static inline void getObj(const Value& value, std::map<T, K>& obj)
{
    if (!value.IsObject()) //它应该是一个Object
        return;
    obj.clear();
    for (Value::ConstMemberIterator itr = value.MemberBegin(); itr != value.MemberEnd(); ++itr) {
        T k;
        K v;
        getObj(itr->name, k);
        getObj(itr->value, v);
        obj[k] = v;
    }
}

template <typename T, typename K>
static inline ValueW&& toValue(const std::map<T, K>& map, ValueW&& value,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    value.SetObject();
    for (auto kvp : map) {
        value.AddMember(toValue(kvp.first, ValueW(), allocator),
                        toValue(kvp.second, ValueW(), allocator), allocator);
    }
    return std::move(value);
}

template <typename T, typename K>
static inline void getObj(const ValueW& value, std::map<T, K>& obj)
{
    if (!value.IsObject()) //它应该是一个Object
        return;
    obj.clear();
    for (ValueW::ConstMemberIterator itr = value.MemberBegin(); itr != value.MemberEnd(); ++itr) {
        T k;
        K v;
        getObj(itr->name, k);
        getObj(itr->value, v);
        obj[k] = v;
    }
}
} // namespace Serialize

} // namespace json
} // namespace xuexue
