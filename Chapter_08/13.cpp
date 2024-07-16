#include "iostream"
using namespace std;

/*
这个程序展示了C++中的模板函数和模板特化的使用。
主要知识点和注意事项：
1. 函数模板的定义和基本语法。
2. 模板函数的特化。
3. 引用参数的传递方式。
4. 结构体的定义和使用。

注意：
1. 模板特化用于处理特定类型的特殊情况。
2. 对于复杂数据类型，需要显式定义如何进行交换操作。
*/

// 定义结构体 job，用于存储员工信息
struct job{
    char name[40];
    double salary;
    int floor;
};

// 模板函数的定义，用于交换两个同类型变量的值
template <typename T>
void Swap(T &a, T &b);

// 模板特化，用于交换两个 job 类型变量的特定实现
template <>
void Swap<job>(job &j1, job &j2);

// 显示 job 结构体内容的函数
void show(job &j);

int main(){
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << "." << endl;
    Swap(i, j); // 交换整数变量 i 和 j 的值
    cout << "After swap, now i, j = " << i << ", " << j << "." << endl;

    double x = 24.5, y = 81.7;
    cout << "x, y = " << x << ", " << y << "." << endl;
    Swap(x, y); // 交换双精度浮点数变量 x 和 y 的值
    cout << "After swap, now x, y = " << x << ", " << y << "." << endl;

    job Rick = {"Rick", 1000, 10}; // 定义并初始化 job 结构体变量 Rick
    job Jack = {"Jack", 1100, 11}; // 定义并初始化 job 结构体变量 Jack
    show(Rick); // 显示 Rick 的信息
    show(Jack); // 显示 Jack 的信息
    Swap(Rick, Jack); // 交换 Rick 和 Jack 的 salary 和 floor
    cout << "After swap: " << endl;
    show(Rick); // 显示交换后的 Rick 信息
    show(Jack); // 显示交换后的 Jack 信息
    return 0;
}

// 模板函数的定义，用于交换两个同类型变量的值
template <typename T>
void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

// 模板特化，用于交换两个 job 类型变量的特定实现
template <>
void Swap<job>(job &j1, job &j2){
    double t1; // 临时变量，用于交换 salary
    int t2; // 临时变量，用于交换 floor
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

// 显示 job 结构体内容的函数
void show(job &j){
    cout << j.name << ": " << j.salary << " on floor " << j.floor << endl; // 输出 job 信息
}
