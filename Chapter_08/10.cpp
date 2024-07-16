#include "iostream"
using namespace std;

const int ArSize = 80;
char *left(const char *str, int n = 1);     // 函数声明：字符串处理，默认参数为1
unsigned long left(unsigned long num, unsigned int ct); // 函数声明：整型处理

int main(){
    const char *trip = "Hawaii"; // 定义字符串 trip
    unsigned long n = 12345678; // 定义无符号长整型数 n
    int i;
    char *temp;

    for (i = 0; i < 10; i++) {
        // 循环调用并输出 left 函数结果
        cout << left(n, i) << endl; // 输出取前 i 位后的数字
        temp = left(trip, i);
        cout << temp << endl; // 输出取前 i 个字符后的字符串
        delete []temp; // 释放动态分配的内存
    }

    return 0;
}

// 定义字符串取前几位函数
char *left(const char *str, int n){
    int m = 0;    // 初始化计数器为0
    while (m < n && str[m] != '\0'){
        // 计算字符串前n个字符的实际长度
        m++;
    }
    char *p = new char[m + 1];
    // 分配新的字符数组内存，比实际长度多1以存放终止符
    int i;
    for (i = 0; i < m; ++i) {
        // 复制前m个字符到新数组
        p[i] = str[i];
    }
    p[i] = '\0';  // 添加字符串终止符
    return p;     // 返回新的字符串
}

// 定义整形取前几位函数
unsigned long left(unsigned long num, unsigned int ct){
    unsigned long n = num;   // 将传入参数赋值给n，方便后续操作
    int count = 1;           // 初始化整形位数计数器为1
    if (0 == num || 0 == ct){
        // 如果传入的数字为0，或者需要取的位数为0，则直接返回0
        return 0;
    }
    while (n /= 10){
        // 将n除以10，去掉最低位，同时计数器加1，得出整形的位数
        ++count;
    }
    if (count > ct){
        // 如果数字的位数大于需要取的位数
        ct = count - ct;
        // 计算需要去掉的位数
        while (ct--){
            // 去掉多余的位数
            num /= 10;
        }
        return num;
        // 返回处理后的数字
    } else {
        return num;
        // 如果数字的位数不大于需要取的位数，直接返回原数字
    }
}
