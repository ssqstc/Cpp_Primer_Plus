#include "iostream"
#include "cstring" // 为了使用 strcpy 函数
using namespace std;

/*
这个程序展示了结构体的使用、默认参数的设置和引用参数的传递。
主要知识点和注意事项：
1. 结构体的定义和使用。
2. 使用默认参数简化函数调用。
3. 使用引用参数避免值传递带来的开销。

注意：
1. 默认参数在函数声明时设置，可以在调用时省略。
2. 引用参数可以直接修改原始数据，而不会产生副本。
3. 确保在包含字符串操作的头文件 <cstring>。
*/

// 常量定义
const int SIZE = 30;

// 结构体定义
struct CandyBar{
    char name[SIZE];  // 糖果名称
    double weight;    // 糖果重量
    int heat;         // 糖果热量
};

// 函数声明，带有默认参数
void set_CandyBar(CandyBar &cb, const char name[] = "Millennium Munch", double weight = 28.5, int calories = 350);

// 显示 CandyBar 内容的函数
void show_CandyBar(const CandyBar &cb);

int main(){
    CandyBar cb{}; // 定义一个 CandyBar 结构体变量
    set_CandyBar(cb); // 使用默认参数调用函数
    show_CandyBar(cb); // 显示 CandyBar 的信息

    return 0;
}

// 设置 CandyBar 内容的函数定义
void set_CandyBar(CandyBar &cb, const char name[], double weight, int calories){
    strcpy(cb.name, name); // 使用 strcpy 复制字符串到结构体成员
    cb.weight = weight; // 设置重量
    cb.heat = calories; // 设置热量
}

// 显示 CandyBar 内容的函数定义
void show_CandyBar(const CandyBar &cb){
    cout << "name = " << cb.name << endl; // 输出名称
    cout << "weight = " << cb.weight << endl; // 输出重量
    cout << "calories = " << cb.heat << endl; // 输出热量
}
