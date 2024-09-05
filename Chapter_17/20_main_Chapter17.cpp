/*
知识点：
1. 使用 `struct` 定义结构体 `planet`，包含行星的名称、人口和重力加速度。
2. 使用 `ifstream` 和 `ofstream` 进行二进制文件的读写操作。
3. `ios_base::binary` 用于指定文件的二进制模式，`ios_base::app` 用于文件追加写入。
4. `read()` 和 `write()` 方法用于二进制文件的输入和输出操作。

注意点：
1. 文件以二进制方式打开，确保文件数据按照结构体的内存布局进行读写，避免数据格式问题。
2. 在使用 `cin.get()` 读取行星名称时，需处理多余的换行符，避免干扰后续输入。
3. 使用 `setprecision()` 控制浮点数的输出精度。
*/

#include <iostream> // 包含标准输入输出库
#include <fstream> // 包含文件操作库
using namespace std; // 使用标准命名空间

// 定义结构体 planet，表示行星信息
struct planet {
    char name[20]; // 行星名称，最多 20 个字符
    double population; // 行星人口
    double g; // 行星的重力加速度
};

int main() {
    planet pl; // 创建行星结构体对象
    const char* file = "planet.dat"; // 定义文件名
    cout << fixed; // 设置浮点数的固定格式输出

    ifstream fin; // 定义输入文件流对象
    fin.open(file, ios_base::in | ios_base::binary); // 以二进制方式打开文件进行读取
    if (fin.is_open()) { // 如果文件成功打开
        cout << "Here are the current contents of the " << file << endl; // 输出文件内容提示
        // 使用 read 方法逐个读取结构体对象并输出
        while (fin.read((char*)&pl, sizeof pl)) {
            cout << pl.name << ": " << setprecision(0) << pl.population << ", " << setprecision(1) << pl.g << endl; // 输出行星信息
        }
        fin.close(); // 关闭输入文件流
    }

    ofstream fout; // 定义输出文件流对象
    // 以追加和二进制模式打开文件，用于写入新的行星信息
    fout.open(file, ios_base::out | ios_base::app | ios_base::binary);
    if (!fout.is_open()) { // 如果文件打开失败
        cout << "Can't open " << file << endl; // 输出错误信息
        exit(0); // 退出程序
    }

    // 提示用户输入行星名称，输入为空时结束输入
    cout << "Enter planet name (enter blank line to quit): ";
    cin.get(pl.name, 20); // 读取行星名称
    while (pl.name[0] != '\0') { // 当名称非空时继续读取
        while (cin.get() != '\n'); // 处理多余的换行符
        cout << "Enter planet population: ";
        cin >> pl.population; // 读取行星人口
        cout << "Enter the planet's acceleration of gravity: ";
        cin >> pl.g; // 读取行星的重力加速度
        while (cin.get() != '\n'); // 处理多余的换行符
        fout.write((char*)&pl, sizeof pl); // 将行星信息写入文件
        cout << "Enter planet name (enter blank line to quit): ";
        cin.get(pl.name, 20); // 读取下一个行星名称
    }
    fout.close(); // 关闭输出文件流

    // 重新打开文件以二进制方式读取并输出更新后的内容
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open()) {
        cout << "Here are the current contents of the " << file << endl;
        while (fin.read((char*)&pl, sizeof pl)) {
            cout << pl.name << ": " << setprecision(0) << pl.population << ", " << setprecision(1) << pl.g << endl; // 输出行星信息
        }
        fin.close(); // 关闭输入文件流
    }

    return 0; // 程序结束，返回 0 表示成功
}