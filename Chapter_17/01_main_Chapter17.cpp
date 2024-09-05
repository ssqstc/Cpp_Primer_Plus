#include <iostream>  // 标准输入输出流库
#include <cstring>   // 包含 strlen 函数

/*
  知识点总结：
  1. `strlen` 函数：计算以 `\0` 结尾的字符串的长度，不包括 `\0`。
  2. `cout.write` 函数：按指定长度输出字符序列，适合部分字符串或二进制数据的输出。
  3. 类型转换与指针：将 `long` 类型转换为 `char*` 指针后，可以以字节形式输出 `long` 类型数据的内存表示。

  注意点：
  1. `cout.write` 超出字符串长度输出时，可能会输出未定义的内容，导致不可预测的结果。
  2. 二进制数据输出：直接输出二进制数据时，结果可能不可读，应注意数据的解释和显示方式。
*/

using namespace std;

int main() {
    const char* state1 = "Florida";   // 定义字符指针指向字符串 "Florida"
    const char* state2 = "Kansas";    // 定义字符指针指向字符串 "Kansas"
    const char* state3 = "Euphoria";  // 定义字符指针指向字符串 "Euphoria"

    int len = strlen(state2);  // 计算字符串 "Kansas" 的长度
    cout << "Increasing loop index:\n";

    // 增加索引的循环，逐渐输出字符串的前 j 个字符
    for (int j = 0; j <= len; ++j) {
        cout.write(state2, j);  // 输出字符串的前 j 个字符
        cout << endl;
    }

    cout << "Decreasing loop index:\n";

    // 减少索引的循环，逐渐输出字符串的前 j 个字符
    for (int j = len; j > 0 ; --j) {
        cout.write(state2, j) << endl;  // 输出字符串的前 j 个字符
    }

    cout << "Exceeding string length:\n";

    // 超过字符串长度的写入，会输出 "Kansas" 后面未定义的内容
    cout.write(state2, len + 5) << endl;

    cout << "----------------Dividing----------------" << endl;

    long val = 560031841;  // 定义长整型变量
    cout.write((char*)&val, sizeof(long));  // 输出该变量在内存中的二进制表示

    return 0;
}