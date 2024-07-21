#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 常量：使用`const`定义常量，提高代码可读性和维护性。
 * - 基本算术运算：包括乘法和除法操作。
 * - BMI计算：将身高从英尺英寸转换为米，体重从磅转换为公斤，然后计算BMI。
 *
 * 注意点：
 * - 输入输出的格式和提示信息：确保用户能够正确理解和输入数据。
 * - 常量定义：使用`const`而不是`#define`来定义常量，以便更好地类型检查。
 * - 数据类型选择：使用`float`和`double`来处理小数计算。
 */

/*
 * 主函数：将用户输入的身高（英尺和英寸）和体重（磅）转换为米和公斤，并计算BMI值
 */
int main()
{
    const int FOOT_TO_INCH = 12; // 常量，1英尺等于12英寸
    const float INCH_TO_METER = 0.0254; // 常量，1英寸等于0.0254米
    const float POUND_TO_KILOGRAM = 2.2; // 常量，1磅等于2.2公斤

    float height_foot, height_inch, weight_pound; // 用户输入的身高（英尺和英寸）和体重（磅）

    // 提示用户输入身高（英尺和英寸）以及体重（磅）
    cout << "身高多少英尺_";
    cin >> height_foot;
    cout << "多少英寸_";
    cin >> height_inch;
    cout << "体重多少磅_";
    cin >> weight_pound;

    // 将身高从英尺英寸转换为米，将体重从磅转换为公斤
    double meter = (height_foot * FOOT_TO_INCH + height_inch) * INCH_TO_METER;
    double kilogram = weight_pound / POUND_TO_KILOGRAM;

    // 计算并输出BMI值
    double bmi = kilogram / (meter * meter);
    cout << "你的BMI是：" << bmi;

    return 0;
}
