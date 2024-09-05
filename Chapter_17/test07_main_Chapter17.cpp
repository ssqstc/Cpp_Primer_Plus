/*
知识点：
1. `vector` 动态数组：用于存储可变长度的字符串序列。
2. 文件输入输出流：`ofstream` 和 `ifstream` 处理二进制文件的读写操作。
3. 仿函数：通过重载 `operator()` 实现特定操作，将字符串写入文件。
4. 内存管理：在 `GetStrs` 函数中，动态分配和释放内存用于读取文件内容。

注意点：
1. 在读取和写入二进制文件时，要确保数据格式的一致性，如字符串长度和实际内容的正确处理。
2. 内存管理：确保每次动态分配的内存及时释放，避免内存泄漏。
3. 文件读写操作需要打开成功后才能进行，否则应处理错误。
*/

#include <iostream>   // 标准输入输出
#include <fstream>    // 文件输入输出
#include <vector>     // 动态数组
using namespace std;

// 显示字符串
void showStr(const string& s) {
    cout << s << endl;  // 输出每个字符串
}

// 仿函数类，用于将字符串存储到二进制文件
class Store {
private:
    ofstream& os;  // 输出流引用
public:
    explicit Store(ofstream& output) : os(output) {}  // 构造函数
    void operator()(const string&);  // 重载()运算符
};

// Store 类中重载的()运算符，将字符串的长度和内容写入文件
void Store::operator()(const string& str) {
    size_t len = str.size();  // 获取字符串长度
    os.write((char*)& len, sizeof len);  // 写入字符串长度
    os.write(str.data(), len);  // 写入字符串内容
}

// 从二进制文件中读取字符串并存储到 vector 中
void GetStrs(ifstream& is, vector<string>& vi) {
    size_t len;  // 用于存储读取的字符串长度
    char* pt;  // 临时指针，用于存储读取的字符串
    // 逐个读取字符串长度和内容
    while (is.read((char*)& len, sizeof len)) {
        pt = new char[len];  // 动态分配内存
        is.read(pt, len);  // 读取字符串内容
        vi.push_back(pt);  // 将字符串存储到 vector
        delete []pt;  // 释放临时内存
    }
}

int main() {
    vector<string> vostr;  // 用于存储用户输入的字符串
    string temp;

    // 获取用户输入的字符串
    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0') {
        vostr.push_back(temp);  // 将输入的字符串存储到 vector
    }

    // 显示用户输入的字符串
    cout << "Here is your input.\n";
    for_each(vostr.begin(), vostr.end(), showStr);

    // 打开文件并以二进制形式将字符串写入文件
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    // 读取文件中的字符串并存储到另一个 vector 中
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {  // 检查文件是否成功打开
        cerr << "Could not open file for input.\n";
        exit(0);
    }

    // 从文件中读取字符串
    GetStrs(fin, vistr);

    // 显示从文件读取的字符串
    cout << "\nHere are the strings read from the file:\n";
    for_each(vistr.begin(), vistr.end(), showStr);

    return 0;  // 返回 0 表示程序成功执行
}