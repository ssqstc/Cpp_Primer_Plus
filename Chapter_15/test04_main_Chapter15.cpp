/*
知识点总结:
1. **继承与多态**：使用基类 `Sales` 和派生类 `LabeledSales`，演示了继承与多态的应用，特别是虚函数的使用。
2. **异常处理机制**：通过自定义异常类 `bad_index` 和 `nbad_index`，并结合 `try-catch` 结构实现对数组越界错误的处理。
3. **运算符重载**：重载了 `[]` 运算符，用于访问和修改类中的数组元素，结合异常处理机制防止越界访问。

注意点:
1. **构造函数的初始化列表**：在 `LabeledSales` 类中，使用初始化列表调用基类构造函数，并对派生类的成员进行初始化。
2. **虚函数的覆盖**：派生类中的 `operator[]` 函数覆盖了基类的同名函数，确保派生类能够根据特定需求进行行为定制。
3. **异常对象的传递与捕获**：确保在捕获异常时，使用适当的机制（如 `dynamic_cast`）来访问派生类特有的成员或函数。
*/

#include "test04_head_Chapter15.h"  // 包含头文件

int main() {
    // 初始化两个销售数据数组
    double vals1[12] = {1100, 1110,1120,1130,1140,1150,1160,1170,1180,1190,1200,1210};
    double vals2[12] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22};

    // 创建 Sales 对象和 LabeledSales 对象
    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("dadada", 2012, vals2, 12);

    try {
        // 输出 sales1 的年份和数据
        cout << "Year = " << sales1.Year() << endl;
        for (int i = 0; i < 12; ++i) {
            cout << sales1[i] << ' ';
            if (i % 6 == 5) {
                cout << endl;
            }
        }
        // 输出 sales2 的年份、标签和数据
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (int i = 0; i < 12; ++i) {
            cout << sales2[i] << ' ';
            if (i % 6 == 5) {
                cout << endl;
            }
        }
    }
    catch (Sales::bad_index& bad) {  // 捕获 bad_index 异常
        if (typeid(LabeledSales::nbad_index) == typeid(bad)) {  // 检查是否为 nbad_index 异常
            cout << bad.what();  // 输出错误信息
            cout << "Company: " << dynamic_cast<LabeledSales::nbad_index&>(bad).label_val() << endl;
            cout << "bad index: " << dynamic_cast<LabeledSales::nbad_index&>(bad).bi_val() << endl;
        } else {  // 处理普通的 bad_index 异常
            cout << bad.what();
            cout << "bad index: " << bad.bi_val() << endl;
        }
    }
    cout << "----------------Dividing----------------" << endl;

    try {
        // 修改 sales2 和 sales1 的部分数据
        sales2[2] = 40;
        sales1[2] = 3333;
    }
    catch (Sales::bad_index& bad) {  // 再次捕获异常
        if (typeid(LabeledSales::nbad_index) == typeid(bad)) {
            cout << bad.what();
            cout << "Company: " << dynamic_cast<LabeledSales::nbad_index&>(bad).label_val() << endl;
            cout << "bad index: " << bad.bi_val() << endl;
        } else {
            cout << bad.what();
            cout << "bad index: " << bad.bi_val() << endl;
        }
    }
    return 0;
}