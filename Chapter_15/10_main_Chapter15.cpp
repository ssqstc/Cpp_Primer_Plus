// 知识点总结:
// 1. 本代码演示了多态性、动态类型识别 (RTTI) 和类型转换 (type casting) 的结合使用。
// 2. `Grand` 类及其派生类 `Superb` 和 `Magnificent` 都定义了虚函数以支持多态性。
// 3. 使用 `typeid` 识别对象的真实类型，并使用 `dynamic_cast` 进行安全的类型转换。

// 注意点:
// 1. `dynamic_cast` 只适用于包含虚函数的类层次结构，并且在类型转换失败时返回 `nullptr`。
// 2. `typeid` 用于在运行时获取对象的类型信息，但需要包含虚函数以确保其正确性。
// 3. 在使用动态分配对象后，务必手动释放内存以避免内存泄漏。

#include <iostream> // 包含输入输出流库
#include <cstdlib> // 包含标准库函数，如 rand(), srand()
#include <ctime> // 包含时间相关函数，用于初始化随机数种子
#include <typeinfo> // 包含 RTTI 支持所需的库
using namespace std;

// 基类 Grand，定义了一个整数成员变量和两个虚函数
class Grand {
private:
    int hold; // 保存整数值
public:
    Grand(int h = 0) : hold(h) {} // 构造函数，初始化成员变量
    virtual void speak() const { cout << "I am a grand class.\n"; } // 虚函数，用于输出类信息
    virtual int value() const { return hold; } // 虚函数，返回 hold 的值
};

// Superb 类继承自 Grand，添加了一个新的虚函数 say()
class Superb : public Grand {
public:
    Superb(int h = 0) : Grand(h) {} // 构造函数，调用基类构造函数初始化
    void speak() const override { cout << "I am a superb class.\n"; } // 重写 speak() 函数，输出类信息
    virtual void say() const { cout << "I hold the superb value of " << value() << endl; } // 新增虚函数 say()，输出保存的值
};

// Magnificent 类继承自 Superb，添加了一个字符成员变量，并重写了 say() 函数
class Magnificent : public Superb {
private:
    char ch; // 保存字符值
public:
    Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {} // 构造函数，调用基类构造函数并初始化 ch
    void speak() const override { cout << "I am a magnificent class.\n"; } // 重写 speak() 函数，输出类信息
    void say() const override { cout << "I hold the character " << ch << " and the integer " << value() << endl; } // 重写 say() 函数，输出字符和整数
};

// 随机生成一个 Grand 类或其派生类的对象
Grand* getOne();

int main() {
    Grand* pg; // 基类指针，用于多态性
    Superb* ps; // 派生类指针，用于类型转换
    srand(time(0)); // 用当前时间初始化随机数种子

    for (int i = 0; i < 5; ++i) { // 循环五次，随机生成对象并处理
        pg = getOne(); // 获取一个随机生成的对象
        cout << "Now processing type " << typeid(*pg).name() << endl; // 输出对象的真实类型
        pg->speak(); // 调用 speak() 函数，根据实际类型输出相应信息

        if ((ps = dynamic_cast<Superb*>(pg))) { // 尝试将基类指针转换为 Superb 指针
            ps->say(); // 如果转换成功，调用 say() 函数
        }
        if (typeid(Magnificent) == typeid(*pg)) { // 检查对象是否为 Magnificent 类型
            cout << "Yes, you are really magnificent." << endl; // 如果是，输出确认信息
        }
        delete pg; // 释放动态分配的内存，防止内存泄漏
    }

    return 0; // 返回 0 表示程序正常结束
}

// getOne 函数，随机生成并返回一个 Grand 类或其派生类的对象
Grand* getOne() {
    Grand* p;
    switch (rand() % 3) { // 随机生成 0, 1, 或 2
        case 0:
            p = new Grand(rand() % 100); // 生成一个 Grand 对象
            break;
        case 1:
            p = new Superb(rand() % 100); // 生成一个 Superb 对象
            break;
        case 2:
            p = new Magnificent(rand() % 100, 'A' + rand() % 26); // 生成一个 Magnificent 对象，字符随机生成
            break;
    }
    return p; // 返回指向生成对象的指针
}