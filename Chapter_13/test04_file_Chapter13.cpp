#include "test04_head_Chapter13.h"

// Port 类的构造函数，初始化 brand（品牌）、style（类型）和 bottles（瓶数）
Port::Port(const char *br, const char *st, int b) {
    brand = new char [strlen(br) + 1]; // 为品牌名称动态分配内存
    strcpy(brand, br); // 将品牌名称复制到 brand
    strncpy(style, st, 20); // 将类型复制到 style，最多复制 20 个字符
    if (strlen(st) >= 20)
        style[19] = '\0'; // 如果类型字符串长度超过 20，确保最后一个字符是 '\0'
    else
        style[strlen(st)] = '\0'; // 否则，手动添加 '\0' 以结束字符串
    bottles = b; // 初始化瓶数
}

// Port 类的复制构造函数，用于创建 Port 对象的副本
Port::Port(const Port &p) {
    brand = new char [strlen(p.brand) + 1]; // 为新对象的品牌名称动态分配内存
    strcpy(brand, p.brand); // 复制品牌名称
    strcpy(style, p.style); // 复制类型
    bottles = p.bottles; // 复制瓶数
}

// Port 类的赋值操作符重载，确保对象之间的深拷贝
Port &Port::operator=(const Port &p) {
    if (this == &p) // 检查自赋值
        return *this;
    delete []brand; // 释放原有的内存
    brand = new char [strlen(p.brand) + 1]; // 为新对象的品牌名称重新分配内存
    strcpy(brand, p.brand); // 复制品牌名称
    strcpy(style, p.style); // 复制类型
    bottles = p.bottles; // 复制瓶数
    return *this;
}

// 增加瓶数的操作符重载
Port &Port::operator+=(int b) {
    bottles += b; // 增加瓶数
    return *this;
}

// 减少瓶数的操作符重载，确保瓶数不会低于 0
Port &Port::operator-=(int b) {
    if (b > bottles) { // 如果减少的数量大于现有的瓶数
        cout << "Error!"; // 输出错误信息
        return *this;
    }
    bottles -= b; // 减少瓶数
    return *this;
}

// 显示 Port 对象信息的函数
void Port::show() const {
    cout << "Brand: " << brand << endl; // 输出品牌
    cout << "Kind: " << style << endl; // 输出类型
    cout << "Bottles: " << bottles << endl; // 输出瓶数
}

// 重载 << 操作符，方便输出 Port 对象信息
ostream &operator<<(ostream & os, const Port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles; // 输出品牌、类型和瓶数
    return os;
}

// VintagePort 类的默认构造函数，初始化为默认值
VintagePort::VintagePort() : Port() {
    nickname = nullptr; // 初始化昵称为 nullptr
    year = 0; // 初始化年份为 0
}

// VintagePort 类的构造函数，初始化所有成员变量
VintagePort::VintagePort(const char *br, const char *st, int b, const char *nn, int y) : Port(br, st, b) {
    nickname = new char [strlen(nn) + 1]; // 为昵称动态分配内存
    strcpy(nickname, nn); // 复制昵称
    year = y; // 初始化年份
}

// VintagePort 类的复制构造函数，用于创建 VintagePort 对象的副本
VintagePort::VintagePort(const VintagePort &vp) : Port(vp) {
    nickname = new char [strlen(vp.nickname) + 1]; // 为新对象的昵称动态分配内存
    strcpy(nickname, vp.nickname); // 复制昵称
    year = vp.year; // 复制年份
}

// VintagePort 类的赋值操作符重载，确保对象之间的深拷贝
VintagePort &VintagePort::operator=(const VintagePort &vp) {
    if (this == &vp) // 检查自赋值
        return *this;
    Port::operator=(vp); // 调用基类的赋值操作符重载
    delete []nickname; // 释放原有的内存
    nickname = new char [strlen(vp.nickname) + 1]; // 为新对象的昵称重新分配内存
    strcpy(nickname, vp.nickname); // 复制昵称
    year = vp.year; // 复制年份
    return *this;
}

// 显示 VintagePort 对象信息的函数
void VintagePort::show() const {
    Port::show(); // 调用基类的 show() 函数
    cout << "nickname: " << nickname << endl; // 输出昵称
    cout << "year: " << year << endl; // 输出年份
}

// 重载 << 操作符，方便输出 VintagePort 对象信息
ostream & operator<<(ostream & os, const VintagePort & vp) {
    os << (Port &)vp; // 调用基类的 << 操作符重载
    os << ", " << vp.nickname << ", " << vp.year << endl; // 输出昵称和年份
    return os;
}