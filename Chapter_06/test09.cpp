#include "iostream"
#include "fstream"
using namespace std;

/*
 * 知识点总结：
 * - 使用 `ifstream` 类读取文件数据。
 * - 动态分配数组 (`new` 和 `delete[]`) 来存储捐献者数据。
 * - 文件读取包括字符串和数字，使用 `getline()` 处理包含空格的字符串。
 * - 处理文件打开失败并进行错误处理。
 * - 使用 `eof()` 判断文件是否结束，但最好在读取数据时处理文件结束情况。
 *
 * 注意点：
 * - 确保文件成功打开，未打开则退出程序。
 * - 使用 `getline()` 读取包含空格的字符串数据前，需要清除缓冲区中的剩余字符。
 * - 读取数据后检查数组边界，避免超出范围。
 * - 释放动态分配的内存以避免内存泄漏。
 */

struct patron
{
    string patron_name;
    double patron_money{};
};

int main()
{
    int patron_num, i = 0;
    ifstream inFile;
    string file_name;

    cout << "Enter the file name:";
    getline(cin, file_name);  // 读取文件名

    inFile.open(file_name);   // 打开文件
    if (!inFile.is_open())    // 检查文件是否成功打开
    {
        cout << "文件未正常打开!" << endl;
        exit(EXIT_FAILURE);
    }

    inFile >> patron_num;     // 读取捐献者数目
    auto *p_patron = new patron[patron_num];    // 动态分配内存

    // 读取每个捐献者的信息
    while (!inFile.eof() && i < patron_num)
    {
        inFile.get();         // 清除换行符
        getline(inFile, p_patron[i].patron_name);  // 读取名字
        inFile >> p_patron[i].patron_money;  // 读取捐款数额
        ++i;
    }

    // 输出大捐献者的信息
    cout << "Grand Patrons: " << endl;
    int count = 0;
    for (int i = 0; i < patron_num; ++i) {
        if (p_patron[i].patron_money > 10000)
        {
            cout << p_patron[i].patron_name << " ,捐款: " << p_patron[i].patron_money << endl;
            ++count;
        }
    }
    if (count == 0)
        cout << "none" << endl;

    // 输出普通捐献者的信息
    cout << "Patrons: " << endl;
    for (int i = 0; i < patron_num; ++i) {
        if (p_patron[i].patron_money <= 10000)
            cout << p_patron[i].patron_name << " ,捐款: " << p_patron[i].patron_money << endl;
    }

    inFile.close();     // 关闭文件
    delete [] p_patron; // 释放动态分配的内存

    return 0;
}
