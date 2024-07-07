#include "iostream"
using namespace std;

// 主函数，程序的入口点
// 混合输入字符串和数字
int main()
{
    // 提示用户输入房屋建造年份
    cout << "What's was your house built?\n";
    // 定义一个整型变量，用于存储房屋的建造年份
    int year;
    // 从标准输入读取房屋的建造年份
    cin >> year;
    
    // 提示用户输入房屋的街道地址
    cout << "What is its street address\n";
    // 定义一个字符数组，用于存储房屋的街道地址
    char address[80];
    // 使用cin.get()读取输入流中的下一个字符，以消除前一个输入操作留下的换行符
    cin.get();  // 消除换行
    // 使用cin.getline()读取用户输入的街道地址，直到遇到换行符或达到最大长度79为止
    cin.getline(address,80);
    
    // 输出房屋的建造年份和街道地址
    cout << "Year built:" << year << endl;
    cout << "Address:" << address << endl;
    // 表示程序运行结束
    cout << "Done\n";
    // 程序正常退出
    return 0;
}
