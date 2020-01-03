# xuexuejson
使用rapidjson的高性能封装，纯头文件。
使用两个宏定义即可以实现对象转到json的支持，同时支持对象的嵌套，十分有爱。
``` cpp
//支持opencv和eigen中的一些类型
#define XUEXUE_JSON_SUPPORT_OPENCV
#define XUEXUE_JSON_SUPPORT_EIGEN
#include "xuexuejson/Serialize.hpp"

//下面这个类使用两个宏定义XUEXUE_JSON_OBJECT和XUEXUE_JSON_OBJECT_M4即实现所有的json转换支持。其中XUEXUE_JSON_OBJECT_M4代表后面的成员个数是4个。

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

test(){
    CalibParamDto obj;
    //上面的CalibParamDto已经支持了json转换方法,直接转换即可
    std::string text = JsonMapper::toJson(obj, true);
    CalibParamDto obj2;
    JsonMapper::toObject(text, obj2);
}
```
