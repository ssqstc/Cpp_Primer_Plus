/*
知识点总结:
1. **shared_ptr**：一个可以共享所有权的智能指针，用于多个指针可以指向同一个对象，并自动管理内存的释放。
2. **动态内存管理**：通过智能指针管理动态分配的内存，避免内存泄漏和手动释放内存的风险。
3. **数组初始化**：可以使用初始化列表为 `shared_ptr` 数组初始化动态分配的对象。

注意点:
1. **shared_ptr** 会增加引用计数，当引用计数为零时，自动释放对象。
2. 避免使用原生指针直接管理动态内存，使用智能指针能更好地管理资源，减少错误。
*/

#include <iostream>   // 标准输入输出流库
#include <memory>     // 标准智能指针库
#include <string>     // 标准字符串库

using namespace std;

int main() {
    // 使用 shared_ptr 动态分配字符串并初始化数组
    shared_ptr<string> film[5] = {
            shared_ptr<string>(new string("ABC")),
            shared_ptr<string>(new string("DEF")),
            shared_ptr<string>(new string("GHI")),
            shared_ptr<string>(new string("JKL")),
            shared_ptr<string>(new string("XYZ")),
    };

    shared_ptr<string> pwin;  // 声明一个 shared_ptr 变量
    pwin = film[2];           // 将 film[2] 赋值给 pwin，共享同一个对象

    // 输出候选影片
    cout << "The nominees for best avian baseball film are\n";
    for (int i = 0; i < 5; ++i) {
        cout << *film[i] << endl;  // 使用解引用运算符输出字符串内容
    }

    // 输出获奖影片
    cout << "The winner is " << *pwin << "!\n";

    cin.get();  // 等待用户输入以保持窗口打开

    return 0;  // 程序结束，所有 shared_ptr 自动释放内存
}