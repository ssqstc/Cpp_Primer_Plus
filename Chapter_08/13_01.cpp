#include "iostream"
using namespace std;

/*
这个程序展示了C++中函数调用优先级的知识点。
主要知识点和注意事项：
1. 函数重载、模板函数和模板特化的定义与使用。
2. 当存在函数重载和模板函数时，编译器优先选择重载函数。
3. 当模板特化与模板函数都匹配时，优先选择模板特化。

注意：
1. 函数重载允许多个同名函数根据不同的参数列表进行定义。
2. 模板特化用于处理特定类型的特殊情况。
3. 理解函数调用的优先级有助于避免错误调用。
*/

// 定义结构体 job，用于存储员工信息
struct job{
    char name[40];
    double salary;
    int floor;
};

// 函数重载：定义一个用于交换两个整数的函数
void Swap(int a, int b);

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
    Swap(i, j); // 调用重载的 Swap 函数，只输出交换后的值，没有实际交换
    cout << "After swap, now i, j = " << i << ", " << j << "." << endl;

    double x = 24.5, y = 81.7;
    cout << "x, y = " << x << ", " << y << "." << endl;
    Swap(x, y); // 调用模板函数 Swap，实际交换双精度浮点数变量 x 和 y 的值
    cout << "After swap, now x, y = " << x << ", " << y << "." << endl;

    job Rick = {"Rick", 1000, 10}; // 定义并初始化 job 结构体变量 Rick
    job Jack = {"Jack", 1100, 11}; // 定义并初始化 job 结构体变量 Jack
    show(Rick); // 显示 Rick 的信息
    show(Jack); // 显示 Jack 的信息
    Swap(Rick, Jack); // 调用模板特化函数 Swap，交换 Rick 和 Jack 的 salary 和 floor
    cout << "After swap: " << endl;
    show(Rick); // 显示交换后的 Rick 信息
    show(Jack); // 显示交换后的 Jack 信息
    return 0;
}

// 函数重载：定义一个用于交换两个整数的函数
void Swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "Hello world, a = " << a << ", b = " << b << endl; // 输出交换后的值
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
