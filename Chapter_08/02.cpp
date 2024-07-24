#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 引用变量：引用是变量的别名，创建时必须初始化，且不能改变引用的对象。
 * 2. 引用与原变量：引用操作与原变量完全等效，修改引用变量即修改原变量。
 * 3. 地址相同：引用与原变量共享同一个内存地址。
 *
 * 注意点：
 * 1. 引用初始化：引用必须在声明时进行初始化，不能之后再赋值。
 * 2. 引用修改：修改引用变量的值，原变量的值也会随之改变。
 * 3. 地址比较：引用变量和原变量的地址是相同的，验证引用的本质。
 */

int main() {
    int rats = 10;             // 定义整数变量 rats 并初始化为 10
    int &rodents = rats;       // 定义引用变量 rodents，并引用 rats

    cout << "rats = " << rats << endl;           // 输出 rats 的值
    cout << "rodents = " << rodents << endl;     // 输出 rodents 的值

    rodents++;                                   // 增加 rodents 的值，实际上也是增加 rats 的值
    cout << "rats = " << rats << endl;           // 输出增加后的 rats 的值
    cout << "rodents = " << rodents << endl;     // 输出增加后的 rodents 的值

    cout << "&rats = " << &rats << endl;         // 输出 rats 的内存地址
    cout << "&rodents = " << &rodents << endl;   // 输出 rodents 的内存地址，应该与 rats 相同

    return 0;
}
