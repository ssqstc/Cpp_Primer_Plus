/*
知识点：
1. 命令行参数：使用 `argc` 和 `argv[]` 处理三个文件名，分别用于写入文件和读取两个文件。
2. 文件操作：使用 `ofstream` 追加写入数据到目标文件，使用 `ifstream` 读取源文件内容。
3. 文件读取和写入：通过 `getline()` 按行读取，并逐行将两个文件的内容合并到目标文件中。

注意点：
1. 需要确保传入正确数量的命令行参数，三个文件名不可缺少。
2. 文件读取时要检查是否读取到末尾，以防止空行或无效数据的处理问题。
3. 写入时确保使用追加模式 (`ios_base::app`) 否则会覆盖目标文件内容。
4. 文件操作结束后要及时关闭文件，防止资源泄露。
*/

#include <iostream>   // 包含标准输入输出流库
#include <fstream>    // 包含文件操作库
using namespace std;  // 使用标准命名空间

int main(int argc, char* argv[]) {
    // 检查命令行参数是否正确提供，必须有 4 个参数（程序名+3个文件名）
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " write_file read_file1 read_file2" << endl;
        exit(0);  // 退出程序
    }

    // 以追加模式打开第一个文件，用于写入数据
    ofstream fout(argv[1], ios_base::app);

    // 打开第二和第三个文件，用于读取数据
    ifstream fin1(argv[2]);
    ifstream fin2(argv[3]);

    // 检查三个文件是否都成功打开
    if (fout.is_open() && fin1.is_open() && fin2.is_open()) {
        string str;  // 存储每行读取的字符串
        // 循环读取两个文件的内容，直到其中一个文件到达末尾
        while (!fin1.eof() || !fin2.eof()) {
            // 从第一个文件读取一行内容，如果有效则写入目标文件并添加空格
            if (getline(fin1, str) && str.size() > 0) {
                fout << str << ' ';  // 写入并在行尾添加空格
            }
            // 从第二个文件读取一行内容，如果有效则写入目标文件并换行
            if (getline(fin2, str) && str.size() > 0) {
                fout << str << '\n';  // 写入并换行
            }
        }
    }

    // 关闭打开的文件
    fout.close();
    fin1.close();
    fin2.close();

    return 0;  // 返回 0，表示程序成功执行
}