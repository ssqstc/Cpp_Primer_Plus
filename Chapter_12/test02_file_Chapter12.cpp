#include "test02_head_Chapter12.h"

// 默认构造函数，初始化成员变量
String::String() {
    m_str = new char[1];  // 分配一个字符的空间
    m_str[0] = '\0';  // 设置为空字符串
    m_len = 0;  // 初始化长度为0
}

// 带参数的构造函数
String::String(const char *a_ch) {
    m_len = strlen(a_ch);  // 获取字符串长度
    m_str = new char[m_len + 1];  // 分配对应长度的空间
    strcpy(m_str, a_ch);  // 复制字符串
}

// 拷贝构造函数
String::String(const String &a_st) {
    m_len = strlen(a_st.m_str);  // 获取字符串长度
    m_str = new char[m_len + 1];  // 分配对应长度的空间
    strcpy(m_str, a_st.m_str);  // 复制字符串
}

// 析构函数，释放动态分配的内存
String::~String() {
    delete[] m_str;
}

// 赋值运算符重载
String &String::operator=(const String &a_st) {
    if (this == &a_st)
        return *this;  // 自赋值检查
    delete[] m_str;  // 释放原来的内存
    m_len = strlen(a_st.m_str);  // 获取新字符串的长度
    m_str = new char[m_len + 1];  // 分配新内存
    strcpy(m_str, a_st.m_str);  // 复制字符串
    return *this;
}

// 字符串赋值运算符重载
String &String::operator=(const char *a_ch) {
    delete[] m_str;  // 释放原来的内存
    m_len = strlen(a_ch);  // 获取新字符串的长度
    m_str = new char[m_len + 1];  // 分配新内存
    strcpy(m_str, a_ch);  // 复制字符串
    return *this;
}

// 提取运算符重载，用于输入字符串
istream &operator>>(istream &a_is, String &a_st) {
    char temp[String::CINLIMIT];
    a_is.get(temp, String::CINLIMIT);  // 获取输入字符串
    if (a_is)
        a_st = temp;  // 将输入字符串赋值给对象
    while (a_is && a_is.get() != '\n');  // 清空输入缓冲区
    return a_is;
}

// 比较运算符重载，用于比较字符串
bool operator==(const String &a_st1, const String &a_st2) {
    return (strcmp(a_st1.m_str, a_st2.m_str) == 0);  // 比较字符串
}

// 插入运算符重载，用于输出字符串
ostream &operator<<(ostream &a_os, const String &a_st) {
    a_os << a_st.m_str;
    return a_os;
}

// 加法运算符重载，用于连接字符串
String operator+(const char *a_ch, const String &a_st) {
    String temp;
    temp.m_len = strlen(a_ch) + a_st.m_len;  // 计算新字符串长度
    temp.m_str = new char[temp.m_len + 1];  // 分配新内存
    strcpy(temp.m_str, a_ch);  // 复制第一个字符串
    strcat(temp.m_str, a_st.m_str);  // 连接第二个字符串
    return temp;
}

// 加法运算符重载，用于连接字符串
String String::operator+(const String &a_st) const {
    String temp;
    temp.m_len = m_len + a_st.m_len;  // 计算新字符串长度
    temp.m_str = new char[temp.m_len + 1];  // 分配新内存
    strcpy(temp.m_str, m_str);  // 复制第一个字符串
    strcat(temp.m_str, a_st.m_str);  // 连接第二个字符串
    return temp;
}

// 将字符串转换为小写
void String::stringLow() {
    for (int i = 0; i < m_len; ++i) {
        m_str[i] = tolower(m_str[i]);
    }
}

// 将字符串转换为大写
void String::stringUp() {
    for (int i = 0; i < m_len; ++i) {
        m_str[i] = toupper(m_str[i]);
    }
}

// 统计字符串中某个字符的个数
int String::has(const char a_n) const {
    int count = 0;
    for (int i = 0; i < m_len; ++i) {
        if (m_str[i] == a_n)
            count++;
    }
    return count;
}
