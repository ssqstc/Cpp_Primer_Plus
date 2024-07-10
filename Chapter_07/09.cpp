#include "iostream"
using namespace std;

unsigned int c_in_str(const char *str, char ch);
int main(){
    char mmm[15] = "minimum";
    const char *wail = "ululate";   // "ululate"是一个字符串常量    要用const修饰    char *wail = (char*)"ululate";

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');

    cout << ms << " m character in " << mmm << endl;
    cout << us << " u character in " << wail << endl;
    return 0;
}
unsigned int c_in_str(const char *str, char ch){
    int count = 0;
    while (*str){  // 判断当前字符是否为'\0'
        if (*str == ch){
            count++;
        }
        str++;
    }
    return count;
}