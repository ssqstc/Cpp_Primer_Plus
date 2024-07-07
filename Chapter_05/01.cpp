#include "iostream"
using namespace std;

/* 主函数，程序的入口点 */
int main()
{
    /* 请求用户输入倒计时的起始值 */
    cout << "Enter the starting countdown value: ";
    int limit;
    cin >> limit;
    /* 初始化计数变量i，用于后续的倒计时循环 */
    int i;
    /* 从用户输入的起始值开始倒计时，直到i减到0 */
    for (i = limit; i; i--) {
        /* 输出当前的倒计时值 */
        cout << "i = " << i << endl;
    }

    /* 倒计时结束后，输出最终的i值 */
    cout << "Done, now that i = " << i << endl;
    return 0;
}
