#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * 1. 模板嵌套：在类模板 `Beta` 中嵌套了另一个类模板 `hold`。这展示了模板的灵活性，可以在一个模板类中嵌套另一个模板类。
 * 2. 模板类型推导：模板 `Beta` 的类型参数 `T` 可以用于嵌套模板 `hold` 的类型推导，且可以与 `hold<int>` 一起使用不同的类型。
 * 3. 成员模板：`Beta` 类中的 `blab` 函数是一个成员模板，能够在模板类中使用不同类型的参数。该成员模板展示了模板的多态性。

 * 注意点：
 * 1. 在模板嵌套中，内层模板的定义和使用要注意类型的传递和推导。
 * 2. 使用成员模板时，返回值类型和参数类型的匹配关系要明确。
 * 3. `blab` 函数的计算逻辑依赖于模板参数，需确保参数类型支持相关操作，如加法、乘法和除法等。
 */

template <typename T>
class Beta {
private:
    // 嵌套类模板 hold，用于存储值
    template <typename V>
    class hold {
    private:
        V val;  // 存储类型为 V 的值
    public:
        // 构造函数初始化 val，默认值为 0
        hold(V v = 0) : val(v) {}

        // 显示存储的值
        void v_show() const { cout << val << endl; }

        // 返回存储的值
        V value() const { return val; }
    };

    hold<T> q;     // 使用外部模板参数 T 实例化 hold
    hold<int> n;   // 使用 int 类型实例化 hold
public:
    // 构造函数，使用 T 和 int 初始化 q 和 n
    Beta(T t, int i) : q(t), n(i) {}

    // 显示 q 和 n 的值
    void b_show() const { q.v_show(); n.v_show(); }

    // 成员模板函数，接受 U 类型参数，并使用 T 类型参与计算
    template <typename U>
    U blab(U u, T t) {
        return (q.value() + n.value()) * u / t;
    }
};

int main() {
    // 创建 Beta<double> 对象，T 类型为 double
    Beta<double> guy(3.5, 3);
    cout << "T was set to double" << endl;
    guy.b_show();  // 显示 q 和 n 的值

    cout << "V == T, they are all double" << endl;
    cout << "U was set to int, so output value is int type" << endl;
    cout << guy.blab(10, 2.3) << endl;  // U 类型为 int，进行计算并输出结果

    cout << "U was set to double, so output value is double type" << endl;
    cout << guy.blab(10.0, 2.3) << endl;  // U 类型为 double，进行计算并输出结果

    return 0;
}