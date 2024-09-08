/*
知识点：
1. **深拷贝与浅拷贝**：通过在拷贝构造函数和赋值运算符中显式地进行深拷贝，避免指针成员在多个对象间共享，防止资源释放冲突。
2. **移动语义**：使用移动构造函数和移动赋值运算符以提高对象转移时的效率，避免不必要的深拷贝操作。
3. **智能指针 vs 原生指针**：在此代码中使用了原生指针管理资源，需要手动管理内存分配和释放。可以考虑使用 `std::unique_ptr` 来自动管理资源，减少内存泄漏的风险。

注意点：
1. 使用原生指针需要注意手动释放内存，确保在对象销毁时不会造成内存泄漏或多次释放同一块内存。
2. 在移动构造和移动赋值中，将源对象的指针置为 `nullptr`，防止源对象被销毁时释放已经转移走的资源。
*/

#include <iostream>
using namespace std;

class Cpmv {
public:
    // 嵌套结构体，用于存储字符串信息
    struct Info {
        string qcode;  // 字符串成员 qcode
        string zcode;  // 字符串成员 zcode
    };
private:
    Info* pi;  // 指向 Info 结构体的指针
public:
    // 默认构造函数：pi 置为空指针
    Cpmv() : pi(nullptr) {
        cout << "Default construction" << endl;
    }

    // 带参数的构造函数：动态分配 Info，并初始化 qcode 和 zcode
    Cpmv(string q, string z) : pi(new Info{q, z}) {
        cout << "Construction with args" << endl;
    }

    // 拷贝构造函数：深拷贝 pi 指向的 Info
    Cpmv(const Cpmv& cp) : pi(new Info{cp.pi->qcode, cp.pi->zcode}) {
        cout << "Copy construction" << endl;
    }

    // 移动构造函数：转移 pi 的所有权，并将源对象的 pi 置为空指针
    Cpmv(Cpmv&& mv) : pi(mv.pi) {
        mv.pi = nullptr;
        cout << "Move construction" << endl;
    }

    // 析构函数：释放动态分配的 Info
    ~Cpmv() {
        delete pi;
        cout << "Deconstruction" << endl;
    }

    // 赋值运算符：深拷贝并确保不自赋值
    Cpmv& operator=(const Cpmv& cp) {
        if (this == &cp) {  // 检查自赋值
            return *this;
        }
        delete pi;  // 释放现有的 pi
        pi = new Info{cp.pi->qcode, cp.pi->zcode};  // 深拷贝
        cout << "Assignment function" << endl;
        return *this;
    }

    // 移动赋值运算符：转移 pi 的所有权，并释放旧的资源
    Cpmv& operator=(Cpmv&& mv) noexcept {
        if (this == &mv) {  // 检查自赋值
            return *this;
        }
        delete pi;  // 释放现有的 pi
        pi = mv.pi;  // 转移所有权
        mv.pi = nullptr;  // 将源对象的 pi 置为空指针
        cout << "Move assignment function" << endl;
        return *this;
    }

    // 重载加法运算符：将两个对象的 qcode 和 zcode 拼接，并返回新对象
    Cpmv operator+(const Cpmv& obj) const {
        cout << "Operator +" << endl;
        return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
    }

    // 显示对象信息
    void Display() const {
        if (pi != nullptr) {  // 检查 pi 是否为空指针
            cout << "Display Info" << endl;
            cout << "qcode: " << pi->qcode << ", zcode: " << pi->zcode << endl;
        } else {
            cout << "Empty object." << endl;
        }
    }
};

int main() {
    Cpmv cpmv1("ssq", "stc");  // 调用带参数的构造函数
    Cpmv cpmv2("dadada", "lalala");  // 调用带参数的构造函数
    Cpmv cpmv3(cpmv2);  // 调用拷贝构造函数
    cpmv2 = cpmv1;  // 调用赋值运算符
    Cpmv cpmv4(cpmv1 + cpmv2);  // 调用加法运算符和移动构造函数

    return 0;
}