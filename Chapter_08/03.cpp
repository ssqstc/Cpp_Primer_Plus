#include "iostream"
using namespace std;
// 引用变量

int main() {
    int rats = 101; // 定义并初始化变量 rats
    int &rodents = rats; // 定义引用变量 rodents，引用 rats

    // 输出 rats 和 rodents 的值
    cout << "rats = " << rats << endl;          // rats = 101
    cout << "rodents = " << rodents << endl;    // rodents = 101

    // 输出 rats 和 rodents 的地址，应该是相同的
    cout << "&rats = " << &rats << endl;        // &rats = 0x16dd936e8 (示例地址)
    cout << "&rodents = " << &rodents << endl;  // &rodents = 0x16dd936e8 (示例地址)

    int bunnies = 50; // 定义并初始化变量 bunnies
    rodents = bunnies; // 赋值语句，将 bunnies 的值赋给 rats 和 rodents

    // 输出 bunnies、rodents 和 rats 的值
    cout << "bunnies = " << bunnies << endl;    // bunnies = 50
    cout << "rodents = " << rodents << endl;    // rodents = 50
    cout << "rats = " << rats << endl;          // rats = 50

    // 输出 bunnies 和 rodents 的地址，应该是不同的
    cout << "&bunnies = " << &bunnies << endl;  // &bunnies = 0x16f7536dc (示例地址)
    cout << "&rodents = " << &rodents << endl;  // &rodents = 0x16dd936e8 (示例地址，与 rats 相同)

    return 0;
}
