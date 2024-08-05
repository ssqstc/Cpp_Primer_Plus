#include "02_head_Chapter12.h"

/**
 * 知识点总结:
 * 1. 构造函数和析构函数: `String` 类包含默认构造函数、带参构造函数、复制构造函数和析构函数。
 * 2. 动态内存管理: 确保正确分配和释放动态内存，避免内存泄漏。
 * 3. 运算符重载: 重载了赋值运算符、比较运算符、索引运算符和输入输出运算符。
 * 4. 静态成员: 使用静态成员变量 `num_strings` 统计对象数量。
 * 5. 成员函数和友元函数: 使用成员函数和友元函数实现字符串比较和输入输出。

 * 注意点:
 * 1. 动态内存管理: 构造函数、赋值运算符和析构函数中确保动态内存的正确管理。
 * 2. 输入输出操作: 重载输入输出运算符时注意缓冲区大小和输入数据的边界检查。
 * 3. 静态成员的初始化: 静态成员变量需要在类外进行初始化。
 */

const int MAXLEN = 81;  // 最大长度
int main(){
    String name;
    cout << "Hi, what is your name?" << endl;
    cin >> name;  // 读取用户输入的名字
    cout << name << ", please enter a string: " << endl;

    String sayStrings;
    char temp[MAXLEN];  // 临时存储输入的字符串
    cin.get(temp, MAXLEN);  // 读取字符串
    while (cin && cin.get() != '\n');  // 清空输入缓冲区
    sayStrings = temp;  // 将输入字符串赋值给 sayStrings
    cout << "Here is your sayStrings: " << endl;
    cout << sayStrings[0] << ": " << sayStrings << endl;  // 输出字符串的第一个字符和整个字符串

    String str = "Hello dad";
    if (sayStrings.lenth() < str.lenth()){  // 比较字符串长度
        cout << "str is longer" << endl;
    } else {
        cout << "sayString is longer" << endl;
    }

    if (sayStrings < str){  // 比较字符串的第一个字符
        cout << "sayStrings's first letter is smaller than str's" << endl;
    } else {
        cout << "sayStrings's first letter is bigger than str's" << endl;
    }

    cout << "This program used " << String::howMany() << " objects." << endl;  // 输出当前存在的 String 对象数量

    return 0;
}