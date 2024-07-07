#include "iostream"
using namespace std;
#include "ctime"

// 编写延时循环   clock()返回程序开始执行后所用的系统时间     clock_t是clock()返回类型的别名  CLOCKS_PER_SEC等于每秒包含的系统时间单位数
// 类型别名（可读性更强）     typedef typeName aliasName;     define BYTE char    推荐使用typedef定义别名
int main()
{
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;      // 获取延时时钟节拍 CLOCKS_PER_SEC等于每秒包含的系统时间单位数
    clock_t start = clock();    // clock_t是clock()返回类型的别名   获得当前时钟节拍
    while (clock() - start < delay);
    cout << "Done\n";
    return 0;
}