#include "iostream"
using namespace std;

/**
 * 主函数，演示字符串对象的赋值、拼接和附加操作
 *
 * 此示例展示了如何在C++中使用`std::string`对象进行基本操作，包括：
 * - 直接赋值
 * - 通过C风格字符串赋值
 * - 字符串拼接
 * - 字符串附加
 *
 * @return int 返回0，表示程序正常结束
 */
int main()
{
    string s1 = "penguin";   // 定义并初始化字符串s1
    string s2, s3;           // 定义字符串s2和s3

    // 显示字符串赋值
    cout << "可以将一个字符串对象赋值给另一个：s2 = s1\n";
    s2 = s1;                // 赋值s1给s2

    // 显示通过C风格字符串赋值
    cout << "可以将C风格字符串赋值给字符串对象。\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";         // 赋值C风格字符串给s2

    // 显示字符串拼接
    cout << "可以拼接字符串：s3 = s1 + s2\n";
    s3 = s1 + s2;           // 拼接s1和s2到s3

    // 显示字符串附加
    cout << "可以追加字符串。\n";
    s1 += s2;               // s1附加s2
    cout << "s1 += s2 得到 s2 = " << s1 << endl;

    s2 += " for a day";      // s2附加文本
    cout << "s2 += \" for a day \" 得到 s2 = " << s2 << endl;

    return 0;               // 程序正常结束
}
