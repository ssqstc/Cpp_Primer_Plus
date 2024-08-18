#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * 1. 友元模板函数：模板类 `ManyFriend` 中定义了一个友元模板函数 `show2`，该函数可以访问 `ManyFriend` 实例的私有成员。
 * 2. 模板参数的多样性：`show2` 函数可以接受不同类型的模板实例作为参数，并且可以访问它们的私有数据成员。
 * 3. 泛型编程的灵活性：利用模板函数和友元关系，可以在不同类型的实例之间进行灵活的数据访问和操作。

 * 注意点：
 * 1. 友元函数访问：模板类的友元函数可以访问类的私有成员，但需要确保在函数定义时模板参数正确匹配。
 * 2. 函数模板实例化：在 `main` 函数中，通过传递不同类型的 `ManyFriend` 实例给 `show2`，展示了模板函数如何被实例化并执行。
 */

template <typename T>
class ManyFriend {
private:
    T item; // 模板类型的私有成员变量
public:
    ManyFriend(const T& i) : item(i) {} // 构造函数，初始化私有成员

    // 友元模板函数声明，可以访问 `ManyFriend` 类的私有成员
    template <typename C, typename D>
    friend void show2(C&, D&);
};

// 友元模板函数定义，可以访问 `ManyFriend` 实例的私有成员 `item`
template <typename C, typename D>
void show2(C& c, D& d) {
    cout << c.item << ", " << d.item << endl; // 访问并输出两个 `ManyFriend` 实例的 `item` 值
}

int main() {
    ManyFriend<int> hfi1(10);        // 创建 `ManyFriend<int>` 实例
    ManyFriend<int> hfi2(20);        // 创建另一个 `ManyFriend<int>` 实例
    ManyFriend<double> hfd1(10.5);   // 创建 `ManyFriend<double>` 实例

    cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2); // 调用友元模板函数，传入两个相同类型的实例

    cout << "hfd1: ";
    show2(hfd1, hfi1); // 调用友元模板函数，传入两个不同类型的实例

    return 0;
}