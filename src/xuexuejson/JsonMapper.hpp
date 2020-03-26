#pragma once

#include "Serialize.hpp"

//一些方便实现接口的宏
#include "JsonSerializableImpl.h"

namespace xuexue {
namespace json {
///-------------------------------------------------------------------------------------------------
/// <summary> object和josn的相互转换，这是包含主要的使用方法. </summary>
///
/// <remarks>
/// 将这个类放在最下面，不然GCC支持不了. Dx, 2020/3/19.
/// </remarks>
///-------------------------------------------------------------------------------------------------
class JsonMapper
{
  public:
    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 转换整个obj到一个Document.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
    /// </summary>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="obj"> 要转换的obj对象. </param>
    ///
    /// <returns> Obj as a Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline Document toDocument(const T& obj)
    {
        using namespace rapidjson;

        Document doc;
        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);

        return doc;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 转换整个obj到一个Document.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
    /// </summary>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="obj"> 要转换的obj对象. </param>
    /// <param name="doc"> [out] The document. </param>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline void toDocument(const T& obj, Document& doc)
    {
        using namespace rapidjson;

        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 转换整个obj到一个DocumentW.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
    /// </summary>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="obj"> 要转换的obj对象. </param>
    ///
    /// <returns> Obj as a Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline DocumentW toDocumentW(const T& obj)
    {
        using namespace rapidjson;

        DocumentW doc;
        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);

        return doc;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 转换整个obj到一个DocumentW.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
    /// </summary>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="obj"> 要转换的obj对象. </param>
    /// <param name="doc"> [out] The document. </param>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline void toDocumentW(const T& obj, DocumentW& doc)
    {
        using namespace rapidjson;

        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 转换整个obj到string. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="obj">      要转换的obj对象. </param>
    /// <param name="isPretty"> (Optional) 是否启用缩进格式打印. </param>
    ///
    /// <returns> Doc as a std::wstring. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline std::string toJson(const T& obj, bool isPretty = false)
    {
        using namespace rapidjson;

        Document doc;
        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);

        StringBuffer sb;
        if (isPretty) {
            PrettyWriter<StringBuffer> writer(sb);
            doc.Accept(writer);
        }
        else {
            Writer<StringBuffer> writer(sb);
            doc.Accept(writer); // Accept() traverses the DOM and generates Handler events.
        }
        return std::string(sb.GetString());
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 转换整个obj到string. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="obj">      要转换的obj对象. </param>
    /// <param name="isPretty"> (Optional) 是否启用缩进格式打印. </param>
    ///
    /// <returns> Doc as a std::wstring. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline std::wstring toJsonW(const T& obj, bool isPretty = false)
    {
        using namespace rapidjson;

        DocumentW doc;
        auto& allocator = doc.GetAllocator();
        Serialize::toValue(obj, std::move(doc), allocator);

        StringBufferW sb;
        if (isPretty) {
            PrettyWriter<StringBufferW, UTF16<>, UTF16<>> writer(sb);
            doc.Accept(writer);
        }
        else {
            Writer<StringBufferW, UTF16<>, UTF16<>> writer(sb);
            doc.Accept(writer); // Accept() traverses the DOM and generates Handler events.
        }
        return std::wstring(sb.GetString());
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="text"> The text. </param>
    /// <param name="obj">  [in,out] 支持json序列化的对象. </param>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline void toObject(const std::string& text, T& obj)
    {
        Document document;
        //从string读取
        StringStream s(text.c_str());
        document.ParseStream(s);
        Serialize::getObj(document, obj);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="text"> The text. </param>
    ///
    /// <returns> json序列化的对象. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline T toObject(const std::string& text)
    {
        Document document;
        //从string读取
        StringStream s(text.c_str());
        document.ParseStream(s);
        T obj;
        Serialize::getObj(document, obj);
        return obj;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <param name="is"> 数据流. </param>
    /// <param name="obj"> 支持json序列化的对象. </param>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline void toObject(std::istream& is, T& obj)
    {
        using namespace rapidjson;
        Document document;
        IStreamWrapper isw(is);
        document.ParseStream(isw);
        Serialize::getObj(document, obj);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="is"> [in,out] 数据流. </param>
    ///
    /// <returns> json序列化的对象. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline T toObject(std::istream& is)
    {
        using namespace rapidjson;
        Document document;
        IStreamWrapper isw(is);
        document.ParseStream(isw);
        T obj;
        Serialize::getObj(document, obj);
        return obj;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <param name="text"> The text. </param>
    /// <param name="obj"> 支持json序列化的对象. </param>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline void toObjectW(const std::wstring& text, T& obj)
    {
        DocumentW document;
        //从string读取
        StringStreamW s(text.c_str());
        document.ParseStream(s);
        Serialize::getObj(document, obj);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="text"> The text. </param>
    ///
    /// <returns> json序列化的对象. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline T toObjectW(const std::wstring& text)
    {
        DocumentW document;
        //从string读取
        StringStreamW s(text.c_str());
        document.ParseStream(s);
        T obj;
        Serialize::getObj(document, obj);
        return obj;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="is">  The text. </param>
    /// <param name="obj"> [in,out] 支持json序列化的对象. </param>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline void toObjectW(const std::wistream& is, T& obj)
    {
        using namespace rapidjson;
        DocumentW document;
        WIStreamWrapper isw(is);
        StringStreamW s(isw);
        document.ParseStream(s);
        Serialize::getObj(document, obj);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并给对象赋值. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <typeparam name="T"> Generic type parameter. </typeparam>
    /// <param name="is"> 数据流. </param>
    ///
    /// <returns> json序列化的对象. </returns>
    ///-------------------------------------------------------------------------------------------------
    template <class T>
    static inline T toObjectW(const std::wistream& is)
    {
        using namespace rapidjson;
        DocumentW document;
        WIStreamWrapper isw(is);
        StringStreamW s(isw);
        document.ParseStream(s);
        T obj;
        Serialize::getObj(document, obj);
        return obj;
    }
};

//无关紧要的附加:Unity3D中的类型
namespace unity3d {

class Color32 : XUEXUE_JSON_OBJECT
{
  public:
    Color32() {}
    Color32(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) : r(r), g(g), b(b), a(a)
    {
    }

    bool operator==(const Color32& c)
    {
        if (r == c.r && g == c.g && b == c.b && a == c.a) {
            return true;
        }
        return false;
    }

    unsigned char r{0};
    unsigned char g{0};
    unsigned char b{0};
    unsigned char a{0};

    XUEXUE_JSON_OBJECT_M4(r, g, b, a)
};

} // namespace unity3d

} // namespace json
} // namespace xuexue