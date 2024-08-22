/*
知识点总结:
1. **异常处理**：使用 `try-catch` 结构捕获并处理异常，通过自定义异常类实现特定错误处理。
2. **自定义异常类**：继承标准异常类 `logic_error`，实现自定义异常类型 `bad_hmean` 和 `bad_gmean`，用于表示特定的数学错误。
3. **函数异常抛出**：在函数 `hmean` 和 `gmean` 中，当输入参数不满足特定条件时，抛出相应的自定义异常。

注意点:
1. **抛出异常**：抛出异常时，确保传递有意义的错误信息，以帮助理解错误原因。
2. **异常捕获顺序**：注意 `catch` 块的顺序，确保先捕获更具体的异常，再捕获更泛化的异常。
3. **异常的传播**：函数中抛出的异常会在调用处进行传播，未被捕获的异常会终止程序运行。
*/

#include <iostream>  // 标准输入输出流库
#include <stdexcept>  // 标准异常库
using namespace std;

double hmean(double a, double b);  // 函数声明：计算调和平均数
double gmean(double a, double b);  // 函数声明：计算几何平均数

// 自定义异常类 bad_hmean，继承自 std::logic_error，用于表示调和平均数计算中的无效参数错误
class bad_hmean : public logic_error {
public:
    bad_hmean(const string& what_arg = "hmean, invalid arguments") : logic_error(what_arg) {}
};

// 自定义异常类 bad_gmean，继承自 std::logic_error，用于表示几何平均数计算中的无效参数错误
class bad_gmean : public logic_error {
public:
    bad_gmean(const string& what_arg = "gmean, invalid arguments") : logic_error(what_arg) {}
};

int main() {
    double x, y, z;
    cout << "Enter two numbers: ";  // 提示用户输入两个数
    while (cin >> x >> y) {  // 不断读取用户输入的数对
        try {
            z = hmean(x, y);  // 尝试计算调和平均数
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            z = gmean(x, y);  // 尝试计算几何平均数
            cout << "Geometric mean of " << x << " and " << y << " is " << z << endl;
        }
        catch(bad_hmean& bh) {  // 捕获 bad_hmean 异常
            cout << bh.what() << endl;  // 输出异常信息
            cout << "Enter a new pair of arguments:";  // 提示用户输入新的数对
            continue;  // 继续循环，允许用户重新输入
        }
        catch(bad_gmean& gh) {  // 捕获 bad_gmean 异常
            cout << gh.what() << endl;  // 输出异常信息
            cout << "Sorry, quit now" << endl;  // 提示用户退出
            break;  // 终止循环，退出程序
        }
        cout << "Enter next set of number: ";  // 提示用户输入下一组数
    }
    return 0;
}

// hmean 函数的定义，用于计算调和平均数。如果参数 a 和 b 相反，则抛出 bad_hmean 异常
double hmean(double a, double b) {
    if (a == -b) {  // 检查是否 a 和 b 是相反数
        throw bad_hmean();  // 抛出 bad_hmean 异常
    }
    return 2.0 * a * b / (a + b);  // 计算并返回调和平均数
}

// gmean 函数的定义，用于计算几何平均数。如果参数 a 或 b 为负数，则抛出 bad_gmean 异常
double gmean(double a, double b) {
    if (a < 0 || b < 0) {  // 检查是否存在负数
        throw bad_gmean();  // 抛出 bad_gmean 异常
    }
    return sqrt(a * b);  // 计算并返回几何平均数
}