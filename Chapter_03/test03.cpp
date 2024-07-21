#include <iostream>
using namespace std;

#define DEGREES_TO_MINUTE 60 // 定义常量，1度等于60分
#define MINUTE_TO_SECOND 60 // 定义常量，1分等于60秒

/*
 * 知识点总结：
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 常量：使用`#define`定义常量，提高代码可读性和维护性。
 * - 类型转换：将整数转换为双精度浮点数，以进行准确的浮点运算。
 * - 算术运算：将角度的度、分、秒转换为度的小数表示。
 *
 * 注意点：
 * - 输入输出的格式和提示信息：确保用户能够正确理解和输入数据。
 * - 类型转换：在进行浮点运算时确保正确的类型转换，以避免精度丢失。
 */

/*
 * 主函数：将用户输入的经度（度、分、秒）转换为十进制度表示
 */
int main()
{
    int degrees, minute, second; // 用户输入的经度（度、分、秒）

    // 提示用户输入经度的度、分、秒
    cout << "Enter a latitude in degrees, minutes, and seconds:\n"; // 提示用户输入经度的度、分、秒

    // 提示并输入度数
    cout << "First, enter the degrees:"; // 提示输入度数
    cin >> degrees;

    // 提示并输入分数
    cout << "Next, enter the minutes of arc:"; // 提示输入分数
    cin >> minute;

    // 提示并输入秒数
    cout << "Finally, enter the seconds of arc:"; // 提示输入秒数
    cin >> second;

    // 计算并输出十进制度表示
    cout << degrees << " degrees, " << minute << " minutes, " << second << " seconds = "
         << (double)second / MINUTE_TO_SECOND / DEGREES_TO_MINUTE + (double)minute / DEGREES_TO_MINUTE + (double)degrees << " degrees";

    return 0;
}
