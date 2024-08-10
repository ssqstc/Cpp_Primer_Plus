#include "05_head_Chapter13.h"

// baseDMA类的构造函数
baseDMA::baseDMA(const char *label, int rating) {
    m_label = new char[strlen(label) + 1]; // 分配动态内存用于存储label
    strcpy(m_label, label); // 复制label到成员变量
    m_rating = rating; // 初始化rating
}

// baseDMA类的复制构造函数
baseDMA::baseDMA(const baseDMA &baseDma) {
    m_label = new char[strlen(baseDma.m_label) + 1]; // 分配新的内存用于复制label
    strcpy(m_label, baseDma.m_label); // 复制label
    m_rating = baseDma.m_rating; // 复制rating
}

// baseDMA类的析构函数
baseDMA::~baseDMA() {
    delete []m_label; // 释放动态分配的内存
}

// baseDMA类的赋值运算符重载
baseDMA &baseDMA::operator=(const baseDMA &baseDma) {
    if (this == &baseDma)
        return *this;
    delete []m_label; // 释放已有的内存
    m_label = new char[strlen(baseDma.m_label) + 1]; // 分配新的内存并复制label
    strcpy(m_label, baseDma.m_label);
    m_rating = baseDma.m_rating; // 复制rating
    return *this;
}

// baseDMA类的输出运算符重载
ostream &operator<<(ostream &os, const baseDMA &baseDma) {
    os << "Label: " << baseDma.m_label << endl; // 输出label
    os << "Rating: " << baseDma.m_rating << endl; // 输出rating
    return os;
}

// lacksDMA类的构造函数，初始化baseDMA部分并处理color
lacksDMA::lacksDMA(const char *label, int rating, const char *color) : baseDMA(label, rating) {
    strncpy(m_color, color, COL_LEN - 1); // 复制color，确保不会溢出
    m_color[COL_LEN - 1] = '\0'; // 确保以null结尾
}

// lacksDMA类的复制构造函数，调用基类的复制构造函数并处理color
lacksDMA::lacksDMA(const baseDMA &baseDma, const char *color) : baseDMA(baseDma) {
    strncpy(m_color, color, COL_LEN - 1); // 复制color，确保不会溢出
    m_color[COL_LEN - 1] = '\0'; // 确保以null结尾
}

// lacksDMA类的输出运算符重载
ostream &operator<<(ostream &os, const lacksDMA &lacksDma) {
    os << (const baseDMA &)lacksDma; // 调用基类的输出运算符
    os << "Color: " << lacksDma.m_color << endl; // 输出color
    return os;
}

// hasDMA类的构造函数，初始化baseDMA部分并处理style
hasDMA::hasDMA(const char *label, int rating, const char *style) : baseDMA(label, rating) {
    m_style = new char[strlen(style) + 1]; // 分配动态内存用于存储style
    strcpy(m_style, style); // 复制style
}

// hasDMA类的复制构造函数，调用基类的复制构造函数并处理style
hasDMA::hasDMA(const baseDMA &baseDma, const char *style) : baseDMA(baseDma) {
    m_style = new char[strlen(style) + 1]; // 分配新的内存用于复制style
    strcpy(m_style, style); // 复制style
}

// hasDMA类的复制构造函数，处理深拷贝
hasDMA::hasDMA(const hasDMA &hasDma) : baseDMA(hasDma) {
    cout << "Copy construct function." << endl; // 输出调试信息
    m_style = new char[strlen(hasDma.m_style) + 1]; // 分配新的内存并复制style
    strcpy(m_style, hasDma.m_style);
}

// hasDMA类的析构函数
hasDMA::~hasDMA() {
    delete []m_style; // 释放动态分配的内存
}

// hasDMA类的赋值运算符重载
hasDMA &hasDMA::operator=(const hasDMA &hasDma) {
    cout << "operator function." << endl; // 输出调试信息
    if (this == &hasDma)
        return *this;
    baseDMA::operator=(hasDma); // 调用基类的赋值运算符
    delete []m_style; // 释放已有的内存
    m_style = new char[strlen(hasDma.m_style) + 1]; // 分配新的内存并复制style
    strcpy(m_style, hasDma.m_style);
    return *this;
}

// hasDMA类的输出运算符重载
ostream &operator<<(ostream &os, const hasDMA &hasDma) {
    os << (baseDMA &)hasDma; // 调用基类的输出运算符
    os << "Style: " << hasDma.m_style; // 输出style
    return os;
}