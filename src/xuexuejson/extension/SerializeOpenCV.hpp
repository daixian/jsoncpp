#pragma once
#include "../SerializeBase.hpp"

#include <opencv2/opencv.hpp>

namespace xuexue {
namespace json {

// 使用rapidjson扩展的一些固定序列化/反序列化方法.
namespace Serialize {

//------------------------------ cv::Vec3 ------------------------------
template <typename T>
static inline Value&& toValue(const cv::Vec<T, 3>& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember("x", obj(0), allocator);
    jv.AddMember("y", obj(1), allocator);
    jv.AddMember("z", obj(2), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, cv::Vec<T, 3>& obj)
{
    using namespace rapidjson;
    getObj(value["x"], obj(0));
    getObj(value["y"], obj(1));
    getObj(value["z"], obj(2));
}

template <typename T>
static inline ValueW&& toValue(const cv::Vec<T, 3>& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember(L"x", obj(0), allocator);
    jv.AddMember(L"y", obj(1), allocator);
    jv.AddMember(L"z", obj(2), allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, cv::Vec<T, 3>& obj)
{
    using namespace rapidjson;
    getObj(value[L"x"], obj(0));
    getObj(value[L"y"], obj(1));
    getObj(value[L"z"], obj(2));
}

//------------------------------ cv::size ------------------------------
template <typename T>
static inline Value&& toValue(const cv::Size_<T>& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember("width", obj.width, allocator);
    jv.AddMember("height", obj.height, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, cv::Size_<T>& obj)
{
    using namespace rapidjson;
    getObj(value["width"], obj.width);
    getObj(value["height"], obj.height);
}

template <typename T>
static inline ValueW&& toValue(const cv::Size_<T>& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember(L"width", obj.width, allocator);
    jv.AddMember(L"height", obj.height, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, cv::Size_<T>& obj)
{
    using namespace rapidjson;
    getObj(value[L"width"], obj.width);
    getObj(value[L"height"], obj.height);
}

//------------------------------ cv::point ------------------------------
template <typename T>
static inline Value&& toValue(const cv::Point_<T>& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember("x", obj.x, allocator);
    jv.AddMember("y", obj.y, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, cv::Point_<T>& obj)
{
    using namespace rapidjson;
    getObj(value["x"], obj.x);
    getObj(value["y"], obj.y);
}

template <typename T>
static inline ValueW&& toValue(const cv::Point_<T>& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember(L"x", obj.x, allocator);
    jv.AddMember(L"y", obj.y, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, cv::Point_<T>& obj)
{
    using namespace rapidjson;
    getObj(value[L"x"], obj.x);
    getObj(value[L"y"], obj.y);
}

//------------------------------ cv::point3 ------------------------------
template <typename T>
static inline Value&& toValue(const cv::Point3_<T>& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember("x", obj.x, allocator);
    jv.AddMember("y", obj.y, allocator);
    jv.AddMember("z", obj.z, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, cv::Point3_<T>& obj)
{
    using namespace rapidjson;
    getObj(value["x"], obj.x);
    getObj(value["y"], obj.y);
    getObj(value["z"], obj.z);
}

template <typename T>
static inline ValueW&& toValue(const cv::Point3_<T>& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember(L"x", obj.x, allocator);
    jv.AddMember(L"y", obj.y, allocator);
    jv.AddMember(L"z", obj.z, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, cv::Point3_<T>& obj)
{
    using namespace rapidjson;
    getObj(value[L"x"], obj.x);
    getObj(value[L"y"], obj.y);
    getObj(value[L"z"], obj.z);
}

//------------------------------ cv::Rect ------------------------------
template <typename T>
static inline Value&& toValue(const cv::Rect_<T>& obj, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember("x", obj.x, allocator);
    jv.AddMember("y", obj.y, allocator);
    jv.AddMember("width", obj.width, allocator);
    jv.AddMember("height", obj.height, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const Value& value, cv::Rect_<T>& obj)
{
    using namespace rapidjson;
    getObj(value["x"], obj.x);
    getObj(value["y"], obj.y);
    getObj(value["width"], obj.width);
    getObj(value["height"], obj.height);
}

template <typename T>
static inline ValueW&& toValue(const cv::Rect_<T>& obj, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();
    jv.AddMember(L"x", obj.x, allocator);
    jv.AddMember(L"y", obj.y, allocator);
    jv.AddMember(L"width", obj.width, allocator);
    jv.AddMember(L"height", obj.height, allocator);
    return std::move(jv);
}

template <typename T>
static inline void getObj(const ValueW& value, cv::Rect_<T>& obj)
{
    using namespace rapidjson;
    getObj(value[L"x"], obj.x);
    getObj(value[L"y"], obj.y);
    getObj(value[L"width"], obj.width);
    getObj(value[L"height"], obj.height);
}

//------------------------------ cv::Mat ------------------------------
static inline Value&& toValue(const cv::Mat& m, Value&& jv,
                              rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();

    int channels = m.channels();
    int cols = m.cols;
    int rows = m.rows;

    jv.AddMember("type", m.type(), allocator);
    jv.AddMember("channels", m.channels(), allocator);
    jv.AddMember("cols", cols, allocator);
    jv.AddMember("rows", rows, allocator);

    Value data(rapidjson::kArrayType);

    if (m.type() == CV_32F || m.type() == CV_32FC(1) ||
        m.type() == CV_32FC(2) || m.type() == CV_32FC(3) ||
        m.type() == CV_32FC(4)) {
        const float* p = m.ptr<float>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(p[i], allocator);
    }
    else if (m.type() == CV_64F || m.type() == CV_64FC(1) ||
             m.type() == CV_64FC(2) || m.type() == CV_64FC(3) ||
             m.type() == CV_64FC(4)) {
        const double* p = m.ptr<double>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(p[i], allocator);
    }
    else if (m.type() == CV_8U || m.type() == CV_8UC(1) ||
             m.type() == CV_8UC(2) || m.type() == CV_8UC(3) ||
             m.type() == CV_8UC(4)) {
        const uchar* p = m.ptr<uchar>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<uint>(p[i]), allocator);
    }
    else if (m.type() == CV_8S || m.type() == CV_8SC(1) ||
             m.type() == CV_8SC(2) || m.type() == CV_8SC(3) ||
             m.type() == CV_8SC(4)) {
        const char* p = m.ptr<char>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<int>(p[i]), allocator);
    }
    else if (m.type() == CV_16U || m.type() == CV_16UC(1) ||
             m.type() == CV_16UC(2) || m.type() == CV_16UC(3) ||
             m.type() == CV_16UC(4)) {
        const uint16_t* p = m.ptr<uint16_t>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<uint>(p[i]), allocator);
    }
    else if (m.type() == CV_16S || m.type() == CV_16SC(1) ||
             m.type() == CV_16SC(2) || m.type() == CV_16SC(3) ||
             m.type() == CV_16SC(4)) {
        const int16_t* p = m.ptr<int16_t>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<int>(p[i]), allocator);
    }
    jv.AddMember("data", data, allocator);
    return std::move(jv);
}

static inline void getObj(const Value& value, cv::Mat& m)
{
    int type = value["type"].GetInt(); //好像构造它只需要这个type就行了
    int channels = value["channels"].GetInt();
    int cols = value["cols"].GetInt();
    int rows = value["rows"].GetInt();
    const auto& data = value["data"];

    if (type == CV_32F || type == CV_32FC(1) ||
        type == CV_32FC(2) || type == CV_32FC(3) ||
        type == CV_32FC(4)) {
        m = cv::Mat(rows, cols, type);
        float* _r = m.ptr<float>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetFloat();
    }
    else if (type == CV_64F || type == CV_64FC(1) ||
             type == CV_64FC(2) || type == CV_64FC(3) ||
             type == CV_64FC(4)) {
        m = cv::Mat(rows, cols, type);
        double* _r = m.ptr<double>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetDouble();
    }
    else if (type == CV_8U || type == CV_8UC(1) ||
             type == CV_8UC(2) || type == CV_8UC(3) ||
             type == CV_8UC(4)) {
        m = cv::Mat(rows, cols, type);
        uchar* _r = m.ptr<uchar>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetUint();
    }
    else if (type == CV_8S || type == CV_8SC(1) ||
             type == CV_8SC(2) || type == CV_8SC(3) ||
             type == CV_8SC(4)) {
        m = cv::Mat(rows, cols, type);
        char* _r = m.ptr<char>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetInt();
    }
    else if (type == CV_16U || type == CV_16UC(1) ||
             type == CV_16UC(2) || type == CV_16UC(3) ||
             type == CV_16UC(4)) {
        m = cv::Mat(rows, cols, type);
        uint16_t* _r = m.ptr<uint16_t>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetUint();
    }
    else if (type == CV_16S || type == CV_16SC(1) ||
             type == CV_16SC(2) || type == CV_16SC(3) ||
             type == CV_16SC(4)) {
        m = cv::Mat(rows, cols, type);
        int16_t* _r = m.ptr<int16_t>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetInt();
    }
}

static inline ValueW&& toValue(const cv::Mat& m, ValueW&& jv,
                               rapidjson::MemoryPoolAllocator<>& allocator)
{
    using namespace rapidjson;
    jv.SetObject();

    int channels = m.channels();
    int cols = m.cols;
    int rows = m.rows;

    jv.AddMember(L"type", m.type(), allocator);
    jv.AddMember(L"channels", m.channels(), allocator);
    jv.AddMember(L"cols", cols, allocator);
    jv.AddMember(L"rows", rows, allocator);

    ValueW data(rapidjson::kArrayType);

    if (m.type() == CV_32F || m.type() == CV_32FC(1) ||
        m.type() == CV_32FC(2) || m.type() == CV_32FC(3) ||
        m.type() == CV_32FC(4)) {
        const float* p = m.ptr<float>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(p[i], allocator);
    }
    else if (m.type() == CV_64F || m.type() == CV_64FC(1) ||
             m.type() == CV_64FC(2) || m.type() == CV_64FC(3) ||
             m.type() == CV_64FC(4)) {
        const double* p = m.ptr<double>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(p[i], allocator);
    }
    else if (m.type() == CV_8U || m.type() == CV_8UC(1) ||
             m.type() == CV_8UC(2) || m.type() == CV_8UC(3) ||
             m.type() == CV_8UC(4)) {
        const uchar* p = m.ptr<uchar>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<uint>(p[i]), allocator);
    }
    else if (m.type() == CV_8S || m.type() == CV_8SC(1) ||
             m.type() == CV_8SC(2) || m.type() == CV_8SC(3) ||
             m.type() == CV_8SC(4)) {
        const char* p = m.ptr<char>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<int>(p[i]), allocator);
    }
    else if (m.type() == CV_16U || m.type() == CV_16UC(1) ||
             m.type() == CV_16UC(2) || m.type() == CV_16UC(3) ||
             m.type() == CV_16UC(4)) {
        const uint16_t* p = m.ptr<uint16_t>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<uint>(p[i]), allocator);
    }
    else if (m.type() == CV_16S || m.type() == CV_16SC(1) ||
             m.type() == CV_16SC(2) || m.type() == CV_16SC(3) ||
             m.type() == CV_16SC(4)) {
        const int16_t* p = m.ptr<int16_t>();
        for (size_t i = 0; i < cols * rows * channels; i++)
            data.PushBack(static_cast<int>(p[i]), allocator);
    }
    jv.AddMember(L"data", data, allocator);
    return std::move(jv);
}

static inline void getObj(const ValueW& value, cv::Mat& m)
{
    int type = value[L"type"].GetInt(); //好像构造它只需要这个type就行了
    int channels = value[L"channels"].GetInt();
    int cols = value[L"cols"].GetInt();
    int rows = value[L"rows"].GetInt();
    const auto& data = value[L"data"];

    if (type == CV_32F || type == CV_32FC(1) ||
        type == CV_32FC(2) || type == CV_32FC(3) ||
        type == CV_32FC(4)) {
        m = cv::Mat(rows, cols, type);
        float* _r = m.ptr<float>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetFloat();
    }
    else if (type == CV_64F || type == CV_64FC(1) ||
             type == CV_64FC(2) || type == CV_64FC(3) ||
             type == CV_64FC(4)) {
        m = cv::Mat(rows, cols, type);
        double* _r = m.ptr<double>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetDouble();
    }
    else if (type == CV_8U || type == CV_8UC(1) ||
             type == CV_8UC(2) || type == CV_8UC(3) ||
             type == CV_8UC(4)) {
        m = cv::Mat(rows, cols, type);
        uchar* _r = m.ptr<uchar>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetUint();
    }
    else if (type == CV_8S || type == CV_8SC(1) ||
             type == CV_8SC(2) || type == CV_8SC(3) ||
             type == CV_8SC(4)) {
        m = cv::Mat(rows, cols, type);
        char* _r = m.ptr<char>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetInt();
    }
    else if (type == CV_16U || type == CV_16UC(1) ||
             type == CV_16UC(2) || type == CV_16UC(3) ||
             type == CV_16UC(4)) {
        m = cv::Mat(rows, cols, type);
        uint16_t* _r = m.ptr<uint16_t>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetUint();
    }
    else if (type == CV_16S || type == CV_16SC(1) ||
             type == CV_16SC(2) || type == CV_16SC(3) ||
             type == CV_16SC(4)) {
        m = cv::Mat(rows, cols, type);
        int16_t* _r = m.ptr<int16_t>();
        for (rapidjson::SizeType i = 0; i < data.Size(); i++) // 使用 SizeType 而不是 size_t
            _r[i] = data[i].GetInt();
    }
}

} // namespace Serialize

} // namespace json
} // namespace xuexue
