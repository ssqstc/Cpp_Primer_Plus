#include "iostream"
using namespace std;

const double KILOMETER_TO_MILE = 62.14; // 千米转英里常量
const double GALLON_TO_LITER = 3.875; // 加仑转升常量

/*
 * 知识点总结：
 * - 常量的使用：使用`const`关键字定义常量，以提高代码的可读性和可维护性。
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 算术运算：计算每100公里的油耗和每加仑的行驶里程。
 *
 * 注意点：
 * - 保证输入数据的准确性。
 * - 输出结果时的小数精度控制，可以使用`<iomanip>`库中的`setprecision`函数。
 */

/*
 * 主函数：计算每100公里的油耗和每加仑的行驶里程
 */
int main()
{
    double kilometer, liter; // 驱车里程和使用油量

    cout << "输入驱车里程（公里）："; // 提示用户输入驱车里程
    cin >> kilometer;

    cout << "输入使用油量（升）："; // 提示用户输入使用油量
    cin >> liter;

    // 计算并输出每100公里的油耗（升）
    cout << "每100公里耗油" << liter / kilometer * 100 << "升。" << endl; // 输出每100公里耗油

    // 计算并输出每加仑的行驶里程（英里）
    cout << "耗油一加仑里程" << kilometer / 100 * KILOMETER_TO_MILE / GALLON_TO_LITER / liter << " 英里。" << endl; // 输出每加仑行驶里程

    return 0;
}
