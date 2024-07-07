#include "iostream"
using namespace std;
#include "fstream"
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
    getline(cin, file_name);    // 获取文件名

    inFile.open(file_name);   // 关联patron文件
    if (!inFile.is_open())  // 检查文件是否打开
    {
        cout << "文件未正常打开!" << endl;
        exit(EXIT_FAILURE);
    }

    inFile >> patron_num;      // 获取捐献人数
    auto *p_patron = new patron[patron_num];    // 动态创建结构体数组

    while (!inFile.eof() && i < patron_num)     // 读到文件尾或者循环至读取的捐献人数
    {
        inFile.get();       // 读取换行符
        getline(inFile,p_patron[i].patron_name);    // 读取第二行
        inFile >> p_patron[i].patron_money;     // 读取捐款数
        ++i;
    }

    cout << "Grand Patrons: " << endl;      // 遍历重要捐款人
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

    cout << "Patrons: " << endl;      // 遍历其他捐款人
    for (int i = 0; i < patron_num; ++i) {
        if (p_patron[i].patron_money <= 10000)
            cout << p_patron[i].patron_name << " ,捐款: " << p_patron[i].patron_money << endl;
    }
    inFile.close();     // 关闭文件
    delete [] p_patron;
    return 0;
}