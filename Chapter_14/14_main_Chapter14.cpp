#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * 1. 模板类中的友元函数：通过友元模板函数，使外部函数可以访问模板类的私有成员，如 `counts` 和 `reports`。
 * 2. 静态成员变量：模板类中的静态成员变量 `ct` 是模板类的每个类型实例独立的，因此不同类型的实例不会共享静态成员。
 * 3. 模板特化：在使用友元函数时，必须显式指定模板参数类型，确保友元函数可以访问特定实例的私有数据。

 * 注意点：
 * 1. 友元函数的声明：在模板类中声明友元函数时，需要使用模板参数进行声明，以确保友元函数可以正确访问模板类的私有成员。
 * 2. 静态成员的初始化：静态成员变量 `ct` 需要在类定义外进行初始化，每个类型的 `HasFriend` 实例都有独立的 `ct`。
 * 3. 泛型友元函数的使用：`counts` 和 `reports` 是泛型函数，分别用于计数和报告模板实例的私有成员值。

 */

template <typename T> void counts();            // 友元函数模板声明，用于计数
template <typename U> void reports(U& u);       // 友元函数模板声明，用于报告

// 模板类定义
template <typename V>
class HasFriend {
private:
    V item;                      // 模板类型的私有成员变量
    static int ct;               // 静态成员变量，计数实例数量
public:
    HasFriend(const V& v) : item(v) { ct++; }  // 构造函数，创建实例时计数器加 1
    ~HasFriend() { ct--; }       // 析构函数，销毁实例时计数器减 1

    // 友元函数声明，允许访问私有成员
    friend void counts<V>();     // 计数函数模板作为友元函数
    friend void reports<HasFriend<V>>(HasFriend<V>& hf);  // 报告函数模板作为友元函数
};

// 静态成员变量初始化，每个类型实例化都有独立的 `ct`
template <typename V>
int HasFriend<V>::ct = 0;

// 友元函数模板定义，输出模板类实例的数量
template <typename T>
void counts() {
    cout << "count: " << HasFriend<T>::ct << endl;
}

// 友元函数模板定义，输出模板类实例的 `item` 值
template <typename U>
void reports(U& u) {
    cout << u.item << endl;  // 访问模板类的私有成员 `item`
}

int main() {
    cout << "No objects declared: ";
    counts<int>();  // 输出 `HasFriend<int>` 实例数量

    HasFriend<int> hfi1(10);   // 创建 `HasFriend<int>` 实例
    cout << "After hfi1 declared: ";
    counts<int>();  // 输出 `HasFriend<int>` 实例数量
    reports(hfi1);  // 输出 `hfi1` 的 `item` 值

    HasFriend<int> hfi2(20);   // 创建第二个 `HasFriend<int>` 实例
    cout << "After hfi2 declared: ";
    counts<int>();  // 输出 `HasFriend<int>` 实例数量
    reports(hfi2);  // 输出 `hfi2` 的 `item` 值

    HasFriend<double> hfd1(0.5);   // 创建 `HasFriend<double>` 实例
    cout << "After hfd1 declared: ";
    counts<double>();  // 输出 `HasFriend<double>` 实例数量
    reports(hfd1);  // 输出 `hfd1` 的 `item` 值

    return 0;
}