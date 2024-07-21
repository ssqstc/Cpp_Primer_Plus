#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 字符串对象操作：字符串赋值、拼接和追加。
 * - 使用C++标准库的`string`类进行字符串处理。
 *
 * 注意点：
 * - `string`类提供了丰富的字符串操作功能，使用时注意其方法和操作符的重载。
 */

/*
 * 主函数：演示字符串对象的各种操作
 */
int main()
{
    string s1 = "penguin";   // 初始化字符串对象
    string s2, s3;           // 未初始化的字符串对象

    // 字符串赋值
    cout << "可以将一个字符串对象赋值给另一个：s2 = s1\n";
    s2 = s1;                 // 将s1赋值给s2

    // 赋值C风格字符串
    cout << "可以将C风格字符串赋值给字符串对象。\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";          // 将C风格字符串赋值给s2

    // 拼接字符串
    cout << "可以拼接字符串：s3 = s1 + s2\n";
    s3 = s1 + s2;            // 拼接s1和s2赋值给s3

    // 追加字符串
    cout << "可以追加字符串。\n";
    s1 += s2;                // 将s2追加到s1
    cout << "s1 += s2 得到 s1 = " << s1 << endl;

    s2 += " for a day";      // 将C风格字符串追加到s2
    cout << "s2 += \" for a day\" 得到 s2 = " << s2 << endl;

    return 0;                // 返回0表示程序正常结束
}
