#include "09_head_Chapter15.h"

// Sales 类构造函数，初始化年份，并将所有销售数据设为 0
Sales::Sales(int yy) {
    year = yy;
    for (int i = 0; i < MONTHS; ++i) {
        gross[i] = 0;
    }
}

// Sales 类构造函数，初始化年份和销售数据，未提供数据的月份设为 0
Sales::Sales(int yy, const double* gr, int n) {
    year = yy;
    int limit = n < MONTHS ? n : MONTHS; // 确定要初始化的月份数
    int i;
    for (i = 0; i < n; ++i) { // 将提供的数据拷贝到 gross 数组
        gross[i] = gr[i];
    }
    for (; i < MONTHS; i++) { // 将剩余月份的数据设为 0
        gross[i] = 0;
    }
}

// 重载操作符，用于获取指定月份的销售数据（可写），并处理越界
double& Sales::operator[](int i) {
    if (i < 0 || i >= MONTHS) { // 检查索引是否越界
        throw bad_index(i); // 抛出异常
    }
    return gross[i]; // 返回指定月份的数据
}

// 重载操作符，用于获取指定月份的销售数据（只读），并处理越界
double Sales::operator[](int i) const {
    if (i < 0 || i >= MONTHS) {// 检查索引是否越界
        throw bad_index(i); // 抛出异常
    }
    return gross[i]; // 返回指定月份的数据
}

// 重载操作符，用于获取 LabeledSales 对象的指定月份的销售数据（可写），并处理越界
double& LabeledSales::operator[](int i) {
    if (i < 0 || i >= MONTHS) { // 检查索引是否越界
        throw nbad_index(Label(),i); // 抛出异常，并包含标签信息
    }
    return Sales::operator[](i); // 调用基类的操作符重载函数
}

// 重载操作符，用于获取 LabeledSales 对象的指定月份的销售数据（只读），并处理越界
double LabeledSales::operator[](int i) const {
    if (i < 0 || i >= MONTHS) { // 检查索引是否越界
        throw nbad_index(Label(),i); // 抛出异常，并包含标签信息
    }
    return Sales::operator[](i); // 调用基类的操作符重载函数
}