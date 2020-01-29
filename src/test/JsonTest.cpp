#include "gtest/gtest.h"
#define XUEXUE_JSON_SUPPORT_OPENCV
#define XUEXUE_JSON_SUPPORT_EIGEN
#include "../xuexuejson/Serialize.hpp"
#include "Poco/Format.h"
#include <thread>
#include <boost/format.hpp>

#pragma execution_character_set("utf-8")

using namespace xuexue::json;
using namespace std;
using namespace rapidjson;

//传递相机标定参数的dto
class CalibParamDto : XUEXUE_JSON_OBJECT
{
  public:
    CalibParamDto() {}
    ~CalibParamDto() {}

    //标定使用的方法
    std::string method;

    //标定的参数列表
    std::map<std::string, std::string> params;

    //标定使用的图片路径列表
    std::vector<std::string> imageListA;

    //标定使用的图片路径列表
    std::vector<std::string> imageListB;

    //obj<->json
    XUEXUE_JSON_OBJECT_M4(method, params, imageListA, imageListB)
  private:
};

// 代表一个相机属性的Dto
class CameraDto : XUEXUE_JSON_OBJECT
{
  public:
    CameraDto() {}
    ~CameraDto() {}

    /// <summary> 相机的逻辑编号0-3，它代表一个编程逻辑上的编号，不是相机的设备index. </summary>
    int camIndex = -2;

    /// <summary> 这个相机的设备名. </summary>
    std::wstring devName;

    /// <summary> 相机的分辨率size. </summary>
    cv::Size size;

    XUEXUE_JSON_OBJECT_M3(camIndex, devName, size)
  private:
};

namespace dxtest {

//数据准备类,但是准备数据的耗时也会被记录运行时间里面
class DtoTestData : public testing::Test
{
  protected:
    virtual void SetUp()
    {
        CalibParamDto obj;
        obj.method = "sim";
        for (size_t i = 0; i < 100; i++) {
            obj.imageListA.push_back(Poco::format("one item %z", i));
        }
        obj.params["param1"] = "1";
        obj.params["param2"] = "2";
        obj.params["param3"] = "3";

        for (size_t i = 0; i < 500; i++) {
            vCalibParamDto.push_back(obj);
        }

        CameraDto cdto;
        cdto.camIndex = 123;
        cdto.devName = L"这是一个相机名字";
        cdto.size = cv::Size(123, 231);
        for (size_t i = 0; i < 100; i++) {
            vCameraDto.push_back(cdto);
        }
    }
    virtual void TearDown()
    {
    }

  public:
    vector<CalibParamDto> vCalibParamDto;

    vector<CameraDto> vCameraDto;
};

TEST_F(DtoTestData, DtoTestData_CostTime)
{
    vector<CalibParamDto>& vObj = vCalibParamDto;
}

TEST_F(DtoTestData, DtoTestData_SaveFile)
{
    auto doc = JsonHelper::creatEmptyObjectDoc();
    auto& allocator = doc.GetAllocator();

    vector<CalibParamDto>& vObj = vCalibParamDto;
    doc.AddMember("vec", Serialize::toValue(vObj, Value(kNullType), allocator), allocator);
    JsonHelper::save("CalibParamDtoVector.json", doc);
}

TEST_F(DtoTestData, CalibParamDtoVector)
{
    auto doc = JsonHelper::creatEmptyObjectDoc();
    auto& allocator = doc.GetAllocator();

    vector<CalibParamDto>& vObj = vCalibParamDto;
    doc.AddMember("vec", Serialize::toValue(vObj, Value(kNullType), allocator), allocator);

    string text = JsonHelper::toJson(doc, false);

    Document doc2;
    JsonHelper::toDocument(text, doc2);

    vector<CalibParamDto> vObj2;
    Serialize::getObj(doc2["vec"], vObj2);

    ASSERT_TRUE(vObj2.size() == vObj.size());
    for (size_t i = 0; i < vObj.size(); i++) {
        EXPECT_TRUE(vObj[i].method == vObj2[i].method);
        EXPECT_TRUE(vObj[i].imageListA.size() == vObj2[i].imageListA.size());
        EXPECT_TRUE(vObj[i].params.size() == vObj2[i].params.size());
    }
}

TEST_F(DtoTestData, CalibParamDtoVectorW)
{
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();

    vector<CalibParamDto> vObj = vCalibParamDto;

    doc.AddMember(L"vec", Serialize::toValue(vObj, ValueW(kNullType), allocator), allocator);

    wstring text = JsonHelper::toJsonW(doc, false);

    DocumentW doc2;
    JsonHelper::toDocumentW(text, doc2);

    vector<CalibParamDto> vObj2;
    Serialize::getObj(doc2[L"vec"], vObj2);

    ASSERT_TRUE(vObj2.size() == vObj.size());
    for (size_t i = 0; i < vObj.size(); i++) {
        EXPECT_TRUE(vObj[i].method == vObj2[i].method);
        EXPECT_TRUE(vObj[i].imageListA.size() == vObj2[i].imageListA.size());
        EXPECT_TRUE(vObj[i].params.size() == vObj2[i].params.size());
    }

    //std::wofstream osWrite("CalibParamDtoVector.json", std::wofstream::app);
    //osWrite << text;
    //osWrite << std::endl;
    //osWrite.close();
}

TEST(DtoTest, CalibParamDtoList)
{
    auto doc = JsonHelper::creatEmptyObjectDocW();
    auto& allocator = doc.GetAllocator();

    CalibParamDto obj;
    obj.method = "sim";
    for (size_t i = 0; i < 10; i++) {
        obj.imageListA.push_back(Poco::format("one item %z", i));
    }
    obj.params["param1"] = "1";
    obj.params["param2"] = "2";

    list<CalibParamDto> vObj;
    for (size_t i = 0; i < 10; i++) {
        vObj.push_back(obj);
    }
    doc.AddMember(L"list", Serialize::toValue(vObj, ValueW(kNullType), allocator), allocator);

    wstring text = JsonHelper::toJsonW(doc, true);
    DocumentW doc2;
    JsonHelper::toDocumentW(text, doc2);

    vector<CalibParamDto> vObj2;
    Serialize::getObj(doc2[L"list"], vObj2);

    ASSERT_TRUE(vObj2.size() == vObj.size());
    auto it1 = vObj.begin();
    auto it2 = vObj2.begin();
    while (it1 != vObj.end()) {
        EXPECT_TRUE(it1->method == it2->method);
        EXPECT_TRUE(it1->imageListA.size() == it2->imageListA.size());
        EXPECT_TRUE(it1->params.size() == it2->params.size());
        ++it1;
        ++it2;
    }
}

TEST_F(DtoTestData, CameraDto)
{
    CameraDto& obj = vCameraDto[0];
    string text = JsonMapper::toJson(obj, true);

    CameraDto obj2;
    JsonMapper::toObject(text, obj2);

    EXPECT_TRUE(obj2.camIndex == obj.camIndex);
    EXPECT_TRUE(obj2.devName == obj.devName);
    EXPECT_TRUE(obj2.size == obj.size);
}

TEST_F(DtoTestData, CameraDtoW)
{
    CameraDto& obj = vCameraDto[0];
    wstring text = JsonMapper::toJsonW(obj, true);

    CameraDto obj2;
    JsonMapper::toObjectW(text, obj2);

    EXPECT_TRUE(obj2.camIndex == obj.camIndex);
    EXPECT_TRUE(obj2.devName == obj.devName);
    EXPECT_TRUE(obj2.size == obj.size);
}

TEST_F(DtoTestData, vCameraDto)
{
    auto& obj = vCameraDto;
    string text = JsonMapper::toJson(obj, true);

    vector<CameraDto> obj2 = JsonMapper::toObject<vector<CameraDto>>(text);

    for (size_t i = 0; i < obj.size(); i++) {
        EXPECT_TRUE(obj2[i].camIndex == obj[i].camIndex);
        EXPECT_TRUE(obj2[i].devName == obj[i].devName);
        EXPECT_TRUE(obj2[i].size == obj[i].size);
    }
    JsonHelper::save("vCameraDto.json", text);
}

TEST(Json, cvMat_double)
{
    cv::Mat m;
    m = (cv::Mat_<double>(4, 4) << 1, 0, 0, 0,
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
    double* m_p = m.ptr<double>();
    double* m2_p = m2.ptr<double>();

    for (size_t i = 0; i < m.cols * m.rows; i++) {
        ASSERT_TRUE(m_p[i] == m2_p[i]);
    }
}

TEST(Json, cvMat_short)
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
TEST(Json, cvMat_float)
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

TEST(Json, vector_cvMat)
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

class ClassA : XUEXUE_JSON_OBJECT
{
  public:
    ClassA() {}
    ~ClassA() {}

    Eigen::Vector3d v0;
    cv::Vec3d v1;

    XUEXUE_JSON_OBJECT_M2(v0, v1);

  private:
};

class ClassB : XUEXUE_JSON_OBJECT
{
  public:
    ClassB() {}
    ~ClassB() {}

    string str;
    unsigned char uc;
    char c;
    unsigned short usi;
    short si;
    unsigned int ui;
    int i;
    uint64_t uli;
    int64_t li;
    ClassA oa;

    XUEXUE_JSON_OBJECT_M10(str, uc, c, usi, si, ui, i, uli, li, oa);

  private:
};

TEST(Json, classNest)
{
    ClassB ob;
    ob.str = "12312是是";
    ob.uc = UCHAR_MAX;
    ob.c = CHAR_MIN;
    ob.usi = USHRT_MAX;
    ob.si = SHRT_MIN;
    ob.ui = UINT_MAX;
    ob.i = INT_MIN;
    ob.uli = ULONG_MAX;
    ob.li = LONG_MIN;

    ob.oa.v0 = Eigen::Vector3d(123, 3123543, 53456);
    ob.oa.v1 = cv::Vec3d(345, 321, 76);

    string text = JsonMapper::toJson(ob);
    ClassB ob2 = JsonMapper::toObject<ClassB>(text);
    ASSERT_TRUE(ob.str == ob2.str);
    ASSERT_TRUE(ob.uc == ob2.uc);
    ASSERT_TRUE(ob.c == ob2.c);
    ASSERT_TRUE(ob.usi == ob2.usi);
    ASSERT_TRUE(ob.si == ob2.si);
    ASSERT_TRUE(ob.ui == ob2.ui);
    ASSERT_TRUE(ob.i == ob2.i);
    ASSERT_TRUE(ob.uli == ob2.uli);
    ASSERT_TRUE(ob.li == ob2.li);

    ASSERT_TRUE(ob.oa.v0 == ob2.oa.v0);
    ASSERT_TRUE(ob.oa.v1 == ob2.oa.v1);
}

TEST(Json, cvPoint)
{
    cv::Point o(123, 321);
    string text = JsonMapper::toJson(o);
    cv::Point o2 = JsonMapper::toObject<cv::Point>(text);
    ASSERT_TRUE(o.x == o2.x);
    ASSERT_TRUE(o.y == o2.y);
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

} // namespace dxtest