#include "iostream"
using namespace std;
#include "fstream"
#include "cstdlib"

const int SIZE = 20;

// 读取文本文件
int main()
{
    char filename[SIZE];
    ifstream inFile;

    // 提示用户输入文件名
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);

    // 打开文件并检查是否成功
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating!" << endl;
        exit(EXIT_FAILURE);  // 程序正常返回用return 如果出错用exit
    }

    double value, sum = 0.0;
    int count = 0;

    // 读取文件中的数据
    while (inFile >> value)
    {
        ++count;  // 计数加一
        sum += value;  // 求和
    }

    if (inFile.eof())  // 检查是否已到达文件末尾
        cout << "End of filed reached." << endl;    // 已到达归档末尾。
    else if (inFile.fail())  // 检查是否读取失败
        cout << "Input terminated by data mismatch." << endl;   // 输入因数据不匹配而终止
    else
        cout << "Input terminated for unknown reason." << endl;     // 输入因未知原因而终止。

    if (0 == count)
        cout << "No data processed." << endl;   // 没有处理任何数据。
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    inFile.close();  // 关闭文件
    return 0;
}
