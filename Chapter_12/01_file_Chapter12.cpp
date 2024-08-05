#include "01_head_Chapter12.h"
#include "cstring"

int StringBad::num_strings = 0;  // 静态成员变量初始化

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    strcpy(str, "C++");  // 动态分配内存并复制字符串
    num_strings++;
}

StringBad::StringBad(const char *s) {
    len = strlen(s);  // 计算字符串长度
    str = new char[len + 1];  // 动态分配内存并复制字符串
    strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << ".\"" << endl;  // 输出创建对象的信息
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted." << endl;  // 输出删除对象的信息
    --num_strings;
    cout << num_strings << " left." << endl;  // 输出剩余对象的数量
    delete []str;  // 释放动态分配的内存
}

StringBad::StringBad(const StringBad &st) {
    len = st.len;
    str = new char[len + 1];  // 动态分配内存并复制字符串
    strcpy(str, st.str);
    num_strings++;
    cout << num_strings << ": \"" << str << ".\"" << endl;  // 输出复制对象的信息
}

StringBad &StringBad::operator=(const StringBad &st) {
    if (this == &st) {
        return *this;  // 自我赋值检查
    }
    delete []str;  // 释放旧的内存
    len = st.len;
    str = new char[len + 1];  // 动态分配新的内存并复制字符串
    strcpy(str, st.str);
    return *this;
}

ostream &operator<<(ostream &os, const StringBad &st) {
    os << st.str;  // 输出字符串内容
    return os;
}