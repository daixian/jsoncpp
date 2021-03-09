#pragma once

#include "SerializeMerge.hpp"

namespace xuexue {
namespace json {

/**
 * object和josn的相互转换，这是包含主要的使用方法.将这个类放在代码文件最下面，不然GCC支持不了
 *
 * @author daixian
 * @date 2020/3/19
 */
class JsonMapper
{
  public:
    /**
     * 转换整个obj到一个Document.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
     *
     * @tparam T Generic type parameter.
     * @param  obj 要转换的obj对象.
     *
     * @returns Obj as a Document.
     */
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

    /**
     * 转换整个obj到一个Document.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
     *
     * @tparam T Generic type parameter.
     * @param       obj 要转换的obj对象.
     * @param [out] doc The document.
     */
    template <class T>
    static inline void toDocument(const T& obj, Document& doc)
    {
        using namespace rapidjson;

        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);
    }

    /**
     * 转换整个obj到一个DocumentW.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
     *
     * @tparam T Generic type parameter.
     * @param  obj 要转换的obj对象.
     *
     * @returns DocumentW对象.
     */
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

    /**
     * 转换整个obj到一个DocumentW.如果之后还要转成string可以调用JsonHelper::toJson()里的方法.
     *
     * @tparam T Generic type parameter.
     * @param       obj 要转换的obj对象.
     * @param [out] doc The document.
     */
    template <class T>
    static inline void toDocumentW(const T& obj, DocumentW& doc)
    {
        using namespace rapidjson;

        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);
    }

    /**
     * 转换整个obj到string.
     *
     * @tparam T Generic type parameter.
     * @param  obj      要转换的obj对象.
     * @param  isPretty (Optional) 是否启用缩进格式打印.
     *
     * @returns josn文本.
     */
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

    /**
     * 转换整个obj到string.
     *
     * @tparam T Generic type parameter.
     * @param  obj      要转换的obj对象.
     * @param  isPretty (Optional) 是否启用缩进格式打印.
     *
     * @returns josn文本.
     */
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

    /**
     * 转换整个obj到json然后写入流
     *
     * @tparam T Generic type parameter.
     * @param          obj      要转换的obj对象.
     * @param [in,out] os       要写入的流.
     * @param          isPretty (Optional) 是否美观打印.
     */
    template <class T>
    static inline void toJson(const T& obj, std::ostream& os, bool isPretty = false)
    {
        using namespace rapidjson;

        Document doc;
        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);

        OStreamWrapper osw(os);

        if (isPretty) {
            PrettyWriter<OStreamWrapper> writer(osw);
            doc.Accept(writer);
        }
        else {
            Writer<OStreamWrapper> writer(osw);
            doc.Accept(writer); // Accept() traverses the DOM and generates Handler events.
        }
    }

    /**
     * 转换整个obj到json然后写入流.(注意在windows下使用wofstream会有一些问题,所以这个方法目前没有单元测试)
     *
     * @tparam T Generic type parameter.
     * @param          obj      要转换的obj对象.
     * @param [in,out] os       要写入的流.
     * @param          isPretty (Optional) 是否美观打印.
     */
    template <class T>
    static inline void toJsonW(const T& obj, std::wostream& os, bool isPretty = false)
    {
        using namespace rapidjson;

        DocumentW doc;
        auto& allocator = doc.GetAllocator();
        //作者好像已经屏蔽了doc类型的move,所以这句move实际只是刚好让编译通过
        Serialize::toValue(obj, std::move(doc), allocator);

        WOStreamWrapper osw(os);

        if (isPretty) {
            PrettyWriter<WOStreamWrapper, UTF16<>, UTF16<>> writer(osw);
            doc.Accept(writer);
        }
        else {
            Writer<WOStreamWrapper, UTF16<>, UTF16<>> writer(osw);
            doc.Accept(writer); // Accept() traverses the DOM and generates Handler events.
        }
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param          text The text.
     * @param [in,out] obj  支持json序列化的对象.
     */
    template <class T>
    static inline void toObject(const std::string& text, T& obj)
    {
        Document document;
        //从string读取
        StringStream s(text.c_str());
        bool HasParseError = document.ParseStream(s).HasParseError();
        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param  text The text.
     *
     * @returns json反序列化的对象.
     *
     * ### remarks Dx, 2019/3/12.
     */
    template <class T>
    static inline T toObject(const std::string& text)
    {
        Document document;
        //从string读取
        StringStream s(text.c_str());
        bool HasParseError = document.ParseStream(s).HasParseError();

        T obj;
        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
        return obj;
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param [in,out] is  数据流.
     * @param [in,out] obj 支持json序列化的对象.
     */
    template <class T>
    static inline void toObject(std::istream& is, T& obj)
    {
        using namespace rapidjson;
        Document document;
        IStreamWrapper isw(is);
        bool HasParseError = document.ParseStream(isw).HasParseError();
        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param [in] is 数据流.
     *
     * @returns json反序列化的对象.
     */
    template <class T>
    static inline T toObject(std::istream& is)
    {
        using namespace rapidjson;
        Document document;
        IStreamWrapper isw(is);
        bool HasParseError = document.ParseStream(isw).HasParseError();
        T obj;
        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
        return obj;
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param          text The text.
     * @param [in,out] obj  支持json序列化的对象.
     */
    template <class T>
    static inline void toObjectW(const std::wstring& text, T& obj)
    {
        DocumentW document;
        //从string读取
        StringStreamW s(text.c_str());
        bool HasParseError = document.ParseStream(s).HasParseError();

        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param  text The text.
     *
     * @returns json反序列化的对象.
     */
    template <class T>
    static inline T toObjectW(const std::wstring& text)
    {
        DocumentW document;
        //从string读取
        StringStreamW s(text.c_str());
        bool HasParseError = document.ParseStream(s).HasParseError();
        T obj;
        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
        return obj;
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param [in,out] is  The text.
     * @param [in,out] obj 支持json序列化的对象.
     */
    template <class T>
    static inline void toObjectW(std::wistream& is, T& obj)
    {
        using namespace rapidjson;
        DocumentW document;
        WIStreamWrapper isw(is);
        bool HasParseError = document.ParseStream(isw).HasParseError();
        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
    }

    /**
     * 从json读取并给对象赋值.
     *
     * @exception std::logic_error 解析json失败时抛出.
     *
     * @tparam T Generic type parameter.
     * @param [in,out] is 数据流.
     *
     * @returns json反序列化的对象.
     */
    template <class T>
    static inline T toObjectW(std::wistream& is)
    {
        using namespace rapidjson;
        DocumentW document;
        WIStreamWrapper isw(is);
        bool HasParseError = document.ParseStream(isw).HasParseError();
        T obj;
        if (!HasParseError) {
            Serialize::getObj(document, obj);
        }
        else {
            throw std::logic_error("json has parse error!");
        }
        return obj;
    }

    /**
     * 载入一个本地的json文件.
     *
     * @exception std::logic_error      解析json失败时抛出.
     * @exception std::invalid_argument 无法打开文件时抛出.
     *
     * @tparam T Generic type parameter.
     * @param  jsonFilePath json文件路径.
     *
     * @returns json反序列化的对象.
     */
    template <class T>
    static inline T loadFile(const std::string& jsonFilePath)
    {
        std::ifstream ifs;
        ifs.open(jsonFilePath);

        T obj;
        if (ifs.is_open()) {
            try {
                JsonMapper::toObject<T>(ifs, obj);
            }
            catch (const std::exception& e) {
                ifs.close();
                throw e;
            }
        }
        else {
            throw std::invalid_argument("can not open json file!");
        }
        ifs.close();
        return obj;
    }
};

} // namespace json
} // namespace xuexue
