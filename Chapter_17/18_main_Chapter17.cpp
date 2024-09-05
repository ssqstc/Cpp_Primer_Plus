/*
知识点：
1. `argc` 和 `argv[]` 用于处理命令行参数，`argc` 表示参数的数量，`argv[]` 是参数的数组。
2. `fstream` 是C++中用于文件输入输出的类，支持同时读写操作。
3. `fin.is_open()` 用于判断文件是否成功打开，`fin.clear()` 清除文件流状态标志。
4. 通过 `fin.get()` 逐字符读取文件内容，并统计字符数。

注意点：
1. 确保命令行参数传入有效的文件名，否则会导致程序无法打开文件。
2. 每次处理完文件后需要调用 `fin.clear()` 清除文件流状态，并及时关闭文件。
3. `argc` 的值至少为1，`argv[0]` 通常表示程序的名称。
*/

#include <iostream> // 包含标准输入输出库
#include <fstream> // 包含文件操作库
using namespace std; // 使用标准命名空间

int main(int argc, char* argv[]) {
    // 如果没有传入文件名参数，则输出提示并退出程序
    if (argc == 1) {
        cout << "Usage: " << argv[0] << " filename(s)" << endl; // 输出使用提示
        exit(0); // 退出程序
    }

    long count; // 用于统计当前文件的字符数量
    long total = 0; // 用于统计所有文件的字符总数
    char ch; // 用于逐字符读取文件内容
    fstream fin; // 定义文件流对象，用于同时读写文件

    // 循环处理命令行传入的每个文件
    for (int i = 1; i < argc; ++i) {
        fin.open(argv[i]); // 打开当前文件
        if (!fin.is_open()) { // 如果文件打开失败
            cout << "Can't open " << argv[i] << endl; // 输出错误提示
            fin.clear(); // 清除文件流的错误状态
            continue; // 跳过当前文件，处理下一个文件
        }

        count = 0; // 初始化当前文件的字符计数
        while (fin.get(ch)) { // 逐字符读取文件内容
            count++; // 统计字符数量
        }
        cout << count << " characters in " << argv[i] << endl; // 输出当前文件的字符数
        total += count; // 将当前文件的字符数累加到总字符数中

        fin.clear(); // 清除文件流的状态标志
        fin.close(); // 关闭当前文件
    }

    cout << total << " characters in all files." << endl; // 输出所有文件的字符总数
    return 0; // 程序结束，返回 0 表示成功
}