// 知识点总结:
// 1. 本代码演示了继承与异常处理的结合使用。`Sales` 类和其派生类 `LabeledSales` 提供了对销售数据的管理，并支持异常处理。
// 2. 类中使用了自定义异常类 `bad_index` 和 `nbad_index` 来处理数组越界问题。
// 3. 操作符重载被用于访问和修改销售数据，且在越界时抛出异常。

// 注意点:
// 1. `Sales` 类和 `LabeledSales` 类的操作符 `[]` 重载函数必须处理数组越界情况，并且需要根据继承关系调用基类的方法。
// 2. 在捕获异常时，应该确保异常的类型匹配性，并正确输出相关错误信息。
// 3. `Sales` 类中的构造函数需要初始化 `gross` 数组，未提供数据时默认为0。

#include "09_head_Chapter15.h"

int main() {
    double vals1[12] = {1100, 1110,1120,1130,1140,1150,1160,1170,1180,1190,1200,1210}; // 初始化第一个对象的数据
    double vals2[12] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22}; // 初始化第二个对象的数据

    Sales sales1(2011, vals1, 12); // 创建 Sales 对象，使用年份和数据数组
    LabeledSales sales2("dadada", 2012, vals2, 12); // 创建 LabeledSales 对象，带有标签

    try {
        cout << "Year = " << sales1.Year() << endl; // 输出第一个对象的年份
        for (int i = 0; i < 12; ++i) { // 遍历并输出第一个对象的销售数据
            cout << sales1[i] << ' ';
            if (i % 6 == 5) { // 每6个数据换行
                cout << endl;
            }
        }
        cout << "Year = " << sales2.Year() << endl; // 输出第二个对象的年份
        cout << "Label = " << sales2.Label() << endl; // 输出第二个对象的标签
        for (int i = 0; i < 13; ++i) { // 遍历并输出第二个对象的销售数据（故意超出数组范围触发异常）
            cout << sales2[i] << ' ';
            if (i % 6 == 5) { // 每6个数据换行
                cout << endl;
            }
        }
    }
    catch (LabeledSales::nbad_index& bad) { // 捕获并处理 LabeledSales 的数组越界异常
        cout << bad.what(); // 输出异常信息
        cout << "Company: " << bad.label_val() << endl; // 输出相关的公司标签
        cout << "bad index: " << bad.bi_val() << endl; // 输出出错的索引值
    }
    catch (Sales::bad_index& bad) { // 捕获并处理 Sales 的数组越界异常
        cout << bad.what(); // 输出异常信息
        cout << "bad index: " << bad.bi_val() << endl; // 输出出错的索引值
    }
    cout << "----------------Dividing----------------" << endl; // 分割线

    try {
        sales2[2] = 40; // 尝试修改第二个对象的某个销售数据
        sales1[2] = 3333; // 尝试修改第一个对象的某个销售数据
    }
    catch (LabeledSales::nbad_index& bad) { // 捕获并处理 LabeledSales 的数组越界异常
        cout << bad.what(); // 输出异常信息
        cout << "Company: " << bad.label_val() << endl; // 输出相关的公司标签
        cout << "bad index: " << bad.bi_val() << endl; // 输出出错的索引值
    }
    catch (Sales::bad_index& bad) { // 捕获并处理 Sales 的数组越界异常
        cout << bad.what(); // 输出异常信息
        cout << "bad index: " << bad.bi_val() << endl; // 输出出错的索引值
    }
    return 0; // 返回 0 表示程序正常结束
}