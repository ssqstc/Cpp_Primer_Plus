#include "iostream"
using namespace std;

/*
知识点：
1. 函数重载：定义了两个同名的 left 函数，一个处理字符串，一个处理整数。
2. 动态内存分配：在 left 函数中使用 new 运算符为字符串分配内存。
3. 指针操作：使用指针操作字符数组，处理字符串。
4. 位操作：通过不断除以 10 的方式获取整数的前几位。
5. 常量指针：函数参数中使用 const char*，表示指向常量字符的指针，防止修改传入的字符串。

注意点：
1. 内存管理：动态分配内存后，需要在适当时候使用 delete 释放，防止内存泄漏。
2. 指针边界：处理字符串时需注意不要越界，尤其是在复制字符串时。
3. 类型转换：在处理不同类型的数据时，需注意数据类型的转换和范围。
4. 默认参数：left 函数中 n 的默认参数为 1，调用时可省略。
*/

const int ArSize = 80; // 定义常量数组大小

char *left(const char *str, int n = 1);     // 处理字符串的函数原型，默认参数 n 为 1
unsigned long left(unsigned long num, unsigned int ct); // 处理整数的函数原型

int main(){
    const char *trip = "Hawaii"; // 定义字符串常量
    unsigned long n = 12345678; // 定义整数变量
    int i;
    char *temp;

    // 循环处理并输出结果
    for (i = 0; i < 10; i++) {
        cout << left(n, i) << endl; // 输出整数前 i 位
        temp = left(trip, i); // 获取字符串前 i 个字符
        cout << temp << endl; // 输出获取的字符串
        delete []temp; // 释放动态分配的内存
    }

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

// 函数定义：返回整数的前 ct 位
unsigned long left(unsigned long num, unsigned int ct){
    unsigned long n = num;   // 临时保存原始数值
    int count = 1;           // 计数器初始化

    // 处理特殊情况
    if (0 == num || 0 == ct){
        return 0;
    }

    // 计算数字的总位数
    while (n /= 10){
        ++count;
    }

    // 若要求的位数少于实际位数
    if (count > ct){
        ct = count - ct;
        while (ct--){
            num /= 10;
        }
        return num;
    } else {
        return num;
    }
}
