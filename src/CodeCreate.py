#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
'''
生成代码
'''
import os
import sys
import io
import time

basedir = os.path.abspath(os.path.dirname(__file__))
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')


def creatOneFun1(count: int):
    head = "#define XUEXUE_JSON_OBJECT_M%d(" % count
    for index in range(0, count):
        head += ("PAR%d,") % (index+1)
        if(index >= 15 and index % 15 == 0 and index != count-1):
            head += "\\\n"
    head = head[:-1]  # 去掉最后一个逗号
    head += ")  \\\n   xuexue::json::Value&& toValue(xuexue::json::Value&& value, rapidjson::MemoryPoolAllocator<>& allocator) const {value.SetObject();"
    cur = ""
    for index in range(0, count):
        cur += (" value.AddMember(#PAR%d, xuexue::json::Serialize::toValue( PAR%d , xuexue::json::Value(), allocator), allocator); \\\n") % (index+1, index+1)

    end = " return std::move(value); } \\\n\\\n"
    item = head + cur + end
    print(item)
    return item


def creatOneFun2(count: int):
    head = "xuexue::json::ValueW&& toValue(xuexue::json::ValueW&& value, rapidjson::MemoryPoolAllocator<>& allocator) const \\\n {value.SetObject();"
    cur = ""
    for index in range(0, count):
        cur += (" value.AddMember(L## #PAR%d, xuexue::json::Serialize::toValue( PAR%d , xuexue::json::ValueW(), allocator), allocator); \\\n") % (index+1, index+1)

    end = " return std::move(value); } \\\n\\\n"
    item = head + cur + end
    print(item)
    return item


def creatOneFun3(count: int):
    head = "void getObj(const xuexue::json::Value& value){\\\n"
    cur = ""
    for index in range(0, count):
        cur += ("if(value.HasMember(#PAR%d)){xuexue::json::Serialize::getObj(value[#PAR%d], PAR%d);} \\\n") % (
            index+1, index+1, index+1)
    end = " }\\\n\\\n"
    item = head + cur + end
    print(item)
    return item


def creatOneFun4(count: int):
    head = "void getObj(const xuexue::json::ValueW& value){\\\n"
    cur = ""
    for index in range(0, count):
        cur += ("if(value.HasMember(L## #PAR%d)){xuexue::json::Serialize::getObj(value[L## #PAR%d], PAR%d ); } \\\n") % (
            index+1, index+1, index+1)
    end = " }\\\n \n\n"
    item = head + cur + end
    print(item)
    return item


fh = open(basedir+"/code.cpp", 'w')
for count in range(1, 33):
    fh.write(creatOneFun1(count))
    fh.write(creatOneFun2(count))
    fh.write(creatOneFun3(count))
    fh.write(creatOneFun4(count))
fh.close()
