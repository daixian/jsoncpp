#pragma once

#include "../SerializeBase.hpp"

namespace xuexue {
namespace json {

//Unity3D中的类型,因为这个扩展是声明类型的同时包含序列化方法,所以加个unity3d的命名空间
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