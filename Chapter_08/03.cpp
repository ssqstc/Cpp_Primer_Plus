#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 引用变量：引用是变量的别名，创建时必须初始化，且不能改变引用的对象。
 * 2. 引用与赋值：通过引用赋值实际上是对引用对象的赋值，而不是改变引用的绑定关系。
 * 3. 内存地址：引用和原变量的地址相同。
 *
 * 注意点：
 * 1. 引用的绑定：引用一旦初始化，便不能再引用其他变量，赋值操作不会改变引用的绑定关系。
 * 2. 赋值操作：通过引用赋值会直接影响原变量的值。
 * 3. 地址验证：验证引用和原变量的地址是否相同，以理解引用的本质。
 */

int main() {
    int rats = 101;            // 定义整数变量 rats 并初始化为 101
    int &rodents = rats;       // 定义引用变量 rodents，并引用 rats

    cout << "rats = " << rats << endl;           // 输出 rats 的值
    cout << "rodents = " << rodents << endl;     // 输出 rodents 的值

    cout << "&rats = " << &rats << endl;         // 输出 rats 的内存地址
    cout << "&rodents = " << &rodents << endl;   // 输出 rodents 的内存地址，应该与 rats 相同

    int bunnies = 50;         // 定义另一个整数变量 bunnies 并初始化为 50
    rodents = bunnies;        // 通过引用 rodents 对 rats 赋值为 bunnies 的值

    cout << "bunnies = " << bunnies << endl;     // 输出 bunnies 的值
    cout << "rodents = " << rodents << endl;     // 输出 rodents 的值，实际上也是 rats 的值
    cout << "rats = " << rats << endl;           // 输出 rats 的值，应该与 rodents 和 bunnies 相同

    cout << "&bunnies = " << &bunnies << endl;   // 输出 bunnies 的内存地址
    cout << "&rodents = " << &rodents << endl;   // 输出 rodents 的内存地址，应该与 rats 相同

    return 0;
}
