#include "iostream"
using namespace std;

/*
知识点：
1. 函数重载：定义了两个同名的 left 函数，一个处理字符串，一个处理整数。
2. 动态内存分配：在 left 函数中使用 new 运算符为字符串分配内存。
3. 指针操作：使用指针操作字符数组，处理字符串。
4. 输入处理：使用 cin.get 获取带空格的字符串输入。

注意点：
1. 内存管理：动态分配内存后，需要在适当时候使用 delete 释放，防止内存泄漏。
2. 指针边界：处理字符串时需注意不要越界，尤其是在复制字符串时。
3. 类型转换：在处理不同类型的数据时，需注意数据类型的转换和范围。
4. 默认参数：left 函数中 n 的默认参数为 1，调用时可省略。
*/

const int ArSize = 80; // 定义常量数组大小
char *left(const char *str, int n = 1); // 处理字符串的函数原型，默认参数 n 为 1

int main(){
    char sample[ArSize]; // 定义字符数组
    cout << "Enter a string: " << endl;
    cin.get(sample, ArSize); // 获取用户输入的字符串

    char *ps = left(sample, 400); // 获取字符串的前 400 个字符
    cout << ps << endl; // 输出截取的字符串
    delete []ps; // 释放动态分配的内存

    ps = left(sample); // 获取字符串的前 1 个字符（默认参数）
    cout << ps << endl; // 输出截取的字符串
    delete []ps; // 释放动态分配的内存

    return 0;
}

// 函数定义：返回字符串的前 n 个字符
char *left(const char *str, int n){
    int m = 0; // 计数器初始化
    while (m < n && str[m] != '\0'){ // 计算实际需要的字符数
        m++;
    }
    char *p = new char[m + 1]; // 动态分配内存
    int i;
    for (i = 0; i < m; ++i) { // 复制前 m 个字符
        p[i] = str[i];
    }
    p[i] = '\0'; // 添加字符串结束符
    return p; // 返回新字符串指针
}
