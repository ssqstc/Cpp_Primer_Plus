#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 动态分配内存：
   - 使用 `new` 运算符为数组动态分配内存，使用 `delete[]` 释放内存，避免内存泄漏。
2. 字符串操作：
   - 使用 `strcpy` 函数复制字符串到结构体的字符数组成员。
3. 结构体数组操作：
   - 通过指针操作结构体数组的成员，使用箭头操作符 `->` 和数组下标 `[]` 进行访问。
*/

struct CandyBar
{
    char brand[20];  // 品牌
    double weight;   // 重量
    int calories;    // 卡路里
};

int main()
{
    // 动态分配内存，创建包含3个CandyBar的数组
    CandyBar *pointer = new CandyBar[3];

    // 初始化第一个CandyBar
    strcpy(pointer[0].brand, "Mocha Munch 1");
    pointer[0].weight = 1.3;
    pointer[0].calories = 150;

    // 初始化第二个CandyBar
    strcpy(pointer[1].brand, "Mocha Munch 2");
    pointer[1].weight = 2.3;
    pointer[1].calories = 250;

    // 初始化第三个CandyBar
    strcpy(pointer[2].brand, "Mocha Munch 3");
    pointer[2].weight = 3.3;
    pointer[2].calories = 350;

    // 输出第一个CandyBar的信息
    cout << "pointer[0] brand: " << pointer->brand << " ,pointer[0] weight: " << pointer->weight << " ,pointer[0] calories: " << pointer->calories << endl;

    // 输出第二个CandyBar的信息
    cout << "pointer[1] brand: " << pointer[1].brand << " ,pointer[1] weight: " << pointer[1].weight << " ,pointer[1] calories: " << pointer[1].calories << endl;

    // 输出第三个CandyBar的信息
    cout << "pointer[2] brand: " << pointer[2].brand << " ,pointer[2] weight: " << pointer[2].weight << " ,pointer[2] calories: " << pointer[2].calories << endl;

    delete[] pointer;  // 释放动态分配的内存

    return 0;  // 程序结束
}
