#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 数组：使用字符串数组存储用户输入的数据。
 * 2. 函数：定义并调用函数显示数组内容。
 * 3. 输入输出：使用getline函数读取完整的字符串输入。
 *
 * 注意点：
 * 1. 输入处理：使用getline处理带空格的输入，确保完整读取每行输入。
 * 2. 数组传递：函数参数传递数组及其大小，确保正确显示数组内容。
 */

void display(const string sa[], int n);  // 显示字符串数组内容的函数声明
const int SIZE = 5;

int main() {
    string list[SIZE];  // 定义字符串数组
    cout << "Enter " << SIZE << " favorite food: " << endl;  // 提示输入
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << ": ";  // 提示输入第i个食物
        getline(cin, list[i]);  // 使用getline读取完整输入
    }
    cout << "Your list: " << endl;  // 显示用户输入的食物列表
    display(list, SIZE);  // 调用函数显示数组内容

    return 0;
}

void display(const string sa[], int n) {  // 显示字符串数组内容的函数定义
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": " << sa[i] << endl;  // 输出数组内容
    }
}
