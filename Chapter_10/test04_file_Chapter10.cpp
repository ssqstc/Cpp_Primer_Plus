#include "test04_head_Chapter10.h"
using namespace std;

namespace SALES {
    /*
     * 带参数的构造函数
     * 初始化销售数据，并计算最大值、最小值和平均值
     * ar - 销售数据数组
     * n - 数据个数
     */
    Sales::Sales(const double ar[], int n) {
        info.max = ar[0]; // 初始化最大值
        info.min = ar[0]; // 初始化最小值
        double total = 0; // 总和初始化为0
        for (int i = 0; i < n && i < QUARTERA; ++i) {
            info.sales[i] = ar[i]; // 复制销售数据
            total += ar[i]; // 累加总和
            info.max = (ar[i] > info.max) ? ar[i] : info.max; // 更新最大值
            info.min = (ar[i] < info.min) ? ar[i] : info.min; // 更新最小值
        }
        info.average = total / n; // 计算平均值
        if (n < QUARTERA) {
            for (int i = n; i < QUARTERA; ++i) {
                info.sales[i] = 0; // 填充剩余元素为0
            }
        }
    }

    /*
     * 默认构造函数
     * 提示用户输入四个季度的销售数据，并计算最大值、最小值和平均值
     */
    Sales::Sales() {
        double total = 0; // 总和初始化为0
        cout << "Enter 4 sales quarters:" << endl; // 提示用户输入销售数据
        for (int i = 0; i < QUARTERA; ++i) {
            cout << "# " << i + 1 << ": ";
            cin >> info.sales[i]; // 读取用户输入的销售数据
            total += info.sales[i]; // 累加总和

            if (0 == i) {
                info.max = info.sales[i]; // 初始化最大值
                info.min = info.sales[i]; // 初始化最小值
            } else {
                info.max = (info.sales[i] > info.max) ? info.sales[i] : info.max; // 更新最大值
                info.min = (info.sales[i] < info.min) ? info.sales[i] : info.min; // 更新最小值
            }
        }
        info.average = total / QUARTERA; // 计算平均值
    }

    /*
     * 显示销售数据
     * const 成员函数，保证不修改对象的状态
     */
    void Sales::showSales() const {
        int n = sizeof(info.sales) / sizeof(info.sales[0]); // 计算销售数据数组的大小
        for (int i = 0; i < n; ++i) {
            cout << "# " << i + 1 << ": sales = " << info.sales[i] << endl; // 输出每个季度的销售数据
        }
        cout << "max = " << info.max << endl; // 输出最大值
        cout << "min = " << info.min << endl; // 输出最小值
        cout << "average = " << info.average << endl; // 输出平均值
    }
}