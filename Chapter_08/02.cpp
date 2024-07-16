#include "iostream"
using namespace std;
// 引用变量

int main() {
    int rats = 10;
    int &rodents = rats; // 定义引用变量 rodents，引用 rats

    // 输出 rats 和 rodents 的值
    cout << "rats = " << rats << endl;          // rats = 10
    cout << "rodents = " << rodents << endl;    // rodents = 10

    // 修改引用变量 rodents，相当于修改 rats
    rodents++;
    cout << "rats = " << rats << endl;          // rats = 11
    cout << "rodents = " << rodents << endl;    // rodents = 11

    // 输出 rats 和 rodents 的地址，应该是相同的
    cout << "&rats = " << &rats << endl;        // &rats = 0x16b6376e8 (示例地址)
    cout << "&rodents = " << &rodents << endl;  // &rodents = 0x16b6376e8 (示例地址)

    return 0;
}
