#include <iostream>
using namespace std;

int main()
{
    // 初始化浮点数a为一个非常大的值
    float a = 2.34e22;
    // b初始化为a加上1.0，期望b的值比a大1
    float b = a + 1.0;

    // 输出变量a的值
    cout << "a = " << a << endl;
    // 输出b减去a的结果，预期为1.0，但由于浮点数精度问题，可能不精确
    cout << "b - a = " << b - a << endl;

    return 0;
}
