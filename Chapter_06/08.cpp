#include "iostream"
using namespace std;
// 捕鱼案例
const int Max = 5;
int main()
{
    double fish[Max];
    cout << "Please enter the weight of your fish." << endl;
    cout << "You may enter up to " << Max << " fish <q> to terminate." << endl;

    cout << "fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i])       // cin方法返回值 输入字符匹配返回true
    {
        if (++i < Max)      // i < Max继续让用户输入
            cout << "fish #" << i + 1 << ": ";      // 提示输入下一条鱼信息
    }
    double total = 0.0;     // 初始鱼总重值0
    for (int j = 0; j < i; ++j)
        total += fish[j];       // 通过循环计算鱼总重

    if (0 == i)     // 判断是否一条鱼都没捕到
        cout << "No fish!" << endl;
    else
        cout << "fish total: " << total << endl;
        cout << "Average weight of " << i << " fish: " << total / i;

    return 0;
}