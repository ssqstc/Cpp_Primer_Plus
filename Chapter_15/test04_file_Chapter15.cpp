// 源文件部分
#include "test04_head_Chapter15.h"

// Sales 类的构造函数，实现年份初始化和销售数据的默认值设置
Sales::Sales(int yy) {
    year = yy;
    for (int i = 0; i < MONTHS; ++i) {
        gross[i] = 0;  // 将每个月的销售数据初始化为0
    }
}

// Sales 类的构造函数，实现年份和销售数据的初始化
Sales::Sales(int yy, const double* gr, int n) {
    year = yy;
    int limit = n < MONTHS ? n : MONTHS;  // 限制数据复制的最大数量为12个月
    int i;
    for (i = 0; i < n; ++i) {
        gross[i] = gr[i];  // 复制传入的销售数据
    }
    for (; i < MONTHS; i++) {
        gross[i] = 0;  // 对剩余的月份数据初始化为0
    }
}

// 非常量版本的 operator[]，用于访问和修改销售数据
double& Sales::operator[](int i) {
    if (i < 0 || i >= MONTHS) {  // 检查索引是否越界
        throw bad_index(i);  // 抛出 bad_index 异常
    }
    return gross[i];
}

// 常量版本的 operator[]，用于只读访问销售数据
double Sales::operator[](int i) const {
    if (i < 0 || i >= MONTHS) {  // 检查索引是否越界
        throw bad_index(i);  // 抛出 bad_index 异常
    }
    return gross[i];
}

// LabeledSales 类的非常量版本 operator[]，用于访问和修改销售数据
double& LabeledSales::operator[](int i) {
    if (i < 0 || i >= MONTHS) {  // 检查索引是否越界
        throw nbad_index(Label(), i);  // 抛出 nbad_index 异常，并传递标签
    }
    return Sales::operator[](i);  // 调用基类的 operator[] 函数
}

// LabeledSales 类的常量版本 operator[]，用于只读访问销售数据
double LabeledSales::operator[](int i) const {
    if (i < 0 || i >= MONTHS) {  // 检查索引是否越界
        throw nbad_index(Label(), i);  // 抛出 nbad_index 异常，并传递标签
    }
    return Sales::operator[](i);  // 调用基类的 operator[] 函数
}