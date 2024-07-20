#include "test07_head_Chapter10.h"

/*
 * 构造函数：初始化 name 和 ci
 */
Plorg::Plorg(const char *n, int c) {
    strcpy(name, n); // 初始化 name
    ci = c; // 初始化 ci
}

/*
 * 设置 ci 的值
 */
void Plorg::set_ci(int c) {
    ci = c; // 设置 ci 的值
}

/*
 * 显示 name 和 ci 的值
 */
void Plorg::show() const {
    cout << "name = " << name << endl; // 输出 name 的值
    cout << "ci = " << ci << endl; // 输出 ci 的值
}