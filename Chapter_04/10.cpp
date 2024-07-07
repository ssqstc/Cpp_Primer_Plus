#include "iostream"
using namespace std;
// 共用体 union 创建，可以内含不同的数据类型，但同时只能存储其中一种类型。

union one2all
{
    char ch;
    int n;
};
struct two2all
{
    char ch;
    int n;
};
int main()
{
    one2all test1;
    cout << "共用体占用空间：" << sizeof test1 << endl;     // 共用体长度为其最大成员长度
    two2all test2;
    cout << "结构体占用空间：" << sizeof test2 << endl;     // 结构体位字段对其，其成员均占用最大成员长度大小，整体占用为：最大成员长度*成员数

    test1.ch = 'a';
    cout << test1.ch << endl;   // a
//    cout << test1.n << endl;    // 得到了随机值
    test1.n = 90;
    cout << test1.n << endl;    // 90
    cout << test1.ch << endl;   // z    z对应的ASCLL数字是90      原存储数据‘a'被替代
    return 0;
}