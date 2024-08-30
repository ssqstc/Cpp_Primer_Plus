/*
知识点总结:
1. **文件输入流**：使用 `ifstream` 对象从文件中读取数据，演示了文件的打开、检查和读取操作。
2. **文件读取循环**：使用 `getline` 按指定的分隔符读取文件内容，直到文件末尾。
3. **错误处理**：通过检查文件是否成功打开，处理文件操作中的错误。

注意点:
1. **文件路径与权限**：确保文件路径正确，且程序有读取文件的权限。
2. **循环读取的终止条件**：注意文件读取的循环控制条件，应在每次读取后检查流状态。
3. **文件关闭**：在完成文件操作后，记得关闭文件以释放资源。
*/

#include <iostream>  // 标准输入输出流库
#include <fstream>   // 文件流库
#include <string>    // 标准字符串库
#include <cstdlib>   // C标准库，包含 EXIT_FAILURE

using namespace std;

int main() {
    ifstream fin;  // 创建文件输入流对象
    fin.open("02_main_Chapter16.txt");  // 打开文件
    if (!fin.is_open()) {  // 检查文件是否成功打开
        cerr << "Can't open file. Bye." << endl;  // 如果文件打开失败，输出错误信息
        exit(EXIT_FAILURE);  // 退出程序并返回失败状态码
    }

    string item;  // 用于存储读取的字符串
    int count = 0;  // 计数器，用于统计读取的项目数
    getline(fin, item, ':');  // 从文件中读取第一行内容，使用冒号作为分隔符
    while (fin) {  // 当读取成功时进入循环
        count++;  // 增加计数器
        cout << count << ": " << item << endl;  // 输出计数器和读取的内容
        getline(fin, item, ':');  // 继续读取下一行内容
    }
    fin.close();  // 关闭文件
    return 0;  // 正常结束程序
}