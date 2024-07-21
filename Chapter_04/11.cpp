#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 变量的值和地址：
   - 使用变量名可以访问变量的值。
   - 使用取地址符 `&` 可以获取变量的内存地址。

2. 基本数据类型的内存地址：
   - 整数（int）类型的变量和浮点数（double）类型的变量在内存中有不同的存储地址。

注意点：
- 在输出变量地址时，需注意不同类型变量的地址表示可能不同。
- 变量的地址在不同的程序运行时可能会不同，但在同一次运行中是固定的。
*/

int main()
{
    int dounts = 6;  // 定义整数变量dounts并赋值为6
    double cups = 4.5;  // 定义双精度浮点数变量cups并赋值为4.5

    // 输出dounts的值和地址
    cout << "dounts的值:" << dounts << "\t" << "dounts的地址:" << &dounts << endl;

    // 输出cups的值和地址
    cout << "cups的值:" << cups << "\t" << "cups的地址:" << &cups << endl;

    return 0; // 返回0表示程序正常结束
}
