#include "test02_head_Chapter13.h"

// Cd类的默认构造函数
Cd::Cd() {
    m_performers = nullptr; // 初始化指针为空，避免悬空指针
    m_label = nullptr;
    m_selections = 0;
    m_playtime = 0.0;
}

// Cd类的参数构造函数
Cd::Cd(char *s1, char *s2, int n, double x) {
    m_performers = new char[strlen(s1) + 1]; // 分配内存并复制字符串
    strcpy(m_performers, s1);
    m_label = new char[strlen(s2) + 1];
    strcpy(m_label, s2);
    m_selections = n; // 复制选择数量
    m_playtime = x; // 复制播放时间
}

// Cd类的拷贝构造函数
Cd::Cd(const Cd &d) {
    m_performers = new char[strlen(d.m_performers) + 1]; // 深拷贝指针成员
    strcpy(m_performers, d.m_performers);
    m_label = new char[strlen(d.m_label) + 1];
    strcpy(m_label, d.m_label);
    m_selections = d.m_selections; // 复制其他成员变量
    m_playtime = d.m_playtime;
}

// Cd类的析构函数
Cd::~Cd() {
    delete []m_performers; // 释放动态分配的内存
    delete []m_label;
}

// Cd类的赋值运算符重载
Cd &Cd::operator=(const Cd &d) {
    if (this == &d)
        return *this; // 防止自我赋值
    delete []m_performers; // 释放已有的内存，防止内存泄漏
    delete []m_label;
    m_performers = new char[strlen(d.m_performers) + 1]; // 深拷贝指针成员
    strcpy(m_performers, d.m_performers);
    m_label = new char[strlen(d.m_label) + 1];
    strcpy(m_label, d.m_label);
    m_selections = d.m_selections; // 复制其他成员变量
    m_playtime = d.m_playtime;
    return *this;
}

// Cd类的report函数，用于输出对象信息
void Cd::report() const {
    cout << "performers: " << m_performers << endl; // 输出表演者信息
    cout << "label: " << m_label << endl; // 输出标签信息
    cout << "selections: " << m_selections << endl; // 输出选择数量
    cout << "playtime: " << m_playtime << endl; // 输出播放时间
}

// Classic类的默认构造函数
Classic::Classic() : Cd() {
    m_str = nullptr; // 初始化指针为空，避免悬空指针
}

// Classic类的参数构造函数
Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : Cd(s2, s3, n, x) {
    m_str = new char[strlen(s1) + 1]; // 分配内存并复制字符串
    strcpy(m_str, s1);
}

// Classic类的拷贝构造函数
Classic::Classic(const Classic &classic) : Cd(classic) {
    m_str = new char[strlen(classic.m_str) + 1]; // 深拷贝指针成员
    strcpy(m_str, classic.m_str);
}

// Classic类的析构函数
Classic::~Classic() {
    delete []m_str; // 释放动态分配的内存
}

// Classic类的赋值运算符重载
Classic &Classic::operator=(const Classic &classic) {
    if (this == &classic)
        return *this; // 防止自我赋值
    Cd::operator=(classic); // 调用基类的赋值运算符
    delete []m_str; // 释放已有的内存，防止内存泄漏
    m_str = new char[strlen(classic.m_str) + 1]; // 深拷贝指针成员
    strcpy(m_str, classic.m_str);
    return *this;
}

// Classic类的report函数，覆盖基类的report函数
void Classic::report() const {
    cout << "str: " << m_str << endl; // 输出特有的字符串信息
    Cd::report(); // 调用基类的report函数输出其余信息
}