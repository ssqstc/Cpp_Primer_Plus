#include <iostream>
#include <exception>
using namespace std;

/*
  知识点总结：
  1. `cin.exceptions(ios_base::failbit)`：此函数用于设置输入流的异常掩码。当遇到输入失败（如非数字输入）时，抛出 `ios_base::failure` 异常。
  2. 异常处理：通过 `try-catch` 捕获 `cin` 抛出的异常，避免程序崩溃并提供错误处理逻辑。
  3. `ios_base::failbit`：表示输入流遇到格式错误（例如非数字输入时），`cin` 会进入错误状态并设置该标志。

  注意点：
  1. `cin.exceptions()` 用于捕获输入错误，不使用时只会导致循环终止，不会抛出异常。在启用后，异常需要通过 `try-catch` 来处理。
  2. `cin` 在抛出异常后会停止输入，需要在 `catch` 块中恢复流的正常状态或处理错误。
  3. 输入失败后，`input` 仍然会保留最后一次有效输入的值，但注意错误输入未被清除。
*/

int main() {
    cin.exceptions(ios_base::failbit);  // 设置cin在失败时抛出异常
    cout << "Enter number: ";  // 提示输入

    int sum = 0;    // 累加输入的数字
    int input;      // 存储当前输入的数字

    try {
        while (cin >> input) {  // 当输入成功时继续读取
            sum += input;  // 累加输入的数字
        }
    } catch (ios_base::failure& bf) {  // 捕获输入失败抛出的异常
        cout << bf.what() << endl;  // 输出异常信息
        cout << "O! the horror!\n";  // 输出错误提示
    }

    // 输出最后一次成功输入的值和总和
    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}