#include "iostream"
#include "cctype" // 包含字符处理函数
using namespace std;

/*
这个程序展示了字符串处理、引用参数传递和基本的循环控制。
主要知识点和注意事项：
1. 使用引用参数传递字符串，避免不必要的复制。
2. 使用标准库函数 toupper 将字符串转换为大写。
3. 基本的循环控制，处理用户输入并持续运行直到用户输入 "q"。

注意：
1. 引用参数允许函数直接修改原始数据。
2. 使用 getline 函数读取整行输入。
3. 使用 <cctype> 中的 toupper 函数进行字符转换。
*/

// 函数声明，将字符串转换为大写
void convert(string &str); // convert 函数声明

int main(){
    string str;
    cout << "Enter a string (q to quit): "; // 提示用户输入字符串 (q 表示退出)
    getline(cin, str); // 读取用户输入的字符串
    while (str != "q"){ // 循环直到用户输入 "q"
        convert(str); // 调用函数将字符串转换为大写
        cout << str << endl; // 输出转换后的字符串
        cout << "Next string (q to quit): "; // 提示用户输入下一个字符串 (q 表示退出)
        getline(cin, str); // 再次读取用户输入
    }
    cout << "Bye." << endl; // 输出退出信息
    return 0;
}

// 函数定义，将字符串转换为大写
void convert(string &str){
    for (int i = 0; i < str.length(); ++i) { // 遍历字符串的每个字符
        str[i] = toupper(str[i]); // 将每个字符转换为大写
    }
}
