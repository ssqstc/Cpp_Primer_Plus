#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 递归：函数 `countdown` 通过递归调用自身来实现倒计时功能。
 * 2. 变量地址：通过 `&n` 输出局部变量 `n` 的地址。
 * 3. 栈帧：递归调用过程中，每次调用都会在栈上分配新的栈帧，因此每个 `n` 的地址都不同。

 * 注意点：
 * 1. 递归终止条件：确保递归有明确的终止条件（这里是 `n > 0`）。
 * 2. 栈空间：递归深度过大可能导致栈空间不足，通常递归深度应控制在合理范围。
 * 3. 局部变量地址：每次递归调用时，局部变量 `n` 的地址不同，因为每次调用都会在栈上分配新的内存空间。
 */

void countdown(int n);

int main() {
    countdown(4);  // 从4开始倒计时
    return 0;
}

void countdown(int n) {
    cout << "Counting down...." << n << " , n at address = " << &n << endl;  // 输出当前值和地址
    if (n > 0) {
        countdown(n - 1);  // 递归调用，值递减
    }
    cout << n << ": Kadoom" << " , n at address = " << &n << endl;  // 输出当前值和地址
}
