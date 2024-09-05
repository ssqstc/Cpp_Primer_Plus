/*
知识点：
1. `ofstream` 和 `ifstream` 分别用于文件的写操作和读操作。
2. 使用 `open()` 函数打开文件，并通过文件流进行输入输出操作。
3. `fout.close()` 用于关闭文件，确保资源释放。
4. `fin.get(char)` 用来逐个字符读取文件内容，并通过 `while` 循环输出。

注意点：
1. 文件流需要手动打开和关闭，避免内存泄漏或文件损坏。
2. 检查文件是否成功打开，避免因文件不存在或路径错误导致的异常。
3. 读取和写入操作后应及时关闭文件，以确保数据被正确写入文件中。
*/

#include <iostream> // 包含标准输入输出库
#include <fstream> // 包含文件操作库
using namespace std; // 使用标准命名空间

int main() {
    string fileName; // 用于存储文件名
    cout << "Enter name for new file: "; // 提示用户输入新文件名
    cin >> fileName; // 获取用户输入的文件名

    ofstream fout; // 定义输出文件流对象
    fout.open(fileName); // 打开用户指定的文件进行写操作

    // 将字符串写入文件
    fout << "For your eyes only!" << endl; // 向文件写入一行文本

    float secret; // 定义浮点数变量用于存储秘密数字
    cout << "Enter your secret number: "; // 提示用户输入秘密数字
    cin >> secret; // 获取用户输入的数字
    fout << "Your secret number is: " << secret << endl; // 将数字写入文件

    ifstream fin; // 定义输入文件流对象
    fin.open(fileName); // 打开之前写入的文件进行读操作
    cout << "Here are the contents of " << fileName << ": " << endl; // 输出文件内容提示

    char ch; // 用于逐个字符读取文件内容
    while (fin.get(ch)) { // 使用 fin.get() 逐个字符读取文件内容
        cout << ch; // 将读取到的字符输出到屏幕上
    }

    fout.close(); // 关闭输出文件流，确保文件写入完成
    return 0; // 程序结束，返回 0 表示成功
}