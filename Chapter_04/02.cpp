#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - `cin.getline()`：用于读取包含空格的字符串输入。
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 字符数组：定义字符数组并使用其存储和操作字符串。
 *
 * 注意点：
 * - `cin.getline()`可以读取包含空格的字符串，适合用于读取整行输入。
 */

/*
 * 主函数：处理用户输入的姓名和喜爱的甜点，并进行相关输出
 */
int main()
{
    const int Size = 20; // 字符数组大小常量
    char name1[Size]; // 用于存储用户输入的姓名
    char dessert[Size]; // 用于存储用户输入的甜点

    // 提示用户输入姓名
    cout << "Enter your name:\n";
    cin.getline(name1, Size); // 读取用户输入的姓名

    // 提示用户输入喜爱的甜点
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, Size); // 读取用户输入的甜点

    // 输出用户的姓名和喜爱的甜点
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name1 << endl;

    return 0;
}
