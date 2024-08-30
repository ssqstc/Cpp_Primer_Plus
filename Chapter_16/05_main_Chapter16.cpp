/*
知识点总结:
1. **智能指针**：C++ 标准库提供了 `unique_ptr` 和 `shared_ptr` 来管理动态内存，避免手动管理内存释放，减少内存泄漏的风险。
2. **unique_ptr**：一个独占所有权的智能指针，指针之间不能复制，适用于一个指针拥有一个资源的场景。
3. **shared_ptr**：一个可以共享所有权的智能指针，多个 `shared_ptr` 可以指向同一对象，自动管理引用计数，当最后一个 `shared_ptr` 释放时，才会释放内存。

注意点:
1. **unique_ptr**：不能复制或共享，转移所有权可以使用 `std::move`，常用于不希望共享所有权的情况。
2. **shared_ptr**：引用计数会增加少量的内存开销，适用于需要多个指针共享同一对象的情况。
*/

#include <iostream>  // 标准输入输出流库
#include <string>    // 标准字符串库
#include <memory>    // 标准智能指针库

using namespace std;

class Report {
private:
    string str;  // 存储报告内容的字符串
public:
    // 构造函数，接受一个字符串参数并初始化 str
    Report(string s) : str(s) {
        cout << "Object created\n";  // 对象创建时输出提示信息
    }
    // 析构函数，销毁对象时输出提示信息
    ~Report() {
        cout << "Object deleted\n";
    }
    // 常量成员函数，打印报告内容
    void comment() const {
        cout << str << endl;
    }
};

int main() {
    {
        // 使用 unique_ptr 管理动态分配的 Report 对象
        unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();  // 调用对象的 comment 方法
    }  // unique_ptr 在作用域结束时自动销毁对象

    // 使用 shared_ptr 管理动态分配的 Report 对象
    shared_ptr<Report> ps(new Report("using shared_ptr"));
    ps->comment();  // 调用对象的 comment 方法

    return 0;  // 程序结束，shared_ptr 自动销毁对象
}