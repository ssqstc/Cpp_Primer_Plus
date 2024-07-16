#include "iostream"
using namespace std;

string version1(const string &s1, const string &s2);
const string &version2(string &s1, const string &s2);
const string &version3(string &s1, const string &s2);

int main(){
    string input, result, copy;
    cout << "Enter a string: ";
    getline(cin, input); // 读取用户输入的字符串
    copy = input; // 复制输入字符串以进行后续操作

    cout << "Your string as entered: " << input << endl;    // 输出用户输入的字符串
    result = version1(input, "***"); // 调用 version1
    cout << "Your string enhanced: " << result << endl;     // 输出 version1 返回的字符串
    cout << "Your original string: " << input << endl;      // 输出原始字符串

    cout << "-----------------------------" << endl;
    result = version2(input, "###"); // 调用 version2
    cout << "Your string enhanced: " << result << endl;     // 输出 version2 返回的字符串
    cout << "Your original string: " << input << endl;      // 输出修改后的原始字符串

    cout << "-----------------------------" << endl;
    result = version3(copy, "@@@"); // 调用 version3
    cout << "Your string enhanced: " << result << endl;     // 输出 version3 返回的字符串
    cout << "Your original string: " << copy << endl;      // 输出复制的字符串

    return 0;
}

// 返回一个string对象的函数
string version1(const string &s1, const string &s2) {
    // 创建一个局部变量 temp 来存储 s2 + s1 + s2
    string temp;
    temp = s2 + s1 + s2;
    return temp; // 返回 temp 的值，调用者接收一个新的字符串对象
}

// 返回一个指向原字符串的const引用
const string &version2(string &s1, const string &s2) {
    // 修改传入的字符串 s1 为 s2 + s1 + s2
    s1 = s2 + s1 + s2;
    return s1; // 返回 s1 的引用
}

// 错误示例：返回局部变量的引用
const string &version3(string &s1, const string &s2) {
    // 创建一个局部变量 temp 来存储 s2 + s1 + s2
    string temp;
    temp = s2 + s1 + s2;
    // 返回局部变量 temp 的引用，导致未定义行为
    return temp; // temp 在函数结束时会被销毁
}
