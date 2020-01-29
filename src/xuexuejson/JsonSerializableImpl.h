#define XUEXUE_JSON_OBJECT_M1(PAR1)                                                                                         \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M2(PAR1, PAR2)                                                                                   \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M3(PAR1, PAR2, PAR3)                                                                             \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M4(PAR1, PAR2, PAR3, PAR4)                                                                       \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M5(PAR1, PAR2, PAR3, PAR4, PAR5)                                                                 \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M6(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6)                                                           \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M7(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7)                                                     \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M8(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8)                                               \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR8)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR8)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M9(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9)                                         \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);        \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);   \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR8)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR9)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                            \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR8)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR9)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                        \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M10(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10)                                 \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);      \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator); \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR8)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR9)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR10)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                          \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR8)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR9)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR10)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                      \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M11(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11)                          \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);      \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator); \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR8)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR9)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR10)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR11)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                          \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR8)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR9)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR10)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR11)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                      \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M12(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12)                   \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);      \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator); \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR8)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR9)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR10)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR11)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR12)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                          \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR8)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR9)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR10)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR11)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR12)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                      \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M13(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13)            \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);      \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator); \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR8)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR9)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR10)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR11)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR12)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR13)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                          \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR8)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR9)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR10)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR11)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR12)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR13)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                      \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M14(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14)     \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const   \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);        \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);      \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);      \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \
    {                                                                                                                       \
        value.SetObject();                                                                                                  \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);   \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator); \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator); \
        return std::move(value);                                                                                            \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::Value& value)                                                                   \
    {                                                                                                                       \
        if (value.HasMember(#PAR1)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR2)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR3)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR4)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR5)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR6)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR7)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR8)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR9)) {                                                                                       \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                            \
        }                                                                                                                   \
        if (value.HasMember(#PAR10)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR11)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR12)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR13)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                          \
        }                                                                                                                   \
        if (value.HasMember(#PAR14)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                          \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                  \
    {                                                                                                                       \
        if (value.HasMember(L## #PAR1)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR2)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR3)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR4)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR5)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR6)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR7)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR8)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR9)) {                                                                                   \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                        \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR10)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR11)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR12)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR13)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                      \
        }                                                                                                                   \
        if (value.HasMember(L## #PAR14)) {                                                                                  \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                      \
        }                                                                                                                   \
    }

#define XUEXUE_JSON_OBJECT_M15(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15) \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const      \
    {                                                                                                                          \
        value.SetObject();                                                                                                     \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);           \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);         \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);         \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);         \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);         \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);         \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);         \
        return std::move(value);                                                                                               \
    }                                                                                                                          \
                                                                                                                               \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const    \
    {                                                                                                                          \
        value.SetObject();                                                                                                     \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);      \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);    \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);    \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);    \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);    \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);    \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);    \
        return std::move(value);                                                                                               \
    }                                                                                                                          \
                                                                                                                               \
    virtual void getObj(const xuexue::json::Value& value)                                                                      \
    {                                                                                                                          \
        if (value.HasMember(#PAR1)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR2)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR3)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR4)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR5)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR6)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR7)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR8)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR9)) {                                                                                          \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                               \
        }                                                                                                                      \
        if (value.HasMember(#PAR10)) {                                                                                         \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                             \
        }                                                                                                                      \
        if (value.HasMember(#PAR11)) {                                                                                         \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                             \
        }                                                                                                                      \
        if (value.HasMember(#PAR12)) {                                                                                         \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                             \
        }                                                                                                                      \
        if (value.HasMember(#PAR13)) {                                                                                         \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                             \
        }                                                                                                                      \
        if (value.HasMember(#PAR14)) {                                                                                         \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                             \
        }                                                                                                                      \
        if (value.HasMember(#PAR15)) {                                                                                         \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                             \
        }                                                                                                                      \
    }                                                                                                                          \
                                                                                                                               \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                     \
    {                                                                                                                          \
        if (value.HasMember(L## #PAR1)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR2)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR3)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR4)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR5)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR6)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR7)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR8)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR9)) {                                                                                      \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                           \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR10)) {                                                                                     \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                         \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR11)) {                                                                                     \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                         \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR12)) {                                                                                     \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                         \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR13)) {                                                                                     \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                         \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR14)) {                                                                                     \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                         \
        }                                                                                                                      \
        if (value.HasMember(L## #PAR15)) {                                                                                     \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                         \
        }                                                                                                                      \
    }

#define XUEXUE_JSON_OBJECT_M16(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16) \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M17(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17)                                                                                                 \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M18(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18)                                                                                          \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M19(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19)                                                                                   \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M20(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20)                                                                            \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M21(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21)                                                                     \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M22(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22)                                                              \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M23(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23)                                                       \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M24(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24)                                                \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR24)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR24)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M25(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25)                                         \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR24)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR25)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR24)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR25)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M26(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25, PAR26)                                  \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR24)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR25)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR26)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR26], PAR26);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR24)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR25)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR26)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR26], PAR26);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M27(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25, PAR26, PAR27)                           \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR24)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR25)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR26)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR26], PAR26);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR27)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR27], PAR27);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR24)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR25)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR26)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR26], PAR26);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR27)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR27], PAR27);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M28(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25, PAR26, PAR27, PAR28)                    \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR24)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR25)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR26)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR26], PAR26);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR27)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR27], PAR27);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR28)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR28], PAR28);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR24)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR25)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR26)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR26], PAR26);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR27)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR27], PAR27);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR28)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR28], PAR28);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M29(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25, PAR26, PAR27, PAR28, PAR29)             \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR24)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR25)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR26)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR26], PAR26);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR27)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR27], PAR27);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR28)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR28], PAR28);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR29)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR29], PAR29);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR24)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR25)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR26)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR26], PAR26);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR27)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR27], PAR27);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR28)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR28], PAR28);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR29)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR29], PAR29);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M30(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16, \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25, PAR26, PAR27, PAR28, PAR29, PAR30)      \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::Value(), allocator), allocator);                \
        value.AddMember(#PAR30, xuexue::json::Serialize::toValue(PAR30, xuexue::json::Value(), allocator), allocator);                \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const           \
    {                                                                                                                                 \
        value.SetObject();                                                                                                            \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::ValueW(), allocator), allocator);           \
        value.AddMember(L## #PAR30, xuexue::json::Serialize::toValue(PAR30, xuexue::json::ValueW(), allocator), allocator);           \
        return std::move(value);                                                                                                      \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::Value& value)                                                                             \
    {                                                                                                                                 \
        if (value.HasMember(#PAR1)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR2)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR3)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR4)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR5)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR6)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR7)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR8)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR9)) {                                                                                                 \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                      \
        }                                                                                                                             \
        if (value.HasMember(#PAR10)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR11)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR12)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR13)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR14)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR15)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR16)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR17)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR18)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR19)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR20)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR21)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR22)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR23)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR24)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR25)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR26)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR26], PAR26);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR27)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR27], PAR27);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR28)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR28], PAR28);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR29)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR29], PAR29);                                                                    \
        }                                                                                                                             \
        if (value.HasMember(#PAR30)) {                                                                                                \
            xuexue::json::Serialize::getObj(value[#PAR30], PAR30);                                                                    \
        }                                                                                                                             \
    }                                                                                                                                 \
                                                                                                                                      \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                            \
    {                                                                                                                                 \
        if (value.HasMember(L## #PAR1)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR2)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR3)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR4)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR5)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR6)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR7)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR8)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR9)) {                                                                                             \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                  \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR10)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR11)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR12)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR13)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR14)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR15)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR16)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR17)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR18)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR19)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR20)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR21)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR22)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR23)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR24)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR25)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR26)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR26], PAR26);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR27)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR27], PAR27);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR28)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR28], PAR28);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR29)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR29], PAR29);                                                                \
        }                                                                                                                             \
        if (value.HasMember(L## #PAR30)) {                                                                                            \
            xuexue::json::Serialize::getObj(value[L## #PAR30], PAR30);                                                                \
        }                                                                                                                             \
    }

#define XUEXUE_JSON_OBJECT_M31(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16,   \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25, PAR26, PAR27, PAR28, PAR29, PAR30, PAR31) \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const               \
    {                                                                                                                                   \
        value.SetObject();                                                                                                              \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR30, xuexue::json::Serialize::toValue(PAR30, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR31, xuexue::json::Serialize::toValue(PAR31, xuexue::json::Value(), allocator), allocator);                  \
        return std::move(value);                                                                                                        \
    }                                                                                                                                   \
                                                                                                                                        \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                   \
        value.SetObject();                                                                                                              \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR30, xuexue::json::Serialize::toValue(PAR30, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR31, xuexue::json::Serialize::toValue(PAR31, xuexue::json::ValueW(), allocator), allocator);             \
        return std::move(value);                                                                                                        \
    }                                                                                                                                   \
                                                                                                                                        \
    virtual void getObj(const xuexue::json::Value& value)                                                                               \
    {                                                                                                                                   \
        if (value.HasMember(#PAR1)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR2)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR3)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR4)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR5)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR6)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR7)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR8)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR9)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR10)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR11)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR12)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR13)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR14)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR15)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR16)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR17)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR18)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR19)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR20)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR21)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR22)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR23)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR24)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR25)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR26)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR26], PAR26);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR27)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR27], PAR27);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR28)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR28], PAR28);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR29)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR29], PAR29);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR30)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR30], PAR30);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR31)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR31], PAR31);                                                                      \
        }                                                                                                                               \
    }                                                                                                                                   \
                                                                                                                                        \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                              \
    {                                                                                                                                   \
        if (value.HasMember(L## #PAR1)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR2)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR3)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR4)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR5)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR6)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR7)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR8)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR9)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR10)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR11)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR12)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR13)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR14)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR15)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR16)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR17)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR18)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR19)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR20)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR21)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR22)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR23)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR24)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR25)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR26)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR26], PAR26);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR27)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR27], PAR27);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR28)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR28], PAR28);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR29)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR29], PAR29);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR30)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR30], PAR30);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR31)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR31], PAR31);                                                                  \
        }                                                                                                                               \
    }

#define XUEXUE_JSON_OBJECT_M32(PAR1, PAR2, PAR3, PAR4, PAR5, PAR6, PAR7, PAR8, PAR9, PAR10, PAR11, PAR12, PAR13, PAR14, PAR15, PAR16,   \
                               PAR17, PAR18, PAR19, PAR20, PAR21, PAR22, PAR23, PAR24, PAR25, PAR26, PAR27, PAR28, PAR29, PAR30, PAR31, \
                               PAR32)                                                                                                   \
    virtual xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const               \
    {                                                                                                                                   \
        value.SetObject();                                                                                                              \
        value.AddMember(#PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::Value(), allocator), allocator);                    \
        value.AddMember(#PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR30, xuexue::json::Serialize::toValue(PAR30, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR31, xuexue::json::Serialize::toValue(PAR31, xuexue::json::Value(), allocator), allocator);                  \
        value.AddMember(#PAR32, xuexue::json::Serialize::toValue(PAR32, xuexue::json::Value(), allocator), allocator);                  \
        return std::move(value);                                                                                                        \
    }                                                                                                                                   \
                                                                                                                                        \
    virtual xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const             \
    {                                                                                                                                   \
        value.SetObject();                                                                                                              \
        value.AddMember(L## #PAR1, xuexue::json::Serialize::toValue(PAR1, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR2, xuexue::json::Serialize::toValue(PAR2, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR3, xuexue::json::Serialize::toValue(PAR3, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR4, xuexue::json::Serialize::toValue(PAR4, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR5, xuexue::json::Serialize::toValue(PAR5, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR6, xuexue::json::Serialize::toValue(PAR6, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR7, xuexue::json::Serialize::toValue(PAR7, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR8, xuexue::json::Serialize::toValue(PAR8, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR9, xuexue::json::Serialize::toValue(PAR9, xuexue::json::ValueW(), allocator), allocator);               \
        value.AddMember(L## #PAR10, xuexue::json::Serialize::toValue(PAR10, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR11, xuexue::json::Serialize::toValue(PAR11, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR12, xuexue::json::Serialize::toValue(PAR12, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR13, xuexue::json::Serialize::toValue(PAR13, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR14, xuexue::json::Serialize::toValue(PAR14, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR15, xuexue::json::Serialize::toValue(PAR15, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR16, xuexue::json::Serialize::toValue(PAR16, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR17, xuexue::json::Serialize::toValue(PAR17, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR18, xuexue::json::Serialize::toValue(PAR18, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR19, xuexue::json::Serialize::toValue(PAR19, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR20, xuexue::json::Serialize::toValue(PAR20, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR21, xuexue::json::Serialize::toValue(PAR21, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR22, xuexue::json::Serialize::toValue(PAR22, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR23, xuexue::json::Serialize::toValue(PAR23, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR24, xuexue::json::Serialize::toValue(PAR24, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR25, xuexue::json::Serialize::toValue(PAR25, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR26, xuexue::json::Serialize::toValue(PAR26, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR27, xuexue::json::Serialize::toValue(PAR27, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR28, xuexue::json::Serialize::toValue(PAR28, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR29, xuexue::json::Serialize::toValue(PAR29, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR30, xuexue::json::Serialize::toValue(PAR30, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR31, xuexue::json::Serialize::toValue(PAR31, xuexue::json::ValueW(), allocator), allocator);             \
        value.AddMember(L## #PAR32, xuexue::json::Serialize::toValue(PAR32, xuexue::json::ValueW(), allocator), allocator);             \
        return std::move(value);                                                                                                        \
    }                                                                                                                                   \
                                                                                                                                        \
    virtual void getObj(const xuexue::json::Value& value)                                                                               \
    {                                                                                                                                   \
        if (value.HasMember(#PAR1)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR1], PAR1);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR2)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR2], PAR2);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR3)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR3], PAR3);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR4)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR4], PAR4);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR5)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR5], PAR5);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR6)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR6], PAR6);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR7)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR7], PAR7);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR8)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR8], PAR8);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR9)) {                                                                                                   \
            xuexue::json::Serialize::getObj(value[#PAR9], PAR9);                                                                        \
        }                                                                                                                               \
        if (value.HasMember(#PAR10)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR10], PAR10);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR11)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR11], PAR11);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR12)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR12], PAR12);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR13)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR13], PAR13);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR14)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR14], PAR14);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR15)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR15], PAR15);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR16)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR16], PAR16);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR17)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR17], PAR17);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR18)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR18], PAR18);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR19)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR19], PAR19);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR20)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR20], PAR20);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR21)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR21], PAR21);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR22)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR22], PAR22);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR23)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR23], PAR23);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR24)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR24], PAR24);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR25)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR25], PAR25);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR26)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR26], PAR26);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR27)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR27], PAR27);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR28)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR28], PAR28);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR29)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR29], PAR29);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR30)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR30], PAR30);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR31)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR31], PAR31);                                                                      \
        }                                                                                                                               \
        if (value.HasMember(#PAR32)) {                                                                                                  \
            xuexue::json::Serialize::getObj(value[#PAR32], PAR32);                                                                      \
        }                                                                                                                               \
    }                                                                                                                                   \
                                                                                                                                        \
    virtual void getObj(const xuexue::json::ValueW& value)                                                                              \
    {                                                                                                                                   \
        if (value.HasMember(L## #PAR1)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR1], PAR1);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR2)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR2], PAR2);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR3)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR3], PAR3);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR4)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR4], PAR4);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR5)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR5], PAR5);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR6)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR6], PAR6);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR7)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR7], PAR7);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR8)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR8], PAR8);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR9)) {                                                                                               \
            xuexue::json::Serialize::getObj(value[L## #PAR9], PAR9);                                                                    \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR10)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR10], PAR10);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR11)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR11], PAR11);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR12)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR12], PAR12);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR13)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR13], PAR13);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR14)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR14], PAR14);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR15)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR15], PAR15);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR16)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR16], PAR16);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR17)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR17], PAR17);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR18)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR18], PAR18);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR19)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR19], PAR19);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR20)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR20], PAR20);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR21)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR21], PAR21);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR22)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR22], PAR22);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR23)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR23], PAR23);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR24)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR24], PAR24);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR25)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR25], PAR25);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR26)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR26], PAR26);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR27)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR27], PAR27);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR28)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR28], PAR28);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR29)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR29], PAR29);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR30)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR30], PAR30);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR31)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR31], PAR31);                                                                  \
        }                                                                                                                               \
        if (value.HasMember(L## #PAR32)) {                                                                                              \
            xuexue::json::Serialize::getObj(value[L## #PAR32], PAR32);                                                                  \
        }                                                                                                                               \
    }
