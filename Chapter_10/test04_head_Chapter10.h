#ifndef __TEST04_HEAD_CHAPTER10_H__
#define __TEST04_HEAD_CHAPTER10_H__
#include "iostream"

namespace SALES {
    /*
     * Sales 类定义
     * 模拟销售数据的统计和显示
     */
    class Sales{
    private:
        static const int QUARTERA = 4; // 季度数量
        struct sales {
            double sales[QUARTERA]; // 销售数据数组
            double average; // 平均值
            double max; // 最大值
            double min; // 最小值
        };
        sales info{}; // sales 结构体实例
    public:
        Sales(); // 默认构造函数
        Sales(const double ar[], int n); // 带参数的构造函数
        void showSales() const; // 显示销售数据
    };
}

#endif //__TEST04_HEAD_CHAPTER10_H__