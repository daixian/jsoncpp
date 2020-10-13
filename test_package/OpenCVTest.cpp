#include "gtest/gtest.h"

// 目前别的平台没有编译opencv
#if defined(_WIN32__FALSE)

#    define XUEXUE_JSON_SUPPORT_OPENCV
#    include "xuexuejson/Serialize.hpp"

#    pragma execution_character_set("utf-8")

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

    ASSERT_EQ(vObj2.size(), vObj.size());
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

    ASSERT_EQ(vObj2.size(), vObj.size());
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

    ASSERT_EQ(vObj2.size(), vObj.size());
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
    ASSERT_EQ(m2.cols, m.cols);
    ASSERT_EQ(m2.rows, m.rows);
    ASSERT_EQ(m2.type(), m.type());
    double* m_p = m.ptr<double>();
    double* m2_p = m2.ptr<double>();

    for (size_t i = 0; i < m.cols * m.rows; i++) {
        ASSERT_EQ(m_p[i], m2_p[i]);
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
    ASSERT_EQ(m2.cols, m.cols);
    ASSERT_EQ(m2.rows, m.rows);
    ASSERT_EQ(m2.type(), m.type());
    short* m_p = m.ptr<short>();
    short* m2_p = m2.ptr<short>();

    for (size_t i = 0; i < m.cols * m.rows; i++) {
        ASSERT_EQ(m_p[i], m2_p[i]);
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
    ASSERT_EQ(m2.cols, m.cols);
    ASSERT_EQ(m2.rows, m.rows);
    ASSERT_EQ(m2.type(), m.type());
    float* m_p = m.ptr<float>();
    float* m2_p = m2.ptr<float>();

    for (size_t i = 0; i < m.cols * m.rows; i++) {
        ASSERT_EQ(m_p[i], m2_p[i]);
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
    ASSERT_EQ(vm.size(), vm2.size());
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
            ASSERT_EQ(item, *it2);
            ASSERT_EQ(item, *it3);
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
            ASSERT_EQ(arr[i], arr2[i]);
            ASSERT_EQ(arr[i], arr3[i]);
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
            ASSERT_EQ(data.vs[i], data2.vs[i]);
        }
        for (size_t i = 0; i < data.vvs.size(); i++) {
            ASSERT_EQ(data.vvs[i], data2.vvs[i]);
        }
        for (size_t i = 0; i < data.vvvs.size(); i++) {
            ASSERT_EQ(data.vvvs[i], data2.vvvs[i]);
        }
    }
}

TEST(Json, EmptyTest)
{
    vector<string> vs;
    string texe = JsonMapper::toJson(vs, false);
    ASSERT_EQ(texe, "[]");
    vector<string> vs2 = JsonMapper::toObject<vector<string>>(texe);
    ASSERT_EQ(vs2.size(), 0);

    map<int, string> mis;
    texe = JsonMapper::toJson(mis, true);
    ASSERT_EQ(texe, "{}");
    map<int, string> mis2 = JsonMapper::toObject<map<int, string>>(texe);
    ASSERT_EQ(mis2.size(), 0);

    map<int, string> mis3 = JsonMapper::toObject<map<int, string>>("");
    ASSERT_EQ(mis3.size(), 0);

    map<int, string> mis4 = JsonMapper::toObject<map<int, string>>("21312");
    ASSERT_EQ(mis4.size(), 0);

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
        ASSERT_EQ((std::to_string(vs2[i]), vs[i]));
    }

    texe = JsonMapper::toJson("true", false);
    bool b = false;
    b = JsonMapper::toObject<bool>(texe);
    ASSERT_EQ(b, true);

    texe = JsonMapper::toJson("false", false);
    b = JsonMapper::toObject<bool>(texe);
    ASSERT_EQ(b, false);
}

TEST(Json, cvPoint)
{
    cv::Point o(123, 321);
    string text = JsonMapper::toJson(o);
    cv::Point o2 = JsonMapper::toObject<cv::Point>(text);
    ASSERT_EQ(o, o2);
}

TEST(Json, cvPoint3)
{
    cv::Point3i o(123, 321, 312413);
    string text = JsonMapper::toJson(o);
    cv::Point3i o2 = JsonMapper::toObject<cv::Point3i>(text);
    ASSERT_EQ(o, o2);
}

TEST(Json, cvRect)
{
    cv::Rect o(123, 321, 252, 54353);
    string text = JsonMapper::toJson(o);
    cv::Rect o2 = JsonMapper::toObject<cv::Rect>(text);
    ASSERT_EQ(o, o2);
}

} // namespace dxtest

#endif
