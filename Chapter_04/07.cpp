#include "iostream"
#include "cstring" // 包含cstring头文件以使用strcpy和strcat函数
using namespace std;

/*
 * 知识点总结：
 * - C风格字符串和C++字符串对象的基本操作。
 * - 使用C++标准库的`string`类进行字符串赋值、拼接及获取长度。
 * - 使用C标准库的`strcpy`和`strcat`函数进行C风格字符串的复制和拼接。
 *
 * 注意点：
 * - `strcpy`和`strcat`需要包含<cstring>头文件。
 * - `strcpy`和`strcat`操作的目标数组需要有足够的空间，否则可能导致溢出。
 */

/*
 * 主函数：演示C风格字符串和C++字符串对象的操作
 */
int main()
{
    char charr1[20];               // 声明C风格字符串数组
    char charr2[20] = "ssqstc666"; // 初始化C风格字符串数组
    string str1;                   // 声明C++字符串对象
    string str2 = "dadada";        // 初始化C++字符串对象

    // C++字符串对象的赋值和拼接
    str1 = str2;                   // 将str2赋值给str1
    str1 += "dadada";              // 将字符串追加到str1

    // C风格字符串的复制和拼接
    strcpy(charr1, charr2);        // 将charr2复制到charr1
    strcat(charr1, "lalala");      // 将字符串拼接到charr1

    // 获取字符串的长度
    int len1 = str1.size();        // 获取str1的长度
    int len2 = strlen(charr1);     // 获取charr1的长度

    // 输出结果
    cout << "The string " << str1 << " contains " << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n";

    return 0;                      // 返回0表示程序正常结束
}
