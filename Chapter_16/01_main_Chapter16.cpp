/*
知识点总结:
1. **字符串构造与初始化**：演示了 `string` 类的多种构造方式，包括直接赋值、部分拷贝、字符重复初始化等。
2. **字符串操作**：展示了字符串的拼接、修改、子串提取等常见操作。
3. **指针与迭代器**：使用字符数组的指针或 `string` 的迭代器来初始化或操作字符串。

注意点:
1. **字符串的引用与修改**：注意修改 `string` 对象的字符时，使用下标运算符访问字符串中的字符，并确保字符串长度足够避免越界。
2. **字符串拼接的效率**：在频繁的字符串拼接场景下，可能需要考虑使用 `+=` 操作符或 `string::append` 方法提高效率。
3. **指针范围的安全性**：使用指针初始化字符串时，确保指针范围的有效性，避免指针越界带来的潜在问题。
*/

#include <iostream>  // 标准输入输出流库
#include <string>    // 标准字符串库

using namespace std;

int main() {
    string one("Lottery winner");  // 用C字符串初始化string
    cout << one << endl;

    string two(20, '$');  // 用重复字符初始化string
    cout << two << endl;

    string three(one);  // 用另一个string对象初始化
    cout << three << endl;

    one += "Oops!";  // 字符串拼接
    cout << one << endl;

    two = "Sorry, That was ";  // 字符串赋值
    three[0] = 'P';  // 修改字符串中的字符
    string four;
    four = two + three;  // 字符串拼接
    cout << four << endl;

    char alla[] = "All's well that ends well";  // 字符数组
    string five(alla, 20);  // 用字符数组的前20个字符初始化
    cout << five << endl;

    string six(alla + 6, alla + 10);  // 用字符数组的部分区间初始化
    cout << six << ", ";

    string seven(&five[6], &five[10]);  // 用字符串对象的部分区间初始化
    cout << seven << "..." << endl;

    string eight(four, 7, 16);  // 用另一个string对象的子串初始化
    cout << eight << " in motion!" << endl;

    return 0;
}