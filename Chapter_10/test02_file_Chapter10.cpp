#include "test02_head_Chapter10.h"

/*
 * 带参数的构造函数
 * 初始化姓和名
 * ln - 姓
 * fn - 名，默认为 "Heyyou"
 */
Person::Person(const std::string &ln, const char *fn) {
    lname = ln; // 初始化姓
    strcpy(fname, fn); // 将名复制到 fname 数组中
}

/*
 * 显示姓名信息
 * const 成员函数，保证不修改对象的状态
 */
void Person::show() const {
    if (lname == "" && fname[0] == '\0'){ // 如果没有姓名信息
        cout << "No name: " << endl; // 输出 "No name"
    } else{
        cout << "Person name: " << fname << " " << lname << endl; // 输出姓名
    }
}

/*
 * 正式显示姓名信息
 * const 成员函数，保证不修改对象的状态
 */
void Person::FormalShow() const {
    if (lname == "" && fname[0] == '\0'){ // 如果没有姓名信息
        cout << "No name: " << endl; // 输出 "No name"
    } else{
        cout << "Person name: " << lname << ", " << fname << endl; // 输出姓名
    }
}