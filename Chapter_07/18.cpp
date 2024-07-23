#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 函数指针：使用函数指针作为参数，实现对不同估算函数的调用。
 * 2. 函数调用：通过函数指针调用具体的估算函数 `Rick` 和 `Jack`。
 * 3. 简单计算：不同估算函数根据输入代码行数进行简单的时间估算。

 * 注意点：
 * 1. 函数指针的定义和使用：确保函数指针的类型和调用方式正确。
 * 2. 输入输出：处理用户输入并显示相应结果。
 * 3. 数学运算：确保估算公式的正确性。
 */

void estimate(int lines, double (*pf)(int));  // 函数指针作为参数
double Rick(int lines);  // Rick 的估算函数
double Jack(int lines);  // Jack 的估算函数

int main() {
    int code;

    cout << "How many lines of code do you need? ";  // 询问需要的代码行数
    cin >> code;
    cout << "Here is Rick's estimate: " << endl;  // 输出 Rick 的估算结果
    estimate(code, Rick);

    cout << "Here is Jack's estimate: " << endl;  // 输出 Jack 的估算结果
    estimate(code, Jack);

    return 0;
}

double Rick(int lines) {  // Rick 的估算公式
    return lines * 0.05;  // 每行代码 0.05 小时
}

double Jack(int lines) {  // Jack 的估算公式
    return 0.03 * lines + 0.0004 * lines * lines;  // 复杂的估算公式
}

void estimate(int lines, double (*pf)(int)) {  // 通过函数指针调用估算函数
    cout << lines << " lines code will take " << (*pf)(lines) << " hours." << endl;
}
