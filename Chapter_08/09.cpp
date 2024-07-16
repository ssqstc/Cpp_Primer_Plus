#include "iostream"
using namespace std;

const int ArSize = 80;
char *left(const char *str, int n = 1);     // 声明带有默认参数的函数

int main(){
    char sample[ArSize];
    cout << "Enter a string: " << endl;
    cin.get(sample, ArSize); // 读取用户输入的字符串

    char *ps = left(sample, 400); // 请求前400个字符（超出实际字符串长度）
    cout << ps << endl;
    delete []ps; // 释放动态分配的内存

    ps = left(sample); // 请求前1个字符（默认值）
    cout << ps << endl;
    delete []ps; // 释放动态分配的内存

    return 0;
}
//char *left(const char *str, int n){
//    if (n < 0){
//        n = 0;
//    }
//    char *p = new char[n + 1];
//    int i;
//    for (i = 0; i < n && str[i]; ++i) {     // 不能超出str指向字符串大小 判断str[i]元素值 char字符串尾字符为0即false
//        p[i] = str[i];
//    }
//    while (i <= n){     // 判断n小于字符串长度大小 将其余元素均填充为空字符
//        p[i++] = '\0';
//    }
//    return p;
//}

// 函数定义：提取并返回字符串的前 n 个字符
char *left(const char *str, int n){
    int m = 0;
    // 计算实际需要的字符数（最小值为 n 和字符串长度的最小值）
    while (m < n && str[m] != '\0'){
        m++;
    }
    char *p = new char[m + 1]; // 分配内存，+1 用于终止字符 '\0'
    int i;
    for (i = 0; i < m; ++i) {
        p[i] = str[i];
    }
    p[i] = '\0'; // 添加终止字符
    return p;
}