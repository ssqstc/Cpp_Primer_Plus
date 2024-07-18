#include <iostream>
#include "test01_head_Chapter09.h"
using namespace std;

/*
 * 知识点总结：
 * - 数组：用于存储多个相同类型的元素。
 * - 结构体：自定义数据类型，包含多个不同类型的成员。
 * - 输入输出流：使用 `cin` 和 `cout` 进行数据输入和输出。
 * - 字符串处理：使用 `strcpy` 和 `strcmp` 进行字符串操作。
 *
 * 注意点：
 * - `cin.getline` 读取字符串输入，防止缓冲区溢出。
 * - `cin.get` 用于读取并丢弃输入缓冲区中的字符，避免后续输入错误。
 * - 结构体数组的初始化和遍历。
 */

const int SIZE = 2; // 定义数组大小

int main(){
    golf gf[SIZE]; // 定义 golf 结构体数组
    int count = 0; // 初始化计数器

    cout << "Please enter the information of golf players: " << endl; // 提示输入高尔夫球员信息
    while ((count < SIZE) && setgolf(gf[count]) != 0){
        cout << "Please enter next player: " << endl; // 提示输入下一个球员信息
        ++count;
    }

    cout << "\nShow all golf players information: " << endl; // 显示所有球员信息
    for (int i = 0; i < count; ++i) {
        showgolf(gf[i]); // 显示单个球员信息
    }

    cout << "\nReset all the players information: " << endl; // 重置所有球员信息
    for (int i = 0; i < count; ++i) {
        handicap(gf[i], 90); // 设置新的 handicap 值
        showgolf(gf[i]); // 显示重置后的球员信息
    }
    return 0;
}