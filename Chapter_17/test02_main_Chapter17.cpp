/*
知识点：
1. 使用命令行参数传递文件名，并将数据写入文件。
2. 使用 `ofstream` 类来创建文件并写入数据。
3. `cin.get()` 从标准输入获取字符，并使用 `EOF`（文件结束符）作为输入结束条件。

注意点：
1. 命令行参数必须提供有效的文件名作为输出目标。
2. `cin.get(ch)` 读取字符时，`EOF` 常用于标记输入结束，但在不同平台上可能需要手动触发结束（如 Ctrl+D 或 Ctrl+Z）。
3. 程序中没有对文件写入错误进行处理，建议加入错误处理机制。
*/

#include <iostream>   // 包含输入输出流库
#include <fstream>    // 包含文件操作库
using namespace std;  // 使用标准命名空间

int main(int argc, char* argv[]) {
    char ch;         // 存储用户输入的字符
    ofstream fout;   // 创建输出文件流对象

    // 打开由命令行参数传入的文件名
    fout.open(argv[1]);

    // 判断文件是否成功打开
    if (fout.is_open()) {
        cout << "Please enter the data: ";  // 提示用户输入数据

        // 逐个读取用户输入的字符，直到遇到 EOF（文件结束符）
        while (cin.get(ch) && ch != EOF) {
            fout << ch;  // 将字符写入文件
        }
    } else {
        // 文件无法打开时输出错误信息
        cout << "Can't open!" << endl;
        exit(0);  // 退出程序
    }

    return 0;  // 返回 0，表示程序成功执行
}