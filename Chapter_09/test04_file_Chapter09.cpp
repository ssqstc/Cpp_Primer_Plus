#include "iostream"
#include "test04_head_Chapter09.h"
using namespace std;

namespace SALES {
    void setSales(Sales &s, const double ar[], int n) {
        s.max = ar[0]; // 初始化最大值
        s.min = ar[0]; // 初始化最小值
        double total = 0; // 初始化总和
        for (int i = 0; i < n && i < 4; ++i) {
            s.sales[i] = ar[i]; // 设置销售数据
            total += ar[i]; // 累加总和
            s.max = (ar[i] > s.max) ? ar[i] : s.max; // 更新最大值
            s.min = (ar[i] < s.min) ? ar[i] : s.min; // 更新最小值
        }
        s.average = total / n; // 计算平均值

        if (n < 4) {
            for (int i = n; i < 4; ++i) {
                s.sales[i] = 0; // 填充剩余元素为 0
            }
        }
    }

    void setSales(Sales &s) {
        double total = 0;
        cout << "Enter 4 sales quarters:" << endl; // 提示输入四个季度的销售数据
        for (int i = 0; i < QUARTERA; ++i) {
            cout << "# " << i + 1 << ": ";
            cin >> s.sales[i]; // 读取用户输入的销售数据
            total += s.sales[i]; // 累加总和

            if (0 == i) {
                s.max = s.sales[i]; // 初始化最大值
                s.min = s.sales[i]; // 初始化最小值
            } else {
                s.max = (s.sales[i] > s.max) ? s.sales[i] : s.max; // 更新最大值
                s.min = (s.sales[i] < s.min) ? s.sales[i] : s.min; // 更新最小值
            }
        }
        s.average = total / QUARTERA; // 计算平均值
    }

    void showSales(const Sales &s) {
        int n = sizeof(s.sales) / sizeof(s.sales[0]); // 计算销售数据数组的元素数量
        for (int i = 0; i < n; ++i) {
            cout << "# " << i + 1 << ": sales = " << s.sales[i] << endl; // 显示每个季度的销售数据
        }
        cout << "max = " << s.max << endl; // 显示最大值
        cout << "min = " << s.min << endl; // 显示最小值
        cout << "average = " << s.average << endl; // 显示平均值
    }
}