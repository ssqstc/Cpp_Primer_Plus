#include "02_head_Chapter12.h"
#include "cstring"

int String::num_strings = 0;  // 静态成员变量初始化
int String::howMany() { return num_strings; }  // 返回当前 String 对象数量

String::String() {
    len = 0;
    str = new char[1];
    str[0] = '\0';  // 初始化为空字符串
    num_strings++;
}

String::String(const char *s) {
    len = strlen(s);  // 计算字符串长度
    str = new char[len + 1];  // 动态分配内存
    strcpy(str, s);  // 复制字符串
    num_strings++;
}

String::String(const String &st) {
    len = st.len;
    str = new char[len + 1];  // 动态分配内存
    strcpy(str, st.str);  // 复制字符串
    num_strings++;
}

String::~String() {
    --num_strings;
    delete []str;  // 释放动态分配的内存
}

String &String::operator=(const String &st) {
    if (&st == this) {
        return *this;  // 检查自我赋值
    }
    delete []str;  // 释放旧内存
    len = st.len;
    str = new char[len + 1];  // 动态分配新内存
    strcpy(str, st.str);  // 复制字符串
    return *this;
}

String &String::operator=(const char *ch) {
    delete []str;  // 释放旧内存
    len = strlen(ch);
    str = new char[len + 1];  // 动态分配新内存
    strcpy(str, ch);  // 复制字符串
    return *this;
}

char &String::operator[](int i) {
    return str[i];  // 返回字符引用
}

const char &String::operator[](int i) const {
    return str[i];  // 返回字符常量引用
}

bool operator<(const String &str1, const String &str2) {
    return (strcmp(str1.str, str2.str) < 0);  // 比较字符串
}

bool operator>(const String &str1, const String &str2) {
    return str2 < str1;  // 使用 < 运算符重载实现 > 运算符
}

bool operator==(const String &str1, const String &str2) {
    return (strcmp(str1.str, str2.str) == 0);  // 比较字符串是否相等
}

ostream &operator<<(ostream &os, const String &st) {
    os << st.str;  // 输出字符串内容
    return os;
}

istream &operator>>(istream &is, String &st) {
    char temp[String::CINLIM];  // 临时存储输入的字符串
    is.get(temp, String::CINLIM);  // 读取字符串
    if (is) {
        st = temp;  // 将输入字符串赋值给 st
    }
    while (is && is.get() != '\n');  // 清空输入缓冲区
    return is;
}