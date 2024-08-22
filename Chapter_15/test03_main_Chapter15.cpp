/*
知识点总结:
1. **继承与多态**：使用继承来创建自定义异常类 `bad_mean`，并派生出特定的异常类 `bad_hmean` 和 `bad_gmean`，演示了多态性的应用。
2. **异常处理**：通过 `try-catch` 结构捕获基类 `bad_mean` 的异常对象，利用 `typeid` 进行类型检查，以处理不同的异常类型。
3. **虚函数与覆盖**：基类 `bad_mean` 提供了虚函数 `show`，派生类通过 `override` 关键字覆盖该函数，以实现不同的错误显示方式。

注意点:
1. **`typeid`的使用**：使用 `typeid` 进行类型比较时，需要确保类型比较的逻辑是正确的，且注意捕获顺序，避免捕获更泛化的异常导致更具体的异常被忽略。
2. **虚函数覆盖**：在派生类中使用 `override` 关键字覆盖基类虚函数时，需要保证函数签名的一致性。
3. **异常的传递与处理**：抛出异常时，确保传递有意义的参数，并在捕获异常时进行相应的处理。
*/

#include <iostream>  // 标准输入输出流库
#include <stdexcept>  // 标准异常库
using namespace std;

double hmean(double a, double b);  // 函数声明：计算调和平均数
double gmean(double a, double b);  // 函数声明：计算几何平均数

// 基类 bad_mean，继承自 std::logic_error，保存两个出错的数值 v1 和 v2
class bad_mean : public logic_error {
private:
    double v1;  // 错误的第一个数值
    double v2;  // 错误的第二个数值
public:
    // 构造函数，初始化错误数值及错误信息
    bad_mean(double a = 0, double b = 0, const string& what_arg = "mean, error") : v1(a), v2(b), logic_error(what_arg) {}
    virtual void show() const;  // 虚函数，用于显示错误信息
};
inline void bad_mean::show() const {
    cout << "v1 = " << v1 << ", v2 = " << v2 << endl;  // 显示错误数值
}

// 派生类 bad_hmean，继承自 bad_mean，用于表示调和平均数的无效参数错误
class bad_hmean : public bad_mean {
public:
    // 构造函数，初始化基类和错误信息
    bad_hmean(double a = 0, double b = 0, const string& what_arg = "hmean, invalid arguments") : bad_mean(a, b, what_arg) {}
    void show() const override;  // 覆盖基类的 show 函数
};
inline void bad_hmean::show() const {
    cout << what() << endl;  // 显示错误信息
    bad_mean::show();  // 调用基类的 show 函数显示错误数值
}

// 派生类 bad_gmean，继承自 bad_mean，用于表示几何平均数的无效参数错误
class bad_gmean : public bad_mean {
public:
    // 构造函数，初始化基类和错误信息
    bad_gmean(double x, double y, const string& what_arg = "gmean, invalid arguments") : bad_mean(x, y, what_arg) {}
    void show() const override;  // 覆盖基类的 show 函数
};
inline void bad_gmean::show() const {
    cout << what() << endl;  // 显示错误信息
    bad_mean::show();  // 调用基类的 show 函数显示错误数值
}

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
        catch(bad_mean& b) {  // 捕获 bad_mean 异常
            if (typeid(bad_hmean) == typeid(b)) {  // 检查是否是 bad_hmean 类型的异常
                b.show();  // 显示异常信息
                break;  // 退出循环
            }
            if (typeid(bad_gmean) == typeid(b)) {  // 检查是否是 bad_gmean 类型的异常
                b.show();  // 显示异常信息
                break;  // 退出循环
            }
        }
        cout << "Enter next set of number: ";  // 提示用户输入下一组数
    }
    return 0;
}

// hmean 函数的定义，用于计算调和平均数。如果参数 a 和 b 相反，则抛出 bad_hmean 异常
double hmean(double a, double b) {
    if (a == -b) {  // 检查是否 a 和 b 是相反数
        throw bad_hmean(a, b);  // 抛出 bad_hmean 异常
    }
    return 2.0 * a * b / (a + b);  // 计算并返回调和平均数
}

// gmean 函数的定义，用于计算几何平均数。如果参数 a 或 b 为负数，则抛出 bad_gmean 异常
double gmean(double a, double b) {
    if (a < 0 || b < 0) {  // 检查是否存在负数
        throw bad_gmean(a, b);  // 抛出 bad_gmean 异常
    }
    return sqrt(a * b);  // 计算并返回几何平均数
}