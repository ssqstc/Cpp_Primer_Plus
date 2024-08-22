// 头文件部分
#ifndef HEAD_TEST04_CHAPTER15_H
#define HEAD_TEST04_CHAPTER15_H

#include <iostream>  // 标准输入输出流库
#include <stdexcept>  // 标准异常库
#include <string>  // 标准字符串库
using namespace std;

// 基类 Sales，表示某一年的销售数据
class Sales {
public:
    enum {MONTHS = 12};  // 常量，表示每年的月份数量
    explicit Sales(int yy = 0);  // 构造函数
    Sales(int yy, const double* gr, int n);  // 构造函数，接受年份和数据数组
    virtual ~Sales() {}
    int Year() const { return year; }  // 返回年份
    virtual double operator[](int i) const;  // 重载 [] 运算符（常量版本）
    virtual double& operator[](int i);  // 重载 [] 运算符（非常量版本）

    // 异常类 bad_index，继承自 logic_error，用于表示数组越界错误
    class bad_index : public logic_error {
    private:
        int bi;  // 错误的索引值
    public:
        explicit bad_index(int ix, const string& s = "Index error in Sales object\n") : bi(ix), logic_error(s) {}
        int bi_val() const { return bi; }  // 返回错误的索引值
        virtual ~bad_index() throw() {}
    };
private:
    int year;  // 年份
    double gross[MONTHS];  // 每个月的销售数据
};

// 派生类 LabeledSales，表示带有标签的销售数据
class LabeledSales : public Sales {
private:
    string label;  // 销售数据的标签
public:
    explicit LabeledSales(const string& lb = "none", int yy = 0) : Sales(yy), label(lb) {}  // 构造函数
    LabeledSales(const string& lb, int yy, const double* gr, int n) : Sales(yy, gr, n), label(lb) {}
    virtual ~LabeledSales() {}
    const string& Label() const { return label; }  // 返回标签
    virtual double operator[](int i) const;  // 重载 [] 运算符（常量版本）
    virtual double& operator[](int i);  // 重载 [] 运算符（非常量版本）

    // 异常类 nbad_index，继承自 Sales::bad_index，用于表示带标签的数组越界错误
    class nbad_index : public Sales::bad_index {
    private:
        string lbl;  // 标签值
    public:
        nbad_index(const string& lb, int ix, const string& s = "Index error in LabeledSales object\n") : lbl(lb), Sales::bad_index(ix, s) {}
        const string& label_val() const { return lbl; }  // 返回标签值
        virtual ~nbad_index() throw() {}
    };
};

#endif //HEAD_TEST04_CHAPTER15_H