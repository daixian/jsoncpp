#pragma once
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h" // for stringify JSON
#include "rapidjson/filewritestream.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/encodings.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <array>
#include <iostream>
#include <fstream>

//定义是否忽略那些基本类型不匹配的错误，可以接一些类型不匹配但是逻辑上能对应的数据
#define XUEXUE_JSON_IGNORE_TYPE_ERROR

//默认定义支持这些大库里的类型，如果不需要则注销掉这两行
// #define XUEXUE_JSON_SUPPORT_OPENCV
// #define XUEXUE_JSON_SUPPORT_EIGEN

//一些大库使用到的基本类型
#ifdef XUEXUE_JSON_SUPPORT_OPENCV
#    include <opencv2/opencv.hpp>
#endif // XUEXUE_JSON_SUPPORT_OPENCV

#ifdef XUEXUE_JSON_SUPPORT_EIGEN
#    include <Eigen/Geometry>
#    include <unsupported/Eigen/EulerAngles>
#endif // XUEXUE_JSON_SUPPORT_EIGEN

namespace xuexue {
namespace json {

//使用UTF-16的doc,在rapidjson命名空间里包含UTF8的Document和Value的定义,但是不包含UTF16的
typedef rapidjson::Document Document;
typedef rapidjson::Value Value;
typedef rapidjson::StringStream StringStream;
typedef rapidjson::StringBuffer StringBuffer;

typedef rapidjson::GenericDocument<rapidjson::UTF16<>> DocumentW;
typedef rapidjson::GenericValue<rapidjson::UTF16<>> ValueW;
typedef rapidjson::GenericStringStream<rapidjson::UTF16<>> StringStreamW;
typedef rapidjson::GenericStringBuffer<rapidjson::UTF16<>> StringBufferW;

//注.如果定义了#pragma execution_character_set("utf-8"),那么文件内容是UTF-8

///-------------------------------------------------------------------------------------------------
/// <summary> json可序列化接口定义.</summary>
///
/// <remarks> Dx, 2019/1/23. </remarks>
///-------------------------------------------------------------------------------------------------
class JsonSerializable
{
  public:
    virtual ~JsonSerializable(){};
    virtual Value&& toValue(Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const = 0;
    virtual void getObj(const Value& value) = 0;
};
class JsonSerializableW
{
  public:
    virtual ~JsonSerializableW(){};
    virtual ValueW&& toValue(ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const = 0;
    virtual void getObj(const ValueW& value) = 0;
};

//类接口继承宏
#define XUEXUE_JSON_OBJECT xuexue::json::JsonSerializable, xuexue::json::JsonSerializableW
//一些方便实现接口的宏
#include "JsonSerializableImpl.h"

///-------------------------------------------------------------------------------------------------
/// <summary> 转换到Json的公共方法..</summary>
///
/// <remarks> Dx, 2019/1/23. </remarks>
///-------------------------------------------------------------------------------------------------
class JsonHelper
{
  public:
    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 保存json到文件.这个没有进行转码的处理.如果不定义下面的内容,那么就是GBK编码.
    /// #pragma execution_character_set("utf-8")
    /// 如果定义了那么代码中的文本才会是utf-8的文件.因此不应该使用这个函数,程序中统一使用UTF-16进行处理.
    /// </summary>
    ///
    /// <remarks> Dx, 2019/1/23. </remarks>
    ///
    /// <param name="filePath"> [in] 文件路径. </param>
    /// <param name="doc">      The document. </param>
    ///-------------------------------------------------------------------------------------------------
    static void save(const std::string& filePath, const Document& doc, bool isPretty = true)
    {
        FILE* fp;
#if defined(_WIN32) || defined(_WIN64)
        fopen_s(&fp, filePath.c_str(), "wb"); // 非 Windows 平台使用 "w"
#elif defined(__linux__)
        fp = fopen(filePath.c_str(), "w");
#endif
        char writeBuffer[256];
        rapidjson::FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
        if (isPretty) {
            rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
            doc.Accept(writer);
        }
        else {
            rapidjson::Writer<rapidjson::FileWriteStream> writer(os);
            doc.Accept(writer);
        }
        fclose(fp);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary>保存string到文件.</summary>
    ///
    /// <remarks> Dx, 2019/1/23. </remarks>
    ///-------------------------------------------------------------------------------------------------
    static void save(const std::string& filePath, const std::string& text)
    {
        std::ofstream osWrite(filePath);
        osWrite << text;
        osWrite.flush();
        osWrite.close();
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 输入的是utf16的doc,但是保存成utf8的格式. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <param name="filePath"> Full pathname of the file. </param>
    /// <param name="doc">      The document. </param>
    /// <param name="putBOM">   (Optional) True to put bom. </param>
    ///-------------------------------------------------------------------------------------------------
    static void save(const std::string& filePath, const DocumentW& doc, bool putBOM = false, bool isPretty = true)
    {
        using namespace rapidjson;
        FILE* fp;

#if defined(_WIN32) || defined(_WIN64)
        fopen_s(&fp, filePath.c_str(), "wb"); // 非 Windows 平台使用 "w"
#elif defined(__linux__)
        fp = fopen(filePath.c_str(), "w");
#endif
        char writeBuffer[256];
        FileWriteStream ws(fp, writeBuffer, sizeof(writeBuffer));
        typedef EncodedOutputStream<UTF8<>, FileWriteStream> EncodedOutputStream_UTF8;
        EncodedOutputStream_UTF8 os(ws, putBOM); // with BOM
        if (isPretty) {
            PrettyWriter<EncodedOutputStream_UTF8, UTF16<>, UTF8<>> writer(os);
            doc.Accept(writer);
        }
        else {
            Writer<EncodedOutputStream_UTF8, UTF16<>, UTF8<>> writer(os);
            doc.Accept(writer);
        }

        //UTFType type = UTFType::kUTF8;
        //char writeBuffer[256];
        //FileWriteStream bos(fp, writeBuffer, sizeof(writeBuffer));
        //typedef AutoUTFOutputStream<unsigned, FileWriteStream> OutputStream;
        //OutputStream eos(bos, type, putBOM);
        //Writer<OutputStream, UTF8<>, AutoUTF<unsigned>> writer;
        //doc.Accept(writer);

        fclose(fp);
    }

    //保存一个wstring的文本到文件
    static void save(const std::string& filePath, const std::wstring& text)
    {
        std::wofstream osWrite(filePath);
        osWrite << text;
        osWrite.flush();
        osWrite.close();
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从文件(不考虑编码转化的)读取json. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <param name="filePath"> Full pathname of the file. </param>
    /// <param name="doc">      [in,out] The document. </param>
    ///-------------------------------------------------------------------------------------------------
    static void readFile(const std::string& filePath, Document& doc)
    {
        using namespace rapidjson;
        FILE* fp;
#if defined(_WIN32) || defined(_WIN64)
        fopen_s(&fp, filePath.c_str(), "rb"); // 非 Windows 平台使用 "r"
#elif defined(__linux__)
        fp = fopen(filePath.c_str(), "r");
#endif
        //这里不能使用AutoUTF,因为这里的文件可能不是UTF的编码会导致失败.
        char readBuffer[256];
        rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
        doc.ParseStream(is);
        fclose(fp);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从文件UTF读取json. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <param name="filePath"> Full pathname of the file. </param>
    /// <param name="doc">      [in,out] The document. </param>
    ///-------------------------------------------------------------------------------------------------
    static void readFile(const std::string& filePath, DocumentW& doc)
    {
        using namespace rapidjson;
        FILE* fp;
#if defined(_WIN32) || defined(_WIN64)
        fopen_s(&fp, filePath.c_str(), "rb"); // 非 Windows 平台使用 "r"
#elif defined(__linux__)
        fp = fopen(filePath.c_str(), "r");
#endif
        char readBuffer[256];
        FileReadStream bis(fp, readBuffer, sizeof(readBuffer));
        AutoUTFInputStream<unsigned, FileReadStream> eis(bis);
        doc.ParseStream<0, AutoUTF<unsigned>>(eis);
        fclose(fp);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 转换doc到string. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    ///
    /// <param name="doc"> The document. </param>
    ///
    /// <returns> Doc as a std::string. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline std::string toJson(const Document& doc, bool isPretty = false)
    {
        using namespace rapidjson;
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
    /// <summary> 转换doc到string. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <param name="doc"> The document. </param>
    ///
    /// <returns> Doc as a std::wstring. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline std::wstring toJsonW(const DocumentW& doc, bool isPretty = false)
    {
        using namespace rapidjson;
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
    /// <summary> 从json读取并创建Doc. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <param name="text"> The text. </param>
    ///
    /// <returns> A DocumentW. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline void toDocument(const std::string& text, Document& document)
    {
        //从string读取
        StringStream s(text.c_str());
        document.ParseStream(s);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 从json读取并创建Doc. </summary>
    ///
    /// <remarks> Dx, 2019/3/12. </remarks>
    ///
    /// <param name="text"> The text. </param>
    ///
    /// <returns> A DocumentW. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline void toDocumentW(const std::wstring& text, DocumentW& document)
    {
        //从string读取
        StringStreamW s(text.c_str());
        document.ParseStream(s);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> UTF8转换成UTF16. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <param name="str"> The string. </param>
    ///
    /// <returns> A std::wstring. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline std::wstring utf8To16(const std::string& str)
    {
        using namespace rapidjson;
        StringStream source(str.c_str());
        StringBufferW target;
        bool hasError = false;
        while (source.Peek() != '\0')
            if (!Transcoder<UTF8<>, UTF16<>>::Transcode(source, target)) {
                hasError = true;
                break;
            }
        if (!hasError) {
            return target.GetString();
        }
        return std::wstring();
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> UTF16转换成UTF8. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <param name="str"> The string. </param>
    ///
    /// <returns> A std::string. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline std::string utf16To8(const std::wstring& str)
    {
        using namespace rapidjson;
        StringStreamW source(str.c_str());
        StringBuffer target;
        bool hasError = false;
        while (source.Peek() != L'\0')
            if (!Transcoder<UTF16<>, UTF8<>>::Transcode(source, target)) {
                hasError = true;
                break;
            }
        if (!hasError) {
            return target.GetString();
        }
        return std::string();
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> Creat empty object document. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    ///
    /// <returns> A Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline Document creatEmptyObjectDoc()
    {
        Document document;
        document.SetObject();
        return document;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 创建一个空的Object的doc. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    ///
    /// <returns> A Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline DocumentW creatEmptyObjectDocW()
    {
        DocumentW document;
        document.SetObject();
        return document;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 创建一个空的Array的doc.. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    ///
    /// <returns> A Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline Document creatEmptyArrayDoc()
    {
        Document document;
        document.SetArray();
        return document;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 创建一个空的Array的doc.. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    ///
    /// <returns> A Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline DocumentW creatEmptyArrayDocW()
    {
        DocumentW document;
        document.SetArray();
        return document;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 创建一个空空的doc. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    ///
    /// <returns> A Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline Document creatEmptyDoc()
    {
        Document document;
        return document;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 创建一个空空的doc. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    ///
    /// <returns> A Document. </returns>
    ///-------------------------------------------------------------------------------------------------
    static inline DocumentW creatEmptyDocW()
    {
        DocumentW document;
        return document;
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary> 不一致的类型适当转换. </summary>
    ///
    /// <remarks> Surface, 2019/3/11. </remarks>
    /// <param name="value"> value. </param>
    /// <param name="obj"> obj. </param>
    ///-------------------------------------------------------------------------------------------------
    static inline void ValueTypeAdapte(const Value& value, std::string& obj)
    {
        if (value.IsString()) {
            obj = value.GetString();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsTrue()) {
            obj = "true";
        }
        else if (value.IsFalse()) {
            obj = "false";
        }
        else if (value.IsInt()) {
            obj = std::to_string(value.GetInt());
        }
        else if (value.IsInt64()) {
            obj = std::to_string(value.GetInt64());
        }
        else if (value.IsUint()) {
            obj = std::to_string(value.GetUint());
        }
        else if (value.IsUint64()) {
            obj = std::to_string(value.GetUint64());
        }
        else if (value.IsFloat()) {
            obj = std::to_string(value.GetFloat());
        }
        else if (value.IsDouble()) {
            obj = std::to_string(value.GetDouble());
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, std::string& obj)
    {

        if (value.IsString()) {
            obj = utf16To8(value.GetString());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsTrue()) {
            obj = "true";
        }
        else if (value.IsFalse()) {
            obj = "false";
        }
        else if (value.IsInt()) {
            obj = std::to_string(value.GetInt());
        }
        else if (value.IsInt64()) {
            obj = std::to_string(value.GetInt64());
        }
        else if (value.IsUint()) {
            obj = std::to_string(value.GetUint());
        }
        else if (value.IsUint64()) {
            obj = std::to_string(value.GetUint64());
        }
        else if (value.IsFloat()) {
            obj = std::to_string(value.GetFloat());
        }
        else if (value.IsDouble()) {
            obj = std::to_string(value.GetDouble());
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, std::wstring& obj)
    {
        if (value.IsString()) {
            obj = utf8To16(value.GetString());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsTrue()) {
            obj = L"true";
        }
        else if (value.IsFalse()) {
            obj = L"false";
        }
        else if (value.IsInt()) {
            obj = std::to_wstring(value.GetInt());
        }
        else if (value.IsInt64()) {
            obj = std::to_wstring(value.GetInt64());
        }
        else if (value.IsUint()) {
            obj = std::to_wstring(value.GetUint());
        }
        else if (value.IsUint64()) {
            obj = std::to_wstring(value.GetUint64());
        }
        else if (value.IsFloat()) {
            obj = std::to_wstring(value.GetFloat());
        }
        else if (value.IsDouble()) {
            obj = std::to_wstring(value.GetDouble());
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, std::wstring& obj)
    {
        if (value.IsString()) {
            obj = value.GetString();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsTrue()) {
            obj = L"true";
        }
        else if (value.IsFalse()) {
            obj = L"false";
        }
        else if (value.IsInt()) {
            obj = std::to_wstring(value.GetInt());
        }
        else if (value.IsInt64()) {
            obj = std::to_wstring(value.GetInt64());
        }
        else if (value.IsUint()) {
            obj = std::to_wstring(value.GetUint());
        }
        else if (value.IsUint64()) {
            obj = std::to_wstring(value.GetUint64());
        }
        else if (value.IsFloat()) {
            obj = std::to_wstring(value.GetFloat());
        }
        else if (value.IsDouble()) {
            obj = std::to_wstring(value.GetDouble());
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, bool& obj)
    {
        if (value.IsBool()) {
            obj = value.GetBool();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            const char* str = value.GetString();
            if ((str[0] == 't' || str[0] == 'T') &&
                (str[1] == 'r' || str[1] == 'R') &&
                (str[2] == 'u' || str[2] == 'U') &&
                (str[3] == 'e' || str[3] == 'E')) {
                obj = true;
            }
            else if ((str[0] == 'f' || str[0] == 'F') &&
                     (str[1] == 'a' || str[1] == 'A') &&
                     (str[2] == 'l' || str[2] == 'L') &&
                     (str[3] == 's' || str[3] == 'S') &&
                     (str[4] == 'e' || str[4] == 'E')) {
                obj = false;
            }
            else if (value.IsInt()) {
                if (value.GetInt() == 0) {
                    obj = false;
                }
                else if (value.GetInt() == 1) {
                    obj = true;
                }
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, bool& obj)
    {
        if (value.IsBool()) {
            obj = value.GetBool();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            const wchar_t* str = value.GetString();
            if ((str[0] == L't' || str[0] == L'T') &&
                (str[1] == L'r' || str[1] == L'R') &&
                (str[2] == L'u' || str[2] == L'U') &&
                (str[3] == L'e' || str[3] == L'E')) {
                obj = true;
            }
            else if ((str[0] == L'f' || str[0] == L'F') &&
                     (str[1] == L'a' || str[1] == L'A') &&
                     (str[2] == L'l' || str[2] == L'L') &&
                     (str[3] == L's' || str[3] == L'S') &&
                     (str[4] == L'e' || str[4] == L'E')) {
                obj = false;
            }
        }
        else if (value.IsInt()) {
            if (value.GetInt() == 0) {
                obj = false;
            }
            else if (value.GetInt() == 1) {
                obj = true;
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, int& obj)
    {
        if (value.IsInt()) {
            obj = value.GetInt();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stoi(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, int& obj)
    {
        if (value.IsInt()) {
            obj = value.GetInt();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stoi(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, char& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<char>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<short>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, char& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<char>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<short>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, short& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<short>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<short>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, short& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<short>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<short>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, int64_t& obj)
    {
        if (value.IsInt()) {
            obj = value.GetInt();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stoll(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, int64_t& obj)
    {
        if (value.IsInt()) {
            obj = value.GetInt();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stoll(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, uint8_t& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<uint8_t>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<uint8_t>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, uint8_t& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<uint8_t>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<uint8_t>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, uint16_t& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<uint16_t>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<uint16_t>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, uint16_t& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<uint16_t>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<uint16_t>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, uint32_t& obj)
    {
        if (value.IsUint()) {
            obj = value.GetUint();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<uint32_t>(std::stoul(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, uint32_t& obj)
    {
        if (value.IsUint()) {
            obj = value.GetUint();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<uint32_t>(std::stoul(value.GetString()));
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, uint64_t& obj)
    {
        if (value.IsUint64()) {
            obj = value.GetUint64();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stoull(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, uint64_t& obj)
    {
        if (value.IsUint64()) {
            obj = value.GetUint64();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stoull(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, float& obj)
    {
        if (value.IsFloat()) {
            obj = value.GetFloat();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stof(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, float& obj)
    {
        if (value.IsFloat()) {
            obj = value.GetFloat();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stof(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, double& obj)
    {
        if (value.IsDouble()) {
            obj = value.GetDouble();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stod(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, double& obj)
    {
        if (value.IsDouble()) {
            obj = value.GetDouble();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = std::stod(value.GetString());
            }
            catch (const std::exception&) {
            }
        }
#endif
    }
};

///-------------------------------------------------------------------------------------------------
/// <summary> 使用rapidjson扩展的一些固定序列化/反序列化方法. </summary>
///-------------------------------------------------------------------------------------------------
class Serialize
{
  public:
    // ======================================== 所有基本类型 ========================================

    //const char* const wstring ---------------------------------------------
    static inline Value&& toValue(const char* obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.SetString(obj, allocator));
    }

    static inline ValueW&& toValue(const char* obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.SetString(JsonHelper::utf8To16(obj).c_str(), allocator));
    }

    static inline Value&& toValue(const wchar_t* obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.SetString(JsonHelper::utf16To8(obj).c_str(), allocator));
    }

    static inline ValueW&& toValue(const wchar_t* obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.SetString(obj, allocator));
    }

    //实现丑陋,字符串还是全用string类吧
    //static inline void getObj(const ValueW& value, const wchar_t*& obj)
    //{
    //    obj = value.GetString();
    //}

    //这样子的生命周期有问题
    //static inline void getObj(const ValueW& value, const char*& obj)
    //{
    //    std::wstring ws = value.GetString();
    //    obj = JsonHelper::utf16To8(ws).c_str();
    //}

    //string wstring ---------------------------------------------------------
    //必须是utf8的string
    static inline Value&& toValue(const std::string& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {

        return std::move(value.SetString(obj.c_str(), allocator));
    }

    static inline void getObj(const Value& value, std::string& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline ValueW&& toValue(const std::string& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {

        return std::move((value.SetString(JsonHelper::utf8To16(obj).c_str(), allocator)));
    }

    static inline void getObj(const ValueW& value, std::string& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline Value&& toValue(const std::wstring& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.SetString(JsonHelper::utf16To8(obj).c_str(), allocator));
    }

    static inline void getObj(const Value& value, std::wstring& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline ValueW&& toValue(const std::wstring& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move((value.SetString(obj.c_str(), allocator)));
    }

    static inline void getObj(const ValueW& value, std::wstring& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    //基本类型 --------------------------------------------------------------
    static inline Value&& toValue(const double& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline Value&& toValue(const float& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline Value&& toValue(const char& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move((value.Set(static_cast<int>(obj))));
    }

    static inline Value&& toValue(const short& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move((value.Set(static_cast<int>(obj))));
    }

    static inline Value&& toValue(const int& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move((value.Set(obj)));
    }

    static inline Value&& toValue(const int64_t& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline Value&& toValue(const unsigned char& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move((value.Set(static_cast<unsigned int>(obj))));
    }

    static inline Value&& toValue(const unsigned short& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move((value.Set(static_cast<unsigned int>(obj))));
    }

    static inline Value&& toValue(const unsigned int& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline Value&& toValue(const uint64_t& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline Value&& toValue(const bool& obj, Value&& value,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline void getObj(const Value& value, double& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }
    static inline void getObj(const Value& value, float& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, char& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, short& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, int& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, int64_t& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, unsigned char& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, unsigned short& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, unsigned int& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, uint64_t& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const Value& value, bool& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline ValueW&& toValue(const double& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline ValueW&& toValue(const float& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline ValueW&& toValue(const int& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline ValueW&& toValue(const int64_t& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline ValueW&& toValue(const unsigned int& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline ValueW&& toValue(const uint64_t& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline ValueW&& toValue(const bool& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        return std::move(value.Set(obj));
    }

    static inline void getObj(const ValueW& value, double& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }
    static inline void getObj(const ValueW& value, float& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const ValueW& value, int& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const ValueW& value, int64_t& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const ValueW& value, unsigned int& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const ValueW& value, uint64_t& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

    static inline void getObj(const ValueW& value, bool& obj)
    {
        JsonHelper::ValueTypeAdapte(value, obj);
    }

#ifdef XUEXUE_JSON_SUPPORT_OPENCV

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

#endif // XUEXUE_JSON_SUPPORT_OPENCV

#ifdef XUEXUE_JSON_SUPPORT_EIGEN
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

#endif // XUEXUE_JSON_SUPPORT_EIGEN

    // =================================  JsonSerializable接口模板 =====================================
    //自定义接口模板里面必须要含有这两个函数
    template <class T>
    static inline Value&& toValue(const T& obj, Value&& jv,
                                  rapidjson::MemoryPoolAllocator<>& allocator)
    {
        //检察类型,如果不是JsonSerializable接口那么就返回
        if (!std::is_base_of<JsonSerializable, T>::value) {
            jv.SetNull();
            return std::move(jv);
        }
        JsonSerializable* ptr = (JsonSerializable*)&obj;
        return ptr->toValue(std::move(jv), allocator);
    }

    template <class T>
    static inline void getObj(const Value& value, T& obj)
    {
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
            jv.SetNull();
            return std::move(jv);
        }
        JsonSerializableW* ptr = (JsonSerializableW*)&obj;
        return ptr->toValue(std::move(jv), allocator);
    }

    template <class T>
    static inline void getObj(const ValueW& value, T& obj)
    {
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
        for (size_t i = 0; i < obj.size(); i++) {
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
        for (size_t i = 0; i < value.Size(); i++) {
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
        for (size_t i = 0; i < obj.size(); i++) {
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
        for (size_t i = 0; i < value.Size(); i++) {
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
        for (size_t i = 0; i < value.Size(); i++) {
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
        for (size_t i = 0; i < value.Size(); i++) {
            getObj(value[i], obj[i]);
        }
    }

    template <typename T, size_t _Size>
    static inline ValueW&& toValue(const std::array<T, _Size>& obj, ValueW&& value,
                                   rapidjson::MemoryPoolAllocator<>& allocator)
    {
        value.SetArray();
        for (size_t i = 0; i < obj.size(); i++) {
            value.PushBack(toValue(obj[i], ValueW(), allocator), allocator);
        }
        return std::move(value);
    }

    template <typename T, size_t _Size>
    static inline void getObj(const ValueW& value, std::array<T, _Size>& obj)
    {
        if (!value.IsArray()) //它应该是一个array
            return;
        for (size_t i = 0; i < value.Size(); i++) {
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
};

//对象和josn的相互转换，将这个类放在最下面，不然GCC支持不了
class JsonMapper
{
  public:
    ///-------------------------------------------------------------------------------------------------
    /// <summary> 转换整个obj到string. </summary>
    ///
    /// <remarks> Dx, 2019/3/11. </remarks>
    ///
    /// <param name="obj"> 要转换的obj对象. </param>
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
    /// <param name="obj"> 要转换的obj对象. </param>
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
    /// <param name="text"> The text. </param>
    /// <param name="obj"> 支持json序列化的对象. </param>
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
    /// <param name="text"> The text. </param>
    /// <param name="obj"> 支持json序列化的对象. </param>
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
    /// <param name="text"> The text. </param>
    /// <param name="obj"> 支持json序列化的对象. </param>
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
};

//Unity3D中的类型
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