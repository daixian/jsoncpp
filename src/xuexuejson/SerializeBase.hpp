#pragma once
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"
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
#include <memory>
#include <stdexcept>

//定义是否忽略那些基本类型不匹配的错误，可以接一些类型不匹配但是逻辑上能对应的数据
#define XUEXUE_JSON_IGNORE_TYPE_ERROR

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

/**
 * json可序列化接口定义.
 *
 * @author daixian
 * @date 2019/1/23
 */
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

class JsonSerializeSuper
{
  public:
    virtual ~JsonSerializeSuper(){};

    //构造一个子类对象,返回一个新的子类对象指针
    virtual void* instance() const = 0;
};

//类接口继承宏
#define XUEXUE_JSON_OBJECT xuexue::json::JsonSerializable, xuexue::json::JsonSerializableW
#define XUEXUE_JSON_SUPER \
  public                  \
    virtual xuexue::json::JsonSerializeSuper

#define XUEXUE_JSON_SUPER_OBJECT \
  public                         \
    virtual xuexue::json::JsonSerializeSuper, xuexue::json::JsonSerializable, xuexue::json::JsonSerializableW

//一些方便实现接口的宏
#include "JsonSerializableImpl.h"

/**
 * 一些到Json相关的辅助方法.
 *
 * @author daixian
 * @date 2019/1/23
 */
class JsonHelper
{
  public:
    /**
     * 保存json到文件.这个没有进行转码的处理.如果不定义下面的内容,那么就是GBK编码.
     * #pragma execution_character_set("utf-8")
     * 如果定义了那么代码中的文本才会是utf-8的文件.因此不应该使用这个函数,程序中统一使用UTF-
     * 16进行处理.
     *
     * @author daixian
     * @date 2019/1/23
     *
     * @param [in] filePath 文件路径.
     * @param      doc      document对象.
     * @param      isPretty (Optional)是否美观打印.
     */
    static void save(const std::string& filePath, const Document& doc, bool isPretty = true)
    {
        FILE* fp = nullptr;
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
        if (fp != nullptr)
            fclose(fp);
    }

    /**
     * 保存string到文件.
     *
     * @author daixian
     * @date 2019/1/23
     *
     * @param  filePath 文件路径.
     * @param  text     要保存的文本.
     */
    static void save(const std::string& filePath, const std::string& text)
    {
        std::ofstream osWrite(filePath);
        osWrite << text;
        osWrite.flush();
        osWrite.close();
    }

    /**
     * 保存一个wstring的文本到文件
     *
     * @author daixian
     * @date 2019/1/23
     *
     * @param  filePath 文件路径.
     * @param  text     要保存的文本.
     */
    static void save(const std::string& filePath, const std::wstring& text)
    {
        std::wofstream osWrite(filePath);
        osWrite << text;
        osWrite.flush();
        osWrite.close();
    }

    /**
     * 输入的是utf16的doc,但是保存成utf8的格式.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @param  filePath 文件路径.
     * @param  doc      document对象.
     * @param  putBOM   (Optional) 是否输出BOM头.
     * @param  isPretty (Optional) 是否美观打印.
     */
    static void save(const std::string& filePath, const DocumentW& doc, bool putBOM = false, bool isPretty = true)
    {
        using namespace rapidjson;
        FILE* fp = nullptr;

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
        if (fp != nullptr)
            fclose(fp);
    }

    /**
     * 从文件(不考虑编码转化的)读取json，注意检查HasParseError.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @param       filePath 文件路径.
     * @param [out] doc      document对象.
     */
    static void readFile(const std::string& filePath, Document& doc)
    {
        using namespace rapidjson;
        FILE* fp = nullptr;
#if defined(_WIN32) || defined(_WIN64)
        fopen_s(&fp, filePath.c_str(), "rb"); // 非 Windows 平台使用 "r"
#elif defined(__linux__)
        fp = fopen(filePath.c_str(), "r");
#endif
        //这里不能使用AutoUTF,因为这里的文件可能不是UTF的编码会导致失败.
        char readBuffer[256];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));
        doc.ParseStream(is);
        if (fp != nullptr)
            fclose(fp);
    }

    /**
     * 从文件UTF读取json，注意检查HasParseError.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @param       filePath 文件路径.
     * @param [out] doc      document对象.
     */
    static void readFile(const std::string& filePath, DocumentW& doc)
    {
        using namespace rapidjson;
        FILE* fp = nullptr;
#if defined(_WIN32) || defined(_WIN64)
        fopen_s(&fp, filePath.c_str(), "rb"); // 非 Windows 平台使用 "r"
#elif defined(__linux__)
        fp = fopen(filePath.c_str(), "r");
#endif
        char readBuffer[256];
        FileReadStream bis(fp, readBuffer, sizeof(readBuffer));
        AutoUTFInputStream<unsigned, FileReadStream> eis(bis);
        doc.ParseStream<0, AutoUTF<unsigned>>(eis);
        if (fp != nullptr)
            fclose(fp);
    }

    /**
     * 从一个stream里读取string.(TODO:这个函数未测试)
     *
     * @author daixian
     * @date 2020/3/19
     *
     * @param [in,out] is 流.
     *
     * @returns 读取的文本.
     */
    static std::string readStream(std::istream& is)
    {
        char buff[128];
        std::string text;
        while (true) {
            auto count = is.readsome(buff, sizeof(buff));
            text.append(buff, count);
            if (count < sizeof(buff)) {
                break;
            }
        }
        return text;
    }

    /**
     * 转换doc到string.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @param  doc      document对象.
     * @param  isPretty (Optional) 是否美观打印.
     *
     * @returns json文本.
     */
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

    /**
     * 转换doc到string.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @param  doc      document对象.
     * @param  isPretty (Optional) 是否美观打印.
     *
     * @returns json文本.
     */
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

    /**
     * 从json读取并创建Doc,注意检查HasParseError.
     *
     * @author daixian
     * @date 2019/3/12
     *
     * @param          text     json文本.
     * @param [in,out] document document对象.
     */
    static inline void toDocument(const std::string& text, Document& document)
    {
        //从string读取
        StringStream s(text.c_str());
        document.ParseStream(s);
    }

    /**
     * 从json读取并创建Doc,注意检查HasParseError.
     *
     * @author daixian
     * @date 2019/3/12
     *
     * @param          text     json文本.
     * @param [in,out] document document对象.
     */
    static inline void toDocumentW(const std::wstring& text, DocumentW& document)
    {
        //从string读取
        StringStreamW s(text.c_str());
        document.ParseStream(s);
    }

    /**
     * UTF8转换成UTF16，实际是string和wstring的互转.
     *
     * @author daixian
     * @date 2019/3/11.
     *
     * @param  str utf8编码的string.
     *
     * @returns utf16编码的wstring.
     */
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

    /**
     * UTF16转换成UTF8，实际是string和wstring的互转.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @param  wstr utf16编码的wstring.
     *
     * @returns utf16编码的wstring.
     */
    static inline std::string utf16To8(const std::wstring& wstr)
    {
        using namespace rapidjson;
        StringStreamW source(wstr.c_str());
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

    /**
     * 创建一个空的Object的doc.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @returns A Document.
     */
    static inline Document creatEmptyObjectDoc()
    {
        Document document;
        document.SetObject();
        return document;
    }

    /**
     * 创建一个空的Object的doc.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @returns A Document.
     */
    static inline DocumentW creatEmptyObjectDocW()
    {
        DocumentW document;
        document.SetObject();
        return document;
    }

    /**
     * 创建一个空的Array的doc.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @returns A Document.
     */
    static inline Document creatEmptyArrayDoc()
    {
        Document document;
        document.SetArray();
        return document;
    }

    /**
     * 创建一个空的Array的doc.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @returns A Document.
     */
    static inline DocumentW creatEmptyArrayDocW()
    {
        DocumentW document;
        document.SetArray();
        return document;
    }

    /**
     * 创建一个空空的doc.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @returns A Document.
     */
    static inline Document creatEmptyDoc()
    {
        Document document;
        return document;
    }

    /**
     * 创建一个空空的doc.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @returns A Document.
     */
    static inline DocumentW creatEmptyDocW()
    {
        DocumentW document;
        return document;
    }

    /**
     * 不一致的类型适当转换.
     *
     * @author daixian
     * @date 2019/3/11
     *
     * @param          value Value.
     * @param [in,out] obj   obj.
     */
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

    static inline void ValueTypeAdapte(const Value& value, char& obj)
    {
        if (value.IsInt()) {
            obj = static_cast<char>(value.GetInt());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<char>(std::stoi(value.GetString()));
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
                obj = static_cast<char>(std::stoi(value.GetString()));
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

    static inline void ValueTypeAdapte(const Value& value, int& obj)
    {
        if (value.IsInt()) {
            obj = value.GetInt();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsNumber()) {
            obj = static_cast<int>(value.GetDouble());
        }
        else if (value.IsString()) {
            try {
                obj = std::stoi(value.GetString());
            }
            catch (const std::exception&) {
                //懒得做处理了
                obj = 0;
                std::string str = value.GetString();
                int size = (int)str.size();
                int copyLen = size < sizeof(int) ? size : sizeof(int);
                memcpy(&obj, str.c_str(), copyLen);
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
        else if (value.IsNumber()) {
            obj = static_cast<int>(value.GetDouble());
        }
        else if (value.IsString()) {
            try {
                obj = std::stoi(value.GetString());
            }
            catch (const std::exception&) {
                //懒得做处理了
                obj = 0;
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, int64_t& obj)
    {
        if (value.IsInt() || value.IsInt64()) {
            obj = value.GetInt64();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsNumber()) {
            obj = static_cast<int64_t>(value.GetDouble());
        }
        else if (value.IsString()) {
            try {
                obj = std::stoll(value.GetString());
            }
            catch (const std::exception&) {
                //懒得做处理了
                obj = 0;
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, int64_t& obj)
    {
        if (value.IsInt() || value.IsInt64()) {
            obj = value.GetInt64();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsNumber()) {
            obj = static_cast<int64_t>(value.GetDouble());
        }
        else if (value.IsString()) {
            try {
                obj = std::stoll(value.GetString());
            }
            catch (const std::exception&) {
                obj = 0;
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, uint8_t& obj)
    {
        if (value.IsUint()) {
            obj = static_cast<uint8_t>(value.GetUint());
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
        if (value.IsUint()) {
            obj = static_cast<uint8_t>(value.GetUint());
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
        if (value.IsUint()) {
            obj = static_cast<uint16_t>(value.GetUint());
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsString()) {
            try {
                obj = static_cast<uint16_t>(std::stoi(value.GetString()));
            }
            catch (const std::exception&) {
                //懒得做处理了
                obj = 0;
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const ValueW& value, uint16_t& obj)
    {
        if (value.IsUint()) {
            obj = static_cast<uint16_t>(value.GetUint());
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
        else if (value.IsNumber()) {
            double d = value.GetDouble();
            if (d >= 0) {
                obj = static_cast<uint32_t>(d);
            }
        }
        else if (value.IsString()) {
            try {
                obj = static_cast<uint32_t>(std::stoul(value.GetString()));
            }
            catch (const std::exception&) {
                //懒得做处理了
                obj = 0;
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
        else if (value.IsNumber()) {
            double d = value.GetDouble();
            if (d >= 0) {
                obj = static_cast<uint32_t>(d);
            }
        }
        else if (value.IsString()) {
            try {
                obj = static_cast<uint32_t>(std::stoul(value.GetString()));
            }
            catch (const std::exception&) {
                //懒得做处理了
                obj = 0;
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, uint64_t& obj)
    {
        if (value.IsUint() || value.IsUint64()) {
            obj = value.GetUint64();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsNumber()) {
            double d = value.GetDouble();
            if (d >= 0) {
                obj = static_cast<uint64_t>(d);
            }
        }
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
        if (value.IsUint() || value.IsUint64()) {
            obj = value.GetUint64();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsNumber()) {
            double d = value.GetDouble();
            if (d >= 0) {
                obj = static_cast<uint64_t>(d);
            }
        }
        else if (value.IsString()) {
            try {
                obj = std::stoull(value.GetString());
            }
            catch (const std::exception&) {
                //懒得做处理了
                obj = 0;
            }
        }
#endif
    }

    static inline void ValueTypeAdapte(const Value& value, float& obj)
    {
        if (value.IsFloat() || value.IsInt()) {
            obj = value.GetFloat();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsNumber()) {
            obj = static_cast<float>(value.GetDouble());
        }
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
        if (value.IsFloat() || value.IsInt()) {
            obj = value.GetFloat();
        }
#ifdef XUEXUE_JSON_IGNORE_TYPE_ERROR
        else if (value.IsNumber()) {
            obj = static_cast<float>(value.GetDouble());
        }
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
        if (value.IsNumber()) {
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
        if (value.IsNumber()) {
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

// 使用rapidjson扩展的一些固定序列化/反序列化方法.
namespace Serialize {

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

static inline void getObj(const ValueW& value, char& obj)
{
    JsonHelper::ValueTypeAdapte(value, obj);
}

static inline void getObj(const ValueW& value, short& obj)
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

static inline void getObj(const ValueW& value, unsigned char& obj)
{
    JsonHelper::ValueTypeAdapte(value, obj);
}

static inline void getObj(const ValueW& value, unsigned short& obj)
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

} // namespace Serialize

} // namespace json
} // namespace xuexue
