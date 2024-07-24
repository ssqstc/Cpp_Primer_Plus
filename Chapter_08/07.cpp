#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 引用：引用参数的使用。
 * 2. const：常量引用和返回常量引用。
 * 3. 函数返回类型：返回 string 对象和返回 string 引用的差异。
 * 4. 临时对象：返回局部变量的引用导致的问题。
 *
 * 注意点：
 * 1. version2 会修改原字符串，且返回的是修改后的字符串引用。
 * 2. version3 返回局部变量的引用，编译器会警告或错误，因为局部变量会在函数结束时销毁。
 */

string version1(const string &s1, const string &s2); // 版本1：返回新的字符串
const string &version2(string &s1, const string &s2); // 版本2：修改原字符串并返回其引用
const string &version3(string &s1, const string &s2); // 版本3：错误，返回局部变量的引用

int main(){
    string input, result, copy;
    cout << "Enter a string: "; // 输入字符串
    getline(cin, input); // 获取一行输入
    copy = input; // 复制输入的字符串

    cout << "Your string as entered: " << input << endl; // 输出输入的字符串
    result = version1(input, "***"); // 调用 version1，不修改原字符串
    cout << "Your string enhanced: " << result << endl; // 输出增强后的字符串
    cout << "Your original string: " << input << endl; // 输出原始字符串

    cout << "-----------------------------" << endl;
    result = version2(input, "###"); // 调用 version2，修改原字符串
    cout << "Your string enhanced: " << result << endl; // 输出增强后的字符串
    cout << "Your original string: " << input << endl; // 输出原始字符串

    cout << "-----------------------------" << endl;
    result = version3(copy, "@@@"); // 调用 version3，错误：返回局部变量的引用
    cout << "Your string enhanced: " << result << endl; // 输出增强后的字符串
    cout << "Your original string: " << copy << endl; // 输出原始字符串

    return 0;
}

string version1(const string &s1, const string &s2) {
    // 返回一个新的字符串，原字符串不受影响
    string temp;
    temp = s2 + s1 + s2; // 拼接字符串
    return temp;
}

const string &version2(string &s1, const string &s2) {
    // 修改原字符串并返回其引用
    s1 = s2 + s1 + s2; // 拼接字符串并修改原字符串
    return s1;
}

const string &version3(string &s1, const string &s2) {
    // 错误：返回局部变量的引用
    string temp;
    temp = s2 + s1 + s2; // 拼接字符串
    return temp; // 返回局部变量的引用，会导致错误
}
