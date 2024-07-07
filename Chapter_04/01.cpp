#include "iostream"
using namespace std;
#include "cstring"

// 主函数，程序的入口点
// sizeof指出数组长度，strlen()只计算可见字符
int main()
{
    // 定义一个常量Size，用于指定字符数组的大小
    const int Size = 15;
    // 定义一个字符数组name1，大小为Size，未初始化
    char name1[Size];
    // 定义一个字符数组name2，并初始化为"ssqstc"
    char name2[Size] = "ssqstc";
    
    // 输出欢迎信息，询问用户的名字
    cout << "Hello I'm " << name2;
    cout << " What's your name?\n";
    
    // 从标准输入读取用户的名字到name1数组中
    cin >> name1;
    
    // 输出关于用户名字的信息，包括名字长度和存储名字的数组大小
    cout << "Well, " << name1 << " , your name has " << strlen(name1) << " letters and is stored \n";
    // 调用strlen()函数计算数组可见字符串长度
    cout << "And your name is stored in a array of " << sizeof name1 << " bytes" << endl;   // 计算数组占用空间大小

    return 0;
}
