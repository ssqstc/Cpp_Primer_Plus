/*
知识点：
1. 结构体 `planet` 作为存储行星信息的数据结构，使用 `fstream` 进行二进制文件的读写。
2. `seekg()` 和 `seekp()` 用于在文件流中定位读取和写入的位置。
3. 文件读写的过程中使用 `sizeof` 来准确地定位每条记录，`streampos` 用于表示文件中的字节位置。
4. 通过 `finOut.read()` 读取数据和 `finOut.write()` 写入数据，以修改二进制文件中的特定记录。

注意点：
1. 文件以二进制模式打开，并同时支持读写操作（`ios_base::in | ios_base::out | ios_base::binary`）。
2. 需要确保输入的记录号有效，并且在修改后更新文件内容。
3. 在操作文件流时，注意处理 EOF 和清除文件流的错误状态。
*/

#include <iostream>  // 包含输入输出流库
#include <fstream>   // 包含文件读写流库
using namespace std; // 使用标准命名空间

// 定义行星结构体
struct planet {
    char name[20];   // 行星名称，最多 20 个字符
    double population; // 行星人口
    double g;       // 行星的重力加速度
};

int main() {
    planet pl; // 创建行星结构体对象
    const char* file = "planet.dat"; // 定义文件名
    cout << fixed; // 设置浮点数的固定格式输出

    fstream finOut; // 定义文件输入输出流对象
    // 以读写、二进制模式打开文件
    finOut.open(file, ios_base::in | ios_base::out | ios_base::binary);
    int ct = 0; // 记录当前文件中记录的数量
    if (finOut.is_open()) { // 判断文件是否成功打开
        cout << "Here are the current contents of the " << file << endl; // 输出文件内容提示
        // 循环读取文件中的行星记录并输出
        while (finOut.read((char*)&pl, sizeof pl)) {
            cout << ct++ << ": " << pl.name << ": " << setprecision(0) << pl.population << ", " << setprecision(1) << pl.g << endl; // 输出当前行星信息
        }
        if (finOut.eof()) { // 如果读到了文件末尾
            finOut.clear(); // 清除 EOF 标志，准备后续操作
        }
    }

    // 询问用户要修改的记录编号
    cout << "Enter the record number you wish to change: ";
    int rec;
    cin >> rec; // 获取用户输入的记录号
    while (cin.get() != '\n'); // 处理多余的换行符
    if (rec < 0 || rec >= ct) { // 检查记录号是否有效
        cout << "Out of range!" << endl; // 如果记录号超出范围，输出错误提示
        exit(0); // 退出程序
    }

    // 根据记录号计算该记录在文件中的位置
    streampos place = rec * sizeof pl;
    finOut.seekg(place); // 将文件指针移动到对应位置
    finOut.read((char*)&pl, sizeof pl); // 读取该记录
    // 输出当前记录的信息
    cout << rec << ": " << pl.name << ": " << setprecision(0) << pl.population << ", " << setprecision(1) << pl.g << endl;
    if (finOut.eof()) { // 检查文件读取是否到了末尾
        finOut.clear(); // 清除 EOF 状态
    }

    // 提示用户输入新的行星信息
    cout << "Enter planet name: " << endl;
    cin.get(pl.name, 20); // 获取行星名称
    while (cin.get() != '\n'); // 处理多余的换行符
    cout << "Enter planet population: ";
    cin >> pl.population; // 获取行星人口
    cout << "Enter the planet's acceleration gravity: ";
    cin >> pl.g; // 获取行星重力加速度
    finOut.seekp(place); // 将文件指针移动到记录位置
    finOut.write((char*)&pl, sizeof pl); // 将修改后的行星信息写入文件

    // 重新定位文件指针，输出修改后的所有记录
    finOut.seekg(0);
    ct = 0; // 重置记录计数器
    cout << "Here are the current contents of the " << file << endl; // 输出修改后的文件内容
    while (finOut.read((char*)&pl, sizeof pl)) {
        cout << ct++ << ": " << pl.name << ": " << setprecision(0) << pl.population << ", " << setprecision(1) << pl.g << endl; // 输出每条记录
    }

    return 0; // 返回 0，表示程序成功执行
}