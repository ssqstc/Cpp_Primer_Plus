#include "test03_head_Chapter13.h"

// ABC 类构造函数: 动态分配内存用于存储标签字符串并初始化评分
ABC::ABC(const char *label, int rating) {
    m_label = new char[strlen(label) + 1];
    strcpy(m_label, label);
    m_rating = rating;
}

// ABC 类复制构造函数: 深拷贝 m_label 字符串并复制评分
ABC::ABC(const ABC &abc) {
    m_label = new char[strlen(abc.m_label) + 1];
    strcpy(m_label, abc.m_label);
    m_rating = abc.m_rating;
}

// ABC 类析构函数: 释放动态分配的 m_label 内存
ABC::~ABC() {
    delete []m_label;
}

// ABC 类赋值运算符重载: 防止自赋值并实现深拷贝
ABC &ABC::operator=(const ABC &abc) {
    if (this == &abc)
        return *this;
    delete []m_label;
    m_label = new char[strlen(abc.m_label) + 1];
    strcpy(m_label, abc.m_label);
    m_rating = abc.m_rating;
    return *this;
}

// baseDMA 类 view 函数: 显示标签和评分
void baseDMA::view() const {
    cout << "Label: " << ABC::label() << endl;
    cout << "Rating: " << ABC::rating() << endl;
}

// lacksDMA 类构造函数: 初始化 m_color 并调用基类构造函数
lacksDMA::lacksDMA(const char *label, int rating, const char *color) : ABC(label, rating) {
    strncpy(m_color, color, COL_LEN - 1);
    m_color[COL_LEN - 1] = '\0';
}

// lacksDMA 类基于基类对象的构造函数: 使用基类对象初始化
lacksDMA::lacksDMA(const ABC &abc, const char *color) : ABC(abc) {
    strncpy(m_color, color, COL_LEN - 1);
    m_color[COL_LEN - 1] = '\0';
}

// lacksDMA 类赋值运算符重载: 调用基类赋值运算符并复制颜色
lacksDMA &lacksDMA::operator=(const lacksDMA &lacksDma) {
    if (this == &lacksDma)
        return *this;
    ABC::operator=(lacksDma);
    strcpy(m_color, lacksDma.m_color);
    return *this;
}

// lacksDMA 类 view 函数: 显示标签、评分和颜色
void lacksDMA::view() const {
    cout << "Label: " << ABC::label() << endl;
    cout << "Rating: " << ABC::rating() << endl;
    cout << "Color: " << m_color << endl;
}

// hasDMA 类构造函数: 动态分配内存用于存储风格字符串并调用基类构造函数
hasDMA::hasDMA(const char *label, int rating, const char *style) : ABC(label, rating) {
    m_style = new char[strlen(style) + 1];
    strcpy(m_style, style);
}

// hasDMA 类基于基类对象的构造函数: 使用基类对象初始化
hasDMA::hasDMA(const ABC &abc, const char *style) : ABC(abc) {
    m_style = new char[strlen(style) + 1];
    strcpy(m_style, style);
}

// hasDMA 类复制构造函数: 实现深拷贝，确保新对象有独立的 m_style 内存空间
hasDMA::hasDMA(const hasDMA &hasDma) : ABC(hasDma) {
    m_style = new char[strlen(hasDma.m_style) + 1];
    strcpy(m_style, hasDma.m_style);
}

// hasDMA 类析构函数: 释放 m_style 动态分配的内存
hasDMA::~hasDMA() {
    delete []m_style;
}

// hasDMA 类赋值运算符重载: 实现深拷贝并防止自赋值
hasDMA &hasDMA::operator=(const hasDMA &hasDma) {
    if (this == &hasDma)
        return *this;
    ABC::operator=(hasDma);
    delete []m_style;
    m_style = new char[strlen(hasDma.m_style) + 1];
    strcpy(m_style, hasDma.m_style);
    return *this;
}

// hasDMA 类 view 函数: 显示标签、评分和风格
void hasDMA::view() const {
    cout << "Label: " << ABC::label() << endl;
    cout << "Rating: " << ABC::rating() << endl;
    cout << "Style: " << m_style << endl;
}