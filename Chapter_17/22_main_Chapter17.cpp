/*
知识点：
1. 使用 `ifstream` 读取文件内容，并将字符输入到 `stringstream` 中进行处理。
2. 利用 `stringstream` 来解析和处理字符串，特别是将其转换为数字。
3. 基本的文件操作：打开文件、读取文件内容、关闭文件。
4. 累加文件中的数字，注意字符流的使用及其转换。

注意点：
1. 需要检查文件是否成功打开，可以在打开文件后增加判断。
2. 确保文件中内容是可转换为数字的，否则在转换时可能会出错。
3. `stringstream` 用于从字符流中提取数字，但需考虑处理非数字字符的场景。
*/

#include <iostream>   // 包含输入输出流库
#include <fstream>    // 包含文件读写流库
#include <sstream>    // 包含字符串流库
using namespace std;  // 使用标准命名空间

int main() {
    string fileName;  // 定义保存文件名的字符串
    cout << "Enter name for new file: ";  // 提示用户输入文件名
    cin >> fileName;  // 获取用户输入的文件名

    ifstream fin;  // 定义文件输入流对象
    fin.open(fileName);  // 打开指定文件
    // 提示文件内容展示开始
    cout << "Here are the contents of " << fileName << ": " << endl;

    char ch;  // 用于存储从文件读取的字符
    int sum = 0;  // 保存文件中的数字和
    stringstream str;  // 定义字符串流对象，用于保存文件的所有内容
    int n;  // 用于存储从字符串流中提取的整数
    // 逐个字符读取文件内容并存入字符串流
    while (fin.get(ch)) {
        str << ch;  // 将每个读取到的字符追加到字符串流中
    }
    // 从字符串流中逐个提取数字并进行累加
    while (str >> n) {
        sum += n;  // 将提取到的数字累加到 sum
    }
    cout << sum << endl;  // 输出累加结果

    fin.close();  // 关闭文件
    return 0;  // 返回 0，表示程序成功执行
}