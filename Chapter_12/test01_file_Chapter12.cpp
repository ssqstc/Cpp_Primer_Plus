#include "test01_head_Chapter12.h"

// 默认构造函数，初始化成员变量
Cow::Cow() {
    m_name[0] = '\0';  // 初始化名称为空字符串
    m_hobby = nullptr;  // 初始化爱好为null指针
    m_weight = 0.0;  // 初始化体重为0.0
}

// 带参数的构造函数
Cow::Cow(const char *a_name, const char *a_hobby, double a_weight) {
    strncpy(m_name, a_name, 20);  // 复制名称
    if (strlen(a_name) >= 20)
        m_name[19] = '\0';  // 确保名称不越界
    m_hobby = new char [strlen(a_hobby) + 1];  // 动态分配爱好字符串的内存
    strcpy(m_hobby, a_hobby);  // 复制爱好字符串
    m_weight = a_weight;  // 设置体重
}

// 拷贝构造函数
Cow::Cow(const Cow &a_cow) {
    strcpy(m_name, a_cow.m_name);  // 复制名称
    m_hobby = new char [strlen(a_cow.m_hobby) + 1];  // 动态分配爱好字符串的内存
    strcpy(m_hobby, a_cow.m_hobby);  // 复制爱好字符串
    m_weight = a_cow.m_weight;  // 复制体重
}

// 析构函数，释放动态分配的内存
Cow::~Cow() {
    delete[] m_hobby;
}

// 赋值运算符重载
Cow &Cow::operator=(const Cow &a_cow) {
    if (&a_cow == this) {
        return *this;  // 自赋值检查
    }
    delete[] m_hobby;  // 释放原来的内存
    strcpy(m_name, a_cow.m_name);  // 复制名称
    m_hobby = new char [strlen(a_cow.m_hobby) + 1];  // 动态分配新内存
    strcpy(m_hobby, a_cow.m_hobby);  // 复制爱好字符串
    m_weight = a_cow.m_weight;  // 复制体重
    return *this;
}

// 显示Cow对象的信息
void Cow::showCow() const {
    cout << "name = " << m_name << ", hobby = " << m_hobby << ", weight = " << m_weight << endl;
}