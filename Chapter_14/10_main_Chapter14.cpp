#include <iostream>
using namespace std;

/*
 * 知识点总结：
 * 1. 模板显式实例化：通过 `template class A<double, double>;` 语句对模板进行显式实例化，生成指定类型的模板类实例。
 * 2. 模板显示具体化：通过 `template <> class A<int, int>` 显式具体化模板，为特定类型组合提供特殊定义。
 * 3. 模板部分具体化：通过 `template <class T1> class A<T1, int>` 实现部分具体化，当模板参数部分已知时定义专门的处理。
 * 4. 隐式实例化：在未显式实例化或具体化时，编译器根据使用情况自动生成模板类实例。

 * 注意点：
 * 1. 模板的显式实例化和具体化：注意显式实例化和具体化的语法格式，确保正确指定需要特化的类型组合。
 * 2. 部分具体化的使用场景：在部分具体化时，需明确哪些模板参数是固定的，哪些是通用的，以便为特定组合提供优化的实现。
 */

template <class T1, class T2>
class A {
public:
    // 通用模板定义的成员函数，适用于未具体化的模板实例
    void show();
};

// 定义通用模板的成员函数
template <class T1, class T2>
void A<T1, T2>::show() {
    cout << "use general definition" << endl;
}

// 显式实例化模板类，指定类型为 double, double
template class A<double, double>;

// 显式具体化模板类，特化类型为 int, int
template <>
class A<int, int> {
public:
    // 具体化后的成员函数
    void show();
};

// 定义具体化后的成员函数
void A<int, int>::show() {
    cout << "use specialized definition" << endl;
}

// 部分具体化模板类，特化类型为 T1, int
template <class T1>
class A<T1, int> {
public:
    // 部分具体化后的成员函数
    void show();
};

// 定义部分具体化后的成员函数
template <class T1>
void A<T1,int>::show() {
    cout << "use partial specialized definition" << endl;
}

int main() {
    // 隐式实例化，使用通用模板定义
    A<char, char> a1;
    a1.show();

    // 显示具体化，使用特化的模板定义
    A<int, int> a2;
    a2.show();

    // 部分具体化，使用部分特化的模板定义
    A<char, int> a3;
    a3.show();

    return 0;
}