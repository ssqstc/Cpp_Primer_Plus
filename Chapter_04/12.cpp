#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 指针的基本概念：
   - 指针是一个变量，其值为另一个变量的地址。
   - 使用取地址符 `&` 可以获取变量的地址。
   - 使用解引用符 `*` 可以访问指针指向的变量的值。

2. 指针和变量的关系：
   - 定义一个指向 `int` 类型的指针变量，并将其初始化为指向一个 `int` 变量的地址。
   - 通过指针访问和修改变量的值。

注意点：
- 确保指针初始化时指向一个有效的地址。
- 使用指针操作时要特别小心，避免访问无效内存地址导致程序崩溃。
*/

int main()
{
    int updates = 6;  // 定义整数变量updates并赋值为6
    int *P_updates;  // 定义指向整数的指针变量P_updates
    P_updates = &updates;  // 将updates变量的地址赋值给指针P_updates

    // 输出updates的值
    cout << "update的值:" << updates << endl;
    // 输出updates的地址
    cout << "update地址:" << &updates << endl;
    // 输出指针P_updates存储的地址，即updates的地址
    cout << "P_update地址:" << P_updates << endl;
    // 输出指针P_updates指向的变量的值，即updates的值
    cout << "P_update的值:" << *P_updates << endl;

    *P_updates += 1;  // 通过指针P_updates将updates的值加1

    // 输出自加1后的updates的值
    cout << "P_updates自加一后，update的值:" << updates << endl;

    return 0; // 返回0表示程序正常结束
}
