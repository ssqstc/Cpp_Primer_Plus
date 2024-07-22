#include "iostream"

/*
知识点总结和注意点：
1. 使用`using`声明：
   - `using`声明用于指定使用某个命名空间中的特定名称，从而避免每次使用时都要加上命名空间前缀。
2. `for`循环的使用：
   - `for`循环用于重复执行一段代码，通常包括初始化语句、条件表达式和更新语句。
   - 本例中，循环变量`i`每次增加`by`，直到不满足条件`i < 100`为止。

注意点：
- 输入验证：确保用户输入的是有效的整数，以避免意外行为。
- 循环终止条件：注意设置适当的循环终止条件，避免死循环或无意义的循环。
*/

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    cout << "Enter an integer: ";  // 提示用户输入一个整数
    int by;
    cin >> by;  // 读取用户输入的整数
    cout << "Counting by " << by << endl;  // 显示计数的步长

    for (int i = 0; i < 100; i += by) {  // 循环从0开始，每次增加by，直到小于100
        cout << i << endl;  // 输出当前的循环变量i
    }

    return 0;
}
