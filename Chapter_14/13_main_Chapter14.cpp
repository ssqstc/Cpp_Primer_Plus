#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * 1. 模板类中的静态成员：`HasFriend` 类中的静态成员 `ct` 是模板类的一个实例独有的，即 `HasFriend<int>` 和 `HasFriend<double>` 有各自独立的 `ct` 计数器。
 * 2. 友元函数：友元函数 `counts` 和 `reports` 可以访问类 `HasFriend` 的私有成员，这里展示了如何使用友元函数对模板类实例的私有成员进行访问。
 * 3. 重载友元函数：根据模板参数的不同，友元函数 `reports` 被重载以处理 `int` 和 `double` 类型的 `HasFriend` 类实例。

 * 注意点：
 * 1. 静态成员的初始化：模板类的静态成员必须在类定义外部进行初始化，这里对 `ct` 进行了静态初始化。
 * 2. 友元函数的定义：`counts` 和 `reports` 函数被定义为友元函数，使其能够访问模板类 `HasFriend` 的私有数据成员。
 * 3. 对不同类型实例的友元函数重载：注意 `reports` 函数针对 `int` 和 `double` 类型分别进行了重载。

 */

template <typename T>
class HasFriend {
private:
    T item;                  // 存储模板类型的成员变量
    static int ct;           // 静态成员变量，用于计数该模板类型的实例数量
public:
    HasFriend(const T& i) : item(i) { ct++; } // 构造函数，创建实例时计数器加 1
    ~HasFriend() { ct--; }    // 析构函数，销毁实例时计数器减 1

    // 友元函数，声明为友元以访问私有成员
    friend void counts();
    friend void reports(HasFriend<T>& hf);
};

// 静态成员初始化，每种类型的 `HasFriend` 类都有各自的 `ct`
template <typename T>
int HasFriend<T>::ct = 0;

// 友元函数 `counts`，显示 `HasFriend<int>` 和 `HasFriend<double>` 的实例计数
void counts() {
    cout << "int count: " << HasFriend<int>::ct
         << ", double count: " << HasFriend<double>::ct << endl;
}

// 友元函数 `reports` 的 `int` 类型特化，实现对 `HasFriend<int>` 的访问
void reports(HasFriend<int>& hf) {
    cout << "item: " << hf.item << endl;
}

// 友元函数 `reports` 的 `double` 类型特化，实现对 `HasFriend<double>` 的访问
void reports(HasFriend<double>& hf) {
    cout << "item: " << hf.item << endl;
}

int main() {
    cout << "No objects declared: ";
    counts();  // 没有对象时的计数输出

    HasFriend<int> hfi1(10);   // 创建 `HasFriend<int>` 实例
    cout << "After hfi1 declared: ";
    counts();  // 创建对象后的计数输出
    reports(hfi1);  // 输出 `hfi1` 的 item 值

    HasFriend<int> hfi2(20);   // 再创建一个 `HasFriend<int>` 实例
    cout << "After hfi2 declared: ";
    counts();  // 创建对象后的计数输出
    reports(hfi2);  // 输出 `hfi2` 的 item 值

    HasFriend<double> hfd1(0.5);   // 创建 `HasFriend<double>` 实例
    cout << "After hfd1 declared: ";
    counts();  // 创建对象后的计数输出
    reports(hfd1);  // 输出 `hfd1` 的 item 值

    return 0;
}