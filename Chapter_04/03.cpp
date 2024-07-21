#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - `cin.get()`：用于读取包含空格的字符串输入，读取指定字符数或直到换行符为止。
 * - `cin.get().get()`：读取输入并移除缓冲区中的换行符。
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 字符数组：定义字符数组并使用其存储和操作字符串。
 * - cin.get()； 与cin.getline()类似，都读取到行尾，但是get()并不再读取并丢弃换行符。
 *
 * 注意点：
 * - `cin.get().get()`：读取输入后调用`get()`以移除缓冲区中的换行符，防止影响后续输入操作。
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
    cin.get(name1, Size).get(); // 读取用户输入的姓名，并移除换行符

    // 提示用户输入喜爱的甜点
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, Size); // 读取用户输入的甜点

    // 输出用户的姓名和喜爱的甜点
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name1 << endl;

    return 0;
}
