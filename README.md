# xuexuejson :snowflake:

[![Build status](https://daixian.visualstudio.com/Pipeline/_apis/build/status/Pipeline-xuexuejson)](https://daixian.visualstudio.com/Pipeline/_build/latest?definitionId=12)

## 简介

使用rapidjson的高性能封装，纯头文件，支持msvc，gcc，clang。这个库是纯头文件库，全部一起丢到自己的工程里即可。
代码中只需要引入JsonMapper.hpp一个头文件。
在dto对象声明时使用简单的**两个宏定义**即可以实现dto对象转到json的支持，同时支持对象的嵌套，可以很方便的实现一些dto对象的序列化反序列化，十分有爱。

## 使用

如果定义了XUEXUE_JSON_SUPPORT_OPENCV和XUEXUE_JSON_SUPPORT_EIGEN就会直接支持一些opencv和eigen里的常用对象。
有几个需要注意的：

* 对象必须要有一个默认构造函数。
* 对象的成员基本是以map的形式。
* 在反序列化的时候如果成员用到继承那么需要使用智能指针，详见JsonTest.cpp里的实现方法。
* **成员如果是字符串需要使用std::string，没有支持char***。
* 目前对枚举类型的支持是直接转换成int。

``` cpp
#define XUEXUE_JSON_SUPPORT_OPENCV
#define XUEXUE_JSON_SUPPORT_EIGEN
//上面这两个定义，支持opencv和eigen中的一些类型，不用可以去掉
#include "xuexuejson/JsonMapper.hpp"

// 下面这个类使用两个宏定义: XUEXUE_JSON_OBJECT和XUEXUE_JSON_OBJECT_M4
// 即可自动实现支持对象和json相互转换。
// 其中XUEXUE_JSON_OBJECT_M4的数字4代表后面的成员个数是4个。这个宏定义实际上是自动完成了几个接口函数。

//传递相机标定参数的dto
class CalibParamDto : XUEXUE_JSON_OBJECT
{
  public:
    //注意必须要有一个默认构造函数
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

    //obj<->json,将你需要参与json序列化的成员写到括号里面.
    XUEXUE_JSON_OBJECT_M4(method, params, imageListA, imageListB)
  private:
};

Test(){
    CalibParamDto obj;
    //上面的CalibParamDto已经支持了json转换方法,直接转换即可
    std::string text = JsonMapper::toJson(obj, true);// obj -> json

    CalibParamDto obj2;
    JsonMapper::toObject(text, obj2); // json -> obj
}
```

另外由于rapidjson中使用的max和windows定义中的冲突警告，在使用windows.h头文件之前可以试试加一个宏定义去掉windows头文件里的定义。

``` cpp
#ifndef NOMINMAX
#    define NOMINMAX
#endif
#include <windows.h>
```

## 扩展
目前我增加了Eigen和OpenCV中相关的序列化方法的扩展。如果需要对自己经常使用的库增加自定义的扩展方法，在xuexuejson/extension/文件夹中加入自己的方法。
**在SerializeMerge.hpp的对应位置引用自己的序列化方法即可轻松扩展，但注意不要随意调整头文件的顺序**。
``` cpp
/**************************  这里补充所有的特殊扩展序列化方法 **************************/
//默认定义支持这些大库里的类型，如果不需要则注销掉这两行
#ifdef OPENCV_CORE_HPP
#    define XUEXUE_JSON_SUPPORT_OPENCV
#endif
#ifdef EIGEN_GEOMETRY_MODULE_H
#    define XUEXUE_JSON_SUPPORT_EIGEN
#endif

#ifdef XUEXUE_JSON_SUPPORT_EIGEN
#    include "extension/SerializeEigen.hpp"
#endif

#ifdef XUEXUE_JSON_SUPPORT_OPENCV
#    include "extension/SerializeOpenCV.hpp"
#endif

//这个不需要依赖库所以可以直接打开
#include "extension/SerializeUnity3D.hpp"

//在此处加入你自己的扩展代码文件....

/**********************************************************************************/
```
## 构建

这个库是纯头文件库，依赖rapidjson库。*另外这个库自豪的使用了conan构建工具。*

## License

This project is licensed under [GLWTPL](https://github.com/me-shaon/GLWTPL)