/*
知识点：
1. 使用 `ifstream` 和 `ofstream` 类分别实现文件的读取和写入操作。
2. `ios_base::app` 模式用于文件的追加写入，即在文件末尾添加内容而不覆盖已有内容。
3. 使用 `fin.clear()` 清除文件流状态，以便在重新打开文件前重置流的状态。
4. `getline()` 函数用于从输入中读取一整行内容，直到遇到换行符。

注意点：
1. 确保文件在打开之前不存在异常，并检查文件的打开状态。
2. 使用 `ios_base::app` 进行文件写操作时，应当注意文件指针会自动移动到文件末尾。
3. 文件流在使用完毕后应及时关闭，避免资源浪费或文件损坏。
*/

#include <iostream> // 包含标准输入输出库
#include <fstream> // 包含文件操作库
#include <string> // 包含字符串库
using namespace std; // 使用标准命名空间

int main() {
    const char* file = "secret"; // 定义文件名为 "secret"
    char ch; // 用于逐字符读取文件内容
    ifstream fin; // 定义输入文件流对象
    fin.open(file); // 打开文件进行读取操作
    if (fin.is_open()) { // 如果文件成功打开
        cout << "Here are the contents of " << file << ": " << endl; // 输出文件内容提示
        while (fin.get(ch)) { // 使用 fin.get() 逐字符读取文件内容
            cout << ch; // 输出读取到的字符
        }
        fin.close(); // 读取完毕后关闭文件
    }

    ofstream fout; // 定义输出文件流对象
    // 打开文件以追加模式进行写入操作，ios_base::app 确保内容追加到文件末尾
    fout.open(file, ios_base::out | ios_base::app);
    if (!fout.is_open()) { // 如果文件打开失败
        cout << "Can't open " << file << endl; // 输出错误提示
        exit(0); // 退出程序
    }
    cout << "Enter new string append to the file: " << endl; // 提示用户输入新内容
    string str; // 定义字符串变量存储用户输入
    while (getline(cin, str) && str.size() > 0) { // 逐行读取用户输入，直到用户输入空行
        fout << str << endl; // 将用户输入的字符串追加到文件中
    }
    fout.close(); // 写入完毕后关闭文件

    fin.clear(); // 清除文件流的状态标志，准备重新打开文件
    fin.open(file); // 重新打开文件以读取更新后的内容
    if (fin.is_open()) { // 如果文件成功打开
        cout << "Here are the contents of " << file << ": " << endl; // 输出文件内容提示
        while (fin.get(ch)) { // 逐字符读取文件内容
            cout << ch; // 输出读取到的字符
        }
        fin.close(); // 读取完毕后关闭文件
    }

    return 0; // 程序结束，返回 0 表示成功
}