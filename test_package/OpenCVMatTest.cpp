#include "gtest/gtest.h"

// 目前别的平台没有编译opencv
#if defined(_WIN32)

#    include "xuexuejson/Serialize.hpp"

#    pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

TEST(OpenCV, cvMat_double)
{
    cv::Mat m;
    m = (cv::Mat_<double>(4, 4) << 1, 0, 0, 0,
         0, -1, 0, 0,
         0, 0, 0.1, 0,
         0, 0, 0, 1);

    //序列化到doc
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();
    doc.AddMember(L"m1", Serialize::toValue(m, ValueW(kNullType), allocator), allocator);

    //保存到string
    wstring text = JsonHelper::toJsonW(doc);

    //从string读取
    DocumentW doc2;
    JsonHelper::toDocumentW(text, doc2);
    cv::Mat m2;
    Serialize::getObj(doc2[L"m1"], m2);

    //比较两个Mat
    ASSERT_TRUE(m2.cols == m.cols);
    ASSERT_TRUE(m2.rows == m.rows);
    ASSERT_TRUE(m2.type() == m.type());
    double* m_p = m.ptr<double>();
    double* m2_p = m2.ptr<double>();

    for (size_t i = 0; i < m.cols * m.rows; i++) {
        ASSERT_TRUE(m_p[i] == m2_p[i]);
    }
}

TEST(OpenCV, cvMat_short)
{
    cv::Mat m;
    m = (cv::Mat_<short>(4, 4) << 1, 0, 0, 0,
         0, -1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1);

    //序列化到doc
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();
    doc.AddMember(L"m1", Serialize::toValue(m, ValueW(kNullType), allocator), allocator);

    //保存到string
    wstring text = JsonHelper::toJsonW(doc);

    //从string读取
    DocumentW doc2;
    JsonHelper::toDocumentW(text, doc2);
    cv::Mat m2;
    Serialize::getObj(doc2[L"m1"], m2);

    //比较两个Mat
    ASSERT_TRUE(m2.cols == m.cols);
    ASSERT_TRUE(m2.rows == m.rows);
    ASSERT_TRUE(m2.type() == m.type());
    short* m_p = m.ptr<short>();
    short* m2_p = m2.ptr<short>();

    for (size_t i = 0; i < m.cols * m.rows; i++) {
        ASSERT_TRUE(m_p[i] == m2_p[i]);
    }
}

//测试mat的json<->obj
TEST(OpenCV, cvMat_float)
{
    cv::Mat m;
    m = (cv::Mat_<float>(4, 4) << 1, 0, 0, 0,
         0, -1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1);

    //序列化到doc
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();
    doc.AddMember(L"m1", Serialize::toValue(m, ValueW(kNullType), allocator), allocator);

    //保存到string
    wstring text = JsonHelper::toJsonW(doc);

    //从string读取
    DocumentW doc2;
    JsonHelper::toDocumentW(text, doc2);
    cv::Mat m2;
    Serialize::getObj(doc2[L"m1"], m2);

    //比较两个Mat
    ASSERT_TRUE(m2.cols == m.cols);
    ASSERT_TRUE(m2.rows == m.rows);
    ASSERT_TRUE(m2.type() == m.type());
    float* m_p = m.ptr<float>();
    float* m2_p = m2.ptr<float>();

    for (size_t i = 0; i < m.cols * m.rows; i++) {
        ASSERT_TRUE(m_p[i] == m2_p[i]);
    }
}

TEST(OpenCV, vector_cvMat)
{
    cv::Mat m;
    m = (cv::Mat_<float>(4, 4) << 1, 0, 0, 0,
         0, -1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1);
    vector<cv::Mat> vm;
    for (size_t i = 0; i < 10; i++) {
        vm.push_back(m);
    }

    //序列化到doc
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();
    doc.AddMember(L"vm", Serialize::toValue(vm, ValueW(), allocator), allocator);

    //保存到string
    wstring text = JsonHelper::toJsonW(doc);

    //从string读取
    DocumentW doc2;
    JsonHelper::toDocumentW(text, doc2);
    vector<cv::Mat> vm2;
    Serialize::getObj(doc2[L"vm"], vm2);

    //比较两个Mat
    ASSERT_TRUE(vm.size() == vm2.size());
}

TEST(Json, rpTest)
{
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();
    doc.AddMember(L"item", Serialize::toValue(L"31231312213", ValueW(), allocator), allocator);
    //保存到string
    wstring text = JsonHelper::toJsonW(doc);

    wstring obj2;
    Serialize::getObj(doc[L"item"], obj2);
    //v.Set(123132);
}

TEST(Json, ListTest)
{
    list<string> ls;
    for (size_t i = 0; i < 100; i++) {
        ls.push_back((boost::format("这个是一条内容%llu") % i).str());
    }
    for (size_t i = 0; i < 100; i++) {

        string texe = JsonMapper::toJson(ls, true);
        list<string> ls2;
        JsonMapper::toObject(texe, ls2);

        list<string> ls3 = std::move(JsonMapper::toObject<list<string>>(texe));
        auto it2 = ls2.begin();
        auto it3 = ls3.begin();
        for (auto& item : ls) {
            ASSERT_TRUE(item == *it2);
            ASSERT_TRUE(item == *it3);
            ++it2;
            ++it3;
        }
    }
}

TEST(Json, ArrayTest)
{
    array<string, 100> arr;
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = (boost::format("这个是一条内容%llu") % i).str();
    }
    for (size_t i = 0; i < 100; i++) {

        string texe = JsonMapper::toJson(arr, true);
        array<string, 100> arr2;
        JsonMapper::toObject(texe, arr2);

        array<string, 100> arr3 = JsonMapper::toObject<array<string, 100>>(texe);

        for (size_t i = 0; i < arr.size(); i++) {
            ASSERT_TRUE(arr[i] == arr2[i]);
            ASSERT_TRUE(arr[i] == arr3[i]);
        }
    }
}

class VectorData : public testing::Test
{
  protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }

  public:
    class Data : XUEXUE_JSON_OBJECT
    {
      public:
        Data()
        {
            for (size_t i = 0; i < 20; i++) {
                vs.push_back((boost::format("这个是一条内容%llu❀❀❀❀") % i).str());
            }
            for (size_t i = 0; i < 20; i++) {
                vvs.push_back(vs);
            }
            for (size_t i = 0; i < 20; i++) {
                vvvs.push_back(vvs);
            }
        }
        ~Data() {}

        vector<string> vs;
        vector<vector<string>> vvs;
        vector<vector<vector<string>>> vvvs;

        XUEXUE_JSON_OBJECT_M3(vs, vvs, vvvs)
    };

    Data data;
};

TEST_F(VectorData, vectorTest)
{
    for (size_t i = 0; i < 10; i++) {
        string text = JsonMapper::toJson(data);
        Data data2 = JsonMapper::toObject<Data>(text);

        for (size_t i = 0; i < data.vs.size(); i++) {
            ASSERT_TRUE(data.vs[i] == data2.vs[i]);
        }
        for (size_t i = 0; i < data.vvs.size(); i++) {
            ASSERT_TRUE(data.vvs[i] == data2.vvs[i]);
        }
        for (size_t i = 0; i < data.vvvs.size(); i++) {
            ASSERT_TRUE(data.vvvs[i] == data2.vvvs[i]);
        }
    }
}

TEST(Json, EmptyTest)
{
    vector<string> vs;
    string texe = JsonMapper::toJson(vs, false);
    ASSERT_TRUE(texe == "[]");
    vector<string> vs2 = JsonMapper::toObject<vector<string>>(texe);
    ASSERT_TRUE(vs2.size() == 0);

    map<int, string> mis;
    texe = JsonMapper::toJson(mis, true);
    ASSERT_TRUE(texe == "{}");
    map<int, string> mis2 = JsonMapper::toObject<map<int, string>>(texe);
    ASSERT_TRUE(mis2.size() == 0);

    map<int, string> mis3 = JsonMapper::toObject<map<int, string>>("");
    ASSERT_TRUE(mis3.size() == 0);

    map<int, string> mis4 = JsonMapper::toObject<map<int, string>>("21312");
    ASSERT_TRUE(mis4.size() == 0);

    //这是一个类型不匹配的错误
    string str;
    Serialize::getObj(Value(kNullType), str);
}

TEST(Json, typeAdapte)
{
    //string->i
    vector<string> vs;
    for (size_t i = 0; i < 100; i++) {
        vs.push_back(std::to_string(i));
    }
    string texe = JsonMapper::toJson(vs, false);

    //把一个string的用int接下来
    vector<int> vs2 = JsonMapper::toObject<vector<int>>(texe);

    for (size_t i = 0; i < vs.size(); i++) {
        ASSERT_TRUE((std::to_string(vs2[i]) == vs[i]));
    }

    texe = JsonMapper::toJson("true", false);
    bool b = false;
    b = JsonMapper::toObject<bool>(texe);
    ASSERT_TRUE(b == true);

    texe = JsonMapper::toJson("false", false);
    b = JsonMapper::toObject<bool>(texe);
    ASSERT_TRUE(b == false);
}

TEST(Json, cvPoint)
{
    cv::Point o(123, 321);
    string text = JsonMapper::toJson(o);
    cv::Point o2 = JsonMapper::toObject<cv::Point>(text);
    ASSERT_TRUE(o == o2);
}

TEST(Json, cvPoint3)
{
    cv::Point3i o(123, 321, 312413);
    string text = JsonMapper::toJson(o);
    cv::Point3i o2 = JsonMapper::toObject<cv::Point3i>(text);
    ASSERT_TRUE(o == o2);
}

TEST(Json, cvRect)
{
    cv::Rect o(123, 321, 252, 54353);
    string text = JsonMapper::toJson(o);
    cv::Rect o2 = JsonMapper::toObject<cv::Rect>(text);
    ASSERT_TRUE(o == o2);
}

TEST(Json, unity3dColor32)
{
    unity3d::Color32 color(255, 123, 32);
    string text = JsonMapper::toJson(color);
    unity3d::Color32 o2 = JsonMapper::toObject<unity3d::Color32>(text);
    ASSERT_TRUE(color == o2);
}

class cvComponent : XUEXUE_JSON_SUPER_OBJECT
{
  public:
    cvComponent() {}
    virtual ~cvComponent() {}

    /// <summary>
    /// 组件类型
    /// </summary>
    std::string type;

    XUEXUE_JSON_OBJECT_M1(type)
    //实现XUEXUE_JSON_SUPER
    virtual void* instance() const;
};

/// <summary>
/// Line组件
/// </summary>
class cvLine : public cvComponent
{
  public:
    cvLine() {}
    virtual ~cvLine() {}

    /// <summary> 颜色 </summary>
    xuexue::json::unity3d::Color32 color;

    /// <summary> 点0. </summary>
    Eigen::Vector3d pos0;

    /// <summary> 点1. </summary>
    Eigen::Vector3d pos1;

    XUEXUE_JSON_OBJECT_M4(type, color, pos0, pos1)
};
class cvObject : XUEXUE_JSON_OBJECT
{
  public:
    cvObject() {}
    virtual ~cvObject() {}

    /// <summary> 物体名字. </summary>
    std::string name;

    /// <summary> 所有包含的组件. </summary>
    std::vector<std::shared_ptr<cvComponent>> components;

    /// <summary> 子节点. </summary>
    std::vector<cvObject> children;

    XUEXUE_JSON_OBJECT_M3(name, components, children)
  private:
};

void* cvComponent::instance() const
{
    if (type == "cvLine") {
        return new cvLine();
    }

    return nullptr;
}

TEST(Json, cvObject)
{
    std::shared_ptr<cvLine> line = std::make_shared<cvLine>();
    line->type = "cvLine";
    line->color = {21, 123, 32};
    line->pos0 = {123, 321, 4321};
    line->pos1 = {32, 12, 22};

    string text = JsonMapper::toJson(line);

    std::shared_ptr<cvComponent> com = line;
    string text2 = JsonMapper::toJson(com);

    //cvComponent* pcom = &line;
    //string text3 = JsonMapper::toJson(*pcom);

    cvObject obj;
    obj.components.push_back(line);

    text = JsonMapper::toJson(obj);
    cvObject o2 = JsonMapper::toObject<cvObject>(text);
    ASSERT_TRUE(o2.components.size() == obj.components.size());

    cvLine* line2 = static_cast<cvLine*>((o2.components[0]).get());
    ASSERT_TRUE(line->color == line2->color);
    ASSERT_TRUE(line->pos0 == line2->pos0);
    ASSERT_TRUE(line->pos1 == line2->pos1);
    ASSERT_TRUE(line->type == line2->type);
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

    //ASSERT_TRUE(std::memcmp(p1, p2, sizeof(size)) == 0);

    std::string str = "Example string";
    for (size_t i = 0; i < 20; i++) {
        str += str;
    }
    std::istringstream iss;
    std::stringbuf* pbuf = iss.rdbuf();
    pbuf->str(str);
    auto in_avail = pbuf->in_avail();
    std::string text = JsonHelper::readStream(iss);
    ASSERT_TRUE(text == str);
}

TEST(String, istreamToJson)
{
    StringClass sc;
    sc.s1 = "12345678901234567890123456789012345678901234567890123456789012345678901234567890";
    sc.s2 = "123";
    int size = sizeof(sc);
    int size1 = sizeof(sc.s1);
    int size2 = sizeof(sc.s2);

    //ASSERT_TRUE(std::memcmp(p1, p2, sizeof(size)) == 0);

    std::string str = JsonMapper::toJson(sc);
    std::istringstream iss;
    std::stringbuf* pbuf = iss.rdbuf();
    pbuf->str(str);
    int in_avail = pbuf->in_avail();
    StringClass sc2 = JsonMapper::toObject<StringClass>(iss);
    ASSERT_TRUE(sc.s1 == sc2.s1);
    ASSERT_TRUE(sc.s2 == sc2.s2);
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
        ASSERT_TRUE(vStr[i] == vStr2[i]);
    }
}

TEST(String, loadFileNoFile)
{
    //会抛出异常
    ASSERT_THROW(vector<string> vStr2 = JsonMapper::loadFile<vector<string>>("nofile"), invalid_argument);
}

TEST(wstring, toJsonW)
{
    std::vector<std::wstring> vStr;
    vStr.push_back(L"568876❀❀❀");
    vStr.push_back(L"❀❀86786");

    wstring json = JsonMapper::toJsonW(vStr, true);

    vector<wstring> vStr3 = JsonMapper::toObjectW<vector<wstring>>(json);
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_TRUE(vStr[i] == vStr3[i]);
    }
}

TEST(string, toJsonW)
{
    std::vector<std::string> vStr;
    vStr.push_back("568876❀❀❀");
    vStr.push_back("❀❀86786");

    wstring json = JsonMapper::toJsonW(vStr, true);

    vector<string> vStr3 = JsonMapper::toObjectW<vector<string>>(json);
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_TRUE(vStr[i] == vStr3[i]);
    }
}

TEST(string, toJson_ofstream)
{
    std::vector<std::string> vStr;
    vStr.push_back("568❀❀❀876❀❀❀");
    vStr.push_back("86786");
    ofstream ofs("output.json");
    JsonMapper ::toJson(vStr, ofs, true);
    ofs.close();
    vector<string> vStr2 = JsonMapper::loadFile<vector<string>>("output.json");
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_TRUE(vStr[i] == vStr2[i]);
    }
}

TEST(wstring, toJson_ofstream)
{
    std::vector<std::wstring> vStr;
    vStr.push_back(L"568876❀❀❀");
    vStr.push_back(L"❀❀86786");
    ofstream ofs("output2.json");
    JsonMapper::toJson(vStr, ofs, true);
    ofs.close();

    vector<wstring> vStr2 = JsonMapper::loadFile<vector<wstring>>("output2.json");
    for (size_t i = 0; i < vStr.size(); i++) {
        ASSERT_TRUE(vStr[i] == vStr2[i]);
    }
}

/*
TEST(wstring, toJsonW_wofstream)
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
        ASSERT_TRUE(vStr[i] == vStr2[i]);
    }
    //std::locale::global(oPreviousLocale);
}
*/

} // namespace dxtest
#endif