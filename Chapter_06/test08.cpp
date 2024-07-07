#include "iostream"
using namespace std;
#include "fstream"
#include "cstdlib"

int main()
{
    char ch;
    int count = 0;

    ifstream inFile;
    inFile.open("test08.txt");  // 关联文件

    if (!inFile.is_open())
    {
        cout << "文件未能正常打开" << endl;
        exit(EXIT_FAILURE);
    }

    while (!inFile.eof())  // inFile.eof() 判断是否到达文件尾
    {
        inFile >> ch;   // 提取字符到ch
        ++count;
    }
    cout << "文件包含" << count << "个字符";

    inFile.close();

    return 0;
}