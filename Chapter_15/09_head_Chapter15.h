#ifndef HEAD_09_CHAPTER15_H
#define HEAD_09_CHAPTER15_H

#include <iostream> // 包含输入输出流库
#include <stdexcept> // 包含标准异常库
#include <string> // 包含字符串类
using namespace std;

// Sales 类定义，用于管理某年的销售数据
class Sales {
public:
    enum {MONTHS = 12}; // 定义常量，表示一年的月份数
    explicit Sales(int yy = 0); // 构造函数，初始化年份和销售数据
    Sales(int yy, const double* gr, int n); // 构造函数，初始化年份和指定的销售数据
    virtual ~Sales() {} // 虚析构函数
    int Year() const { return year; } // 返回年份
    virtual double operator[](int i) const; // 重载操作符，用于获取指定月份的销售数据（只读）
    virtual double& operator[](int i); // 重载操作符，用于获取指定月份的销售数据（可写）

    // 定义异常类 bad_index 处理 Sales 类的数组越界
    class bad_index : public logic_error {
    private:
        int bi; // 存储发生错误的索引值
    public:
        explicit bad_index(int ix, const string& s = "Index error in Sales object\n") : bi(ix), logic_error(s) {} // 构造函数
        int bi_val() const { return bi; } // 返回错误的索引值
        virtual ~bad_index() throw() {} // 虚析构函数
    };
private:
    int year; // 存储年份
    double gross[MONTHS]; // 存储每月的销售数据
};

// LabeledSales 类继承自 Sales 类，增加了标签属性
class LabeledSales : public Sales {
private:
    string label; // 存储标签
public:
    explicit LabeledSales(const string& lb = "none", int yy = 0) : Sales(yy), label(lb) {} // 构造函数，初始化标签和年份
    LabeledSales(const string& lb, int yy, const double* gr, int n) : Sales(yy, gr, n), label(lb) {} // 构造函数，初始化标签、年份和销售数据
    virtual ~LabeledSales() {} // 虚析构函数
    const string& Label() const { return label; } // 返回标签
    virtual double operator[](int i) const; // 重载操作符，用于获取指定月份的销售数据（只读）
    virtual double& operator[](int i); // 重载操作符，用于获取指定月份的销售数据（可写）

    // 定义异常类 nbad_index 处理 LabeledSales 类的数组越界
    class nbad_index : public Sales::bad_index {
    private:
        string lbl; // 存储发生错误的标签
    public:
        nbad_index(const string& lb, int ix, const string& s = "Index error in LabeledSales object\n") : lbl(lb), Sales::bad_index(ix, s) {} // 构造函数
        const string& label_val() const { return lbl; } // 返回错误的标签
        virtual ~nbad_index() throw() {} // 虚析构函数
    };
};

#endif //HEAD_09_CHAPTER15_H