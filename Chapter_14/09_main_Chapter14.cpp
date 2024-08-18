#include <string>
#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * 1. 类模板：`Pair` 是一个类模板，支持两个不同类型的成员变量 `a` 和 `b`。
 * 2. 构造函数：`Pair` 使用带参数的构造函数初始化两个成员变量。
 * 3. 成员函数模板：通过成员函数模板 `first()` 和 `second()`，可以访问和修改对象的成员变量。
 * 4. 模板类的数组：在 `main` 函数中，使用模板类创建了一个包含多个 `Pair<string, int>` 对象的数组 `rating`。

 * 注意点：
 * 1. 成员变量的初始化：在类模板的构造函数中，使用初始化列表初始化模板类型的成员变量。
 * 2. 成员函数的重载：`first()` 和 `second()` 成员函数分别有常量版本和非常量版本，确保在不同情况下都能正确访问成员变量。
 * 3. 数组大小计算：通过 `sizeof` 计算数组的元素数量时，要注意模板类型的数组大小计算方式。
 */

template <class T1, class T2>
class Pair {
private:
    T1 a; // 成员变量 a，类型为 T1
    T2 b; // 成员变量 b，类型为 T2
public:
    // 构造函数，使用初始化列表初始化成员变量 a 和 b
    Pair(const T1& aVal, const T2& bVal) : a(aVal), b(bVal) {}

    // 非常量版本的成员函数，返回 a 的引用
    T1& first();

    // 非常量版本的成员函数，返回 b 的引用
    T2& second();

    // 常量版本的成员函数，返回 a 的值
    T1 first() const { return a; }

    // 常量版本的成员函数，返回 b 的值
    T2 second() const { return b; }
};

// 成员函数定义：返回 a 的引用，允许修改
template <class T1, class T2>
T1& Pair<T1, T2>::first() {
    return a;
}

// 成员函数定义：返回 b 的引用，允许修改
template <class T1, class T2>
T2& Pair<T1, T2>::second() {
    return b;
}

int main() {
    // 创建一个包含4个 Pair<string, int> 对象的数组
    Pair<string, int> rating[4] = {
            Pair<string, int>("Duck", 5),
            Pair<string, int>("Fresco", 4),
            Pair<string, int>("Cafe", 5),
            Pair<string, int>("East", 3)
    };

    // 计算数组中的元素个数
    int joints = sizeof(rating) / sizeof(Pair<string, int>);

    // 输出数组中的每个 Pair 对象的 second 和 first 成员变量的值
    for (int i = 0; i < joints; ++i) {
        cout << rating[i].second() << ":\t" << rating[i].first() << endl;
    }

    // 修改第四个 Pair 对象的 first 和 second 成员变量的值
    rating[3].first() = "Fab";
    rating[3].second() = 6;

    // 输出修改后的值
    cout << rating[3].second() << ":\t" << rating[3].first() << endl;

    return 0;
}