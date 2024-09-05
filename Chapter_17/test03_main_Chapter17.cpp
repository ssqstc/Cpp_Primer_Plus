/*
知识点：
1. 命令行参数的使用：通过 `argc` 和 `argv[]` 处理传入的文件名。
2. 文件操作：使用 `ofstream` 将数据写入文件，使用 `ifstream` 从文件中读取数据。
3. 文件复制：从一个文件中读取字符，并写入到另一个文件中。

注意点：
1. 程序要求命令行中提供两个文件名作为参数：一个用于写入，另一个用于读取。
2. 需要检查文件是否成功打开，以防止出现文件不存在或权限不足的情况。
3. 文件操作结束后需要及时关闭文件，确保数据正确写入。
*/

#include <iostream>   // 包含输入输出流库
#include <fstream>    // 包含文件操作库
using namespace std;  // 使用标准命名空间

int main(int argc, char* argv[]) {
    // 检查命令行参数是否正确提供，必须有 3 个参数（程序名+2个文件名）
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " write_file1 read_file2" << endl;  // 提示正确的用法
        exit(0);  // 退出程序
    }

    // 创建输出文件流对象，打开第一个文件（argv[1]）以写入数据
    ofstream fout(argv[1]);

    // 创建输入文件流对象，打开第二个文件（argv[2]）以读取数据
    ifstream fin(argv[2]);

    // 检查两个文件是否成功打开
    if (fout.is_open() && fin.is_open()) {
        char ch;  // 存储从输入文件读取的字符

        // 从输入文件逐个读取字符，并写入到输出文件
        while (fin.get(ch)) {
            fout << ch;  // 将读取的字符写入到输出文件
        }
    } else {
        // 如果文件无法打开，输出错误提示
        cout << "Can't open!" << endl;
        exit(0);  // 退出程序
    }

    // 关闭输出文件
    fout.close();

    // 关闭输入文件
    fin.close();

    return 0;  // 返回 0，表示程序成功执行
}