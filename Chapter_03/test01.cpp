#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 常量：使用`const`定义常量，提高代码可读性和维护性。
 * - 基本算术运算：简单的除法操作。
 *
 * 注意点：
 * - 输入输出的格式和提示信息：确保用户能够正确理解和输入数据。
 * - 常量定义：使用`const`而不是`#define`来定义常量，以便更好地类型检查。
 */

/*
 * 主函数：将用户输入的身高从英寸转换为英尺并输出
 */
int main()
{
    float height_inch; // 用户输入的身高（单位：英寸）
    cout << "你的身高是:_"; // 提示用户输入身高
    cin >> height_inch; // 读取用户输入的身高

    const int FOOT_TO_INCH = 12; // 常量，1英尺等于12英寸
    float height_foot = height_inch / FOOT_TO_INCH; // 将身高从英寸转换为英尺

    // 输出转换结果
    cout << "你的身高是：" << height_inch << " 英寸, " << height_foot << " 英尺。";

    return 0;
}
