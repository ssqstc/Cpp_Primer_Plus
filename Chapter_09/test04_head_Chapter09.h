#ifndef __TEST04_HEAD_CHAPTER09_H__
#define __TEST04_HEAD_CHAPTER09_H__

namespace SALES {
    const int QUARTERA = 4; // 常量：四个季度
    struct Sales {
        double sales[QUARTERA]; // 销售数据数组
        double average; // 平均值
        double max; // 最大值
        double min; // 最小值
    };
    void setSales(Sales &s, const double ar[], int n); // 设置销售数据（带参数）

    void setSales(Sales &s); // 设置销售数据（用户输入）

    void showSales(const Sales &s); // 显示销售数据
}

#endif //__TEST04_HEAD_CHAPTER09_H__