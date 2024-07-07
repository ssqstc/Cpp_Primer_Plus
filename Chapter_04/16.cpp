#include "iostream"
using namespace std;

int main()
{
    char animal[20] = "bear"; // 定义一个字符数组并初始化为 "bear"
    const char *bird = "wren"; // 定义一个指向字符串常量的指针
    char *ps; // 未初始化的字符指针

    cout << animal << " and " << bird << endl; // 输出 "bear and wren"

    cout << "Enter a kind of animal: ";
//    cin >> bird; // 不可通过字符串常量指针来改变字符串常量
    cin >> animal; // 将输入的字符串赋值给 animal 数组
    cout << animal << endl;
//    cin >> ps ; // ps 指向一个未知的内存区域，这会导致野指针
//    cout << ps << endl; // ps 是野指针，输出会导致未定义行为

    ps = animal; // ps 指向 animal 数组
    cout << ps << endl; // 输出 animal 数组的内容
    cout << animal << " location: " << (int*) animal << endl; // 输出 animal 数组的地址
    cout << ps << " location: " << (int*) ps << endl; // 输出 ps 指针的地址

    cout << "After using strcpy\n";
    ps = new char[strlen(animal) + 1]; // 动态分配内存以存储 animal 的内容
    strcpy(ps, animal); // 将 animal 的内容复制到 ps 所指向的内存
    cout << animal << " location: " << (int*) animal << endl; // 输出 animal 数组的地址
    cout << ps << " location: " << (int*) ps << endl; // 输出 ps 指针的地址

    delete [] ps; // 释放动态分配的内存

    return 0;
}
