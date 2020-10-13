#include "gtest/gtest.h"
#include "xuexuejson/Serialize.hpp"

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

TEST(String, UTF8ToUTF16)
{
    string utf8 = "这是一条UTF8的内容!--❀❀❀";
    wstring utf16 = L"这是一条UTF8的内容!--❀❀❀";

    ASSERT_EQ(utf8.size(), 37);
    ASSERT_EQ(utf16.size(), 17);

    wstring utf16_2 = JsonHelper::utf8To16(utf8);
    ASSERT_EQ(utf16, utf16_2);
}

TEST(String, UTF16ToUTF8)
{
    string utf8 = "这是一条UTF8的内容!--❀❀❀";
    wstring utf16 = L"这是一条UTF8的内容!--❀❀❀";

    ASSERT_EQ(utf8.size(), 37);
    ASSERT_EQ(utf16.size(), 17);

    string utf8_2 = JsonHelper::utf16To8(utf16);
    ASSERT_EQ(utf8, utf8_2);
}

TEST(String, UTF8ToUTF16_EMPTY)
{
    string utf8 = "";
    wstring utf16 = L"";

    wstring utf16_2 = JsonHelper::utf8To16(utf8);
    string utf8_2 = JsonHelper::utf16To8(utf16);

    ASSERT_EQ(utf16, utf16_2);
    ASSERT_EQ(utf8, utf8_2);
}

class StringClass : XUEXUE_JSON_OBJECT
{
  public:
    StringClass() {}
    ~StringClass() {}
    std::string s1;

    std::string s2;

    XUEXUE_JSON_OBJECT_M2(s1, s2)
  private:
};

TEST(String, readStream)
{
    StringClass sc;
    sc.s1 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
    sc.s2 = "123";
    int size = sizeof(sc);
    int size1 = sizeof(sc.s1);
    int size2 = sizeof(sc.s2);

    void* psc = &(sc);
    void* p1 = &(sc.s1);
    void* p2 = &(sc.s2);

    //ASSERT_EQ(std::memcmp(p1, p2, sizeof(size)) , 0);

    std::string str = "Example string";
    for (size_t i = 0; i < 20; i++) {
        str += str;
    }
    std::istringstream iss;
    std::stringbuf* pbuf = iss.rdbuf();
    pbuf->str(str);
    auto in_avail = pbuf->in_avail();
    std::string text = JsonHelper::readStream(iss);
    ASSERT_EQ(text, str);
}

TEST(String, istreamToJson)
{
    StringClass sc;
    sc.s1 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
    sc.s2 = "123";
    int size = sizeof(sc);
    int size1 = sizeof(sc.s1);
    int size2 = sizeof(sc.s2);

    //ASSERT_EQ(std::memcmp(p1, p2, sizeof(size)) , 0);

    std::string str = JsonMapper::toJson(sc);
    std::istringstream iss;
    std::stringbuf* pbuf = iss.rdbuf();
    pbuf->str(str);
    int in_avail = pbuf->in_avail();
    StringClass sc2 = JsonMapper::toObject<StringClass>(iss);
    ASSERT_EQ(sc.s1, sc2.s1);
    ASSERT_EQ(sc.s2, sc2.s2);
}

TEST(String, loadFile)
{
    std::vector<std::string> vStr;
    vStr.push_back("123");
    vStr.push_back("456");
    string text = JsonMapper::toJson(vStr);
    JsonHelper::save("file.json", text);
    vector<string> vStr2 = JsonMapper::loadFile<vector<string>>("file.json");
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_EQ(vStr[i], vStr2[i]);
    }
}

TEST(String, loadFileNoFile)
{
    //会抛出异常
    ASSERT_THROW(vector<string> vStr2 = JsonMapper::loadFile<vector<string>>("nofile"), invalid_argument);
}

TEST(WString, toJsonW)
{
    std::vector<std::wstring> vStr;
    vStr.push_back(L"568876❀❀❀");
    vStr.push_back(L"❀❀86786");

    wstring json = JsonMapper::toJsonW(vStr, true);

    vector<wstring> vStr3 = JsonMapper::toObjectW<vector<wstring>>(json);
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_EQ(vStr[i], vStr3[i]);
    }
}

TEST(String, toJsonW)
{
    std::vector<std::string> vStr;
    vStr.push_back("568876❀❀❀");
    vStr.push_back("❀❀86786");

    wstring json = JsonMapper::toJsonW(vStr, true);

    vector<string> vStr3 = JsonMapper::toObjectW<vector<string>>(json);
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_EQ(vStr[i], vStr3[i]);
    }
}

TEST(String, toJson_ofstream)
{
    std::vector<std::string> vStr;
    vStr.push_back("568❀❀❀876❀❀❀");
    vStr.push_back("86786");
    ofstream ofs("output.json");
    JsonMapper ::toJson(vStr, ofs, true);
    ofs.close();
    vector<string> vStr2 = JsonMapper::loadFile<vector<string>>("output.json");
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_EQ(vStr[i], vStr2[i]);
    }
}

TEST(WString, toJson_ofstream)
{
    std::vector<std::wstring> vStr;
    vStr.push_back(L"568876❀❀❀");
    vStr.push_back(L"❀❀86786");
    ofstream ofs("output2.json");
    JsonMapper::toJson(vStr, ofs, true);
    ofs.close();

    vector<wstring> vStr2 = JsonMapper::loadFile<vector<wstring>>("output2.json");
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_EQ(vStr[i], vStr2[i]);
    }
}

/*
TEST(WString, toJsonW_wofstream)
{
    //std::locale oNewLocale(std::locale(), "", std::locale::ctype);
    //std::locale oPreviousLocale = std::locale::global(oNewLocale);

    std::vector<std::wstring> vStr;
    vStr.push_back(L"568876❀❀❀");
    vStr.push_back(L"❀❀86786");
    wofstream ofs("output2.json");
    //wcout.imbue(locale(locale(),"",LC_CTYPE));
    ofs << vStr[0];

    JsonMapper::toJsonW(vStr, ofs, true);
    ofs.close();

    wifstream ifs("output2.json");

    vector<wstring> vStr2 = JsonMapper::toObjectW<vector<wstring>>(ifs);
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_EQ(vStr[i] , vStr2[i]);
    }
    //std::locale::global(oPreviousLocale);
}
*/
