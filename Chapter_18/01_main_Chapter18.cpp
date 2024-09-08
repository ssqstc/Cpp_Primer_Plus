/*
知识点：
1. **构造函数**：包括默认构造函数、带参数的构造函数、拷贝构造函数和移动构造函数。
2. **运算符重载**：重载了加法运算符 `operator+`，用于对象的组合。
3. **动态内存管理**：使用 `new` 动态分配字符数组内存，并在析构函数中使用 `delete[]` 释放内存。
4. **静态成员变量**：静态变量 `ct` 用于计数当前对象的个数。

注意点：
1. 在加法运算符重载中，需要合理处理对象的动态内存分配，防止内存泄漏。
2. 使用移动构造函数时，确保移动后的对象处于有效但可识别的状态（如将 `pc` 置为 `nullptr`）。
3. 使用析构函数时，确保删除动态分配的内存。

*/

#include <iostream>
using namespace std;

class Useless {
private:
    int n;  // 元素数量
    char* pc;  // 指向字符数组的指针
    static int ct;  // 记录对象总数的静态变量
    void showObject() const;  // 显示对象状态
public:
    // 构造函数和析构函数
    Useless();  // 默认构造函数
    explicit Useless(int K);  // 单参数构造函数
    Useless(int k, char ch);  // 带字符的构造函数
    Useless(const Useless& f);  // 拷贝构造函数
    Useless(Useless&& f);  // 移动构造函数
    ~Useless();  // 析构函数

    // 运算符重载
    Useless operator+(const Useless& f) const;  // 重载加法运算符

    // 成员函数
    void showData() const;  // 显示对象的数据
};

int Useless::ct = 0;  // 初始化静态变量

// 默认构造函数
Useless::Useless() {
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    showObject();
}

// 带整数参数的构造函数
Useless::Useless(int k) : n(k) {
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];  // 动态分配内存
    showObject();
}

// 带整数和字符参数的构造函数
Useless::Useless(int k, char ch) : n(k) {
    ++ct;
    cout << "int, char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = ch;  // 初始化字符数组
    }
    showObject();
}

// 拷贝构造函数
Useless::Useless(const Useless& f) : n(f.n) {
    ++ct;
    cout << "copy const called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = f.pc[i];  // 拷贝数据
    }
    showObject();
}

// 移动构造函数
Useless::Useless(Useless&& f) : n(f.n) {
    ++ct;
    cout << "move constructor called; number of objects: " << ct << endl;
    pc = f.pc;  // 转移指针所有权
    f.pc = nullptr;  // 使源对象无效
    f.n = 0;
    showObject();
}

// 析构函数
Useless::~Useless() {
    cout << "destructor called; objects left: " << --ct << endl;
    cout << "deleted object:\n";
    showObject();
    delete[] pc;  // 释放动态内存
}

// 重载加法运算符，将两个对象的字符数组拼接
Useless Useless::operator+(const Useless& f) const {
    cout << "Entering operator+()\n";
    Useless temp = Useless(n + f.n);  // 创建临时对象，容量为两个对象之和
    for (int i = 0; i < n; ++i) {
        temp.pc[i] = pc[i];  // 复制第一个对象的数据
    }
    for (int i = n; i < temp.n; ++i) {
        temp.pc[i] = f.pc[i - n];  // 复制第二个对象的数据
    }
    cout << "temp object:\n";
    cout << "Leaving operator+()\n";
    return temp;  // 返回新对象
}

// 显示对象状态
void Useless::showObject() const {
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void*)pc << endl;
}

// 显示对象中的字符数据
void Useless::showData() const {
    if (n == 0) {
        cout << "(object empty)";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << pc[i];
        }
    }
    cout << endl;
}

int main() {
    // 创建对象并调用不同的构造函数
    Useless one(10, 'x');  // 带字符的构造函数
    Useless two = one;  // 拷贝构造函数
    Useless three(20, '0');  // 带字符的构造函数
    Useless four(one + three);  // 重载加法运算符 + 移动构造函数

    // 显示每个对象中的数据
    cout << "object one: ";
    one.showData();
    cout << "object two: ";
    two.showData();
    cout << "object three: ";
    three.showData();
    cout << "object four: ";
    four.showData();

    return 0;
}