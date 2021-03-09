#pragma once

#include "../SerializeBase.hpp"

#include <Eigen/Geometry>
#include <unsupported/Eigen/EulerAngles>

namespace xuexue {
namespace json {

//Eigen库相对支持方法
namespace Serialize {

//------------------------------ Vector2 ------------------------------
template <typename T>
static inline Value&& toValue(const Eigen::Matrix<T, 2, 1>& v, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember("x", v.x(), allocator);
    jv.AddMember("y", v.y(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, Eigen::Matrix<T, 2, 1>& obj)
{
    getObj(value["x"], obj.x());
    getObj(value["y"], obj.y());
}

template <typename T>
static inline ValueW&& toValue(const Eigen::Matrix<T, 2, 1>& v, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember(L"x", v.x(), allocator);
    jv.AddMember(L"y", v.y(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, Eigen::Matrix<T, 2, 1>& obj)
{
    getObj(value[L"x"], obj.x());
    getObj(value[L"y"], obj.y());
}
//------------------------------ Vector3 ------------------------------
template <typename T>
static inline Value&& toValue(const Eigen::Matrix<T, 3, 1>& v, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember("x", v.x(), allocator);
    jv.AddMember("y", v.y(), allocator);
    jv.AddMember("z", v.z(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, Eigen::Matrix<T, 3, 1>& obj)
{
    getObj(value["x"], obj.x());
    getObj(value["y"], obj.y());
    getObj(value["z"], obj.z());
}

template <typename T>
static inline ValueW&& toValue(const Eigen::Matrix<T, 3, 1>& v, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember(L"x", v.x(), allocator);
    jv.AddMember(L"y", v.y(), allocator);
    jv.AddMember(L"z", v.z(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, Eigen::Matrix<T, 3, 1>& obj)
{
    getObj(value[L"x"], obj.x());
    getObj(value[L"y"], obj.y());
    getObj(value[L"z"], obj.z());
}
//------------------------------ Vector4 ------------------------------
template <typename T>
static inline Value&& toValue(const Eigen::Matrix<T, 4, 1>& v, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember("x", v.x(), allocator);
    jv.AddMember("y", v.y(), allocator);
    jv.AddMember("z", v.z(), allocator);
    jv.AddMember("w", v.w(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, Eigen::Matrix<T, 4, 1>& obj)
{
    getObj(value["x"], obj.x());
    getObj(value["y"], obj.y());
    getObj(value["z"], obj.z());
    getObj(value["w"], obj.w());
}

template <typename T>
static inline ValueW&& toValue(const Eigen::Matrix<T, 4, 1>& v, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember(L"x", v.x(), allocator);
    jv.AddMember(L"y", v.y(), allocator);
    jv.AddMember(L"z", v.z(), allocator);
    jv.AddMember(L"w", v.w(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, Eigen::Matrix<T, 4, 1>& obj)
{
    getObj(value[L"x"], obj.x());
    getObj(value[L"y"], obj.y());
    getObj(value[L"z"], obj.z());
    getObj(value[L"w"], obj.z());
}
//------------------------------ Quaternion ------------------------------
template <typename T>
static inline Value&& toValue(const Eigen::Quaternion<T>& q4, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember("x", q4.x(), allocator);
    jv.AddMember("y", q4.y(), allocator);
    jv.AddMember("z", q4.z(), allocator);
    jv.AddMember("w", q4.w(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, Eigen::Quaternion<T>& obj)
{
    getObj(value["x"], obj.x());
    getObj(value["y"], obj.y());
    getObj(value["z"], obj.z());
    getObj(value["w"], obj.w());
}

template <typename T>
static inline ValueW&& toValue(const Eigen::Quaternion<T>& q4, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    jv.SetObject();
    jv.AddMember(L"x", q4.x(), allocator);
    jv.AddMember(L"y", q4.y(), allocator);
    jv.AddMember(L"z", q4.z(), allocator);
    jv.AddMember(L"w", q4.w(), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, Eigen::Quaternion<T>& obj)
{
    getObj(value[L"x"], obj.x());
    getObj(value[L"y"], obj.y());
    getObj(value[L"z"], obj.z());
    getObj(value[L"w"], obj.w());
}

} // namespace Serialize

} // namespace json
} // namespace xuexue
