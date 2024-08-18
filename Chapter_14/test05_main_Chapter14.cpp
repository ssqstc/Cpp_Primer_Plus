// 知识点总结:
// 1. 本程序使用了抽象基类 `abstr_emp`，通过纯虚函数实现多态，要求所有派生类都实现 `showAll()` 和 `setAll()` 函数。
// 2. 虚继承用于避免多重继承时的菱形继承问题，`manager` 和 `fink` 类都虚继承自 `abstr_emp`，而 `highfink` 类继承自这两个类。
// 3. `ostream` 操作符重载用于输出类的成员变量，可以简化类的输出操作。
// 4. 虚函数的调用机制保证了基类指针能够根据实际对象类型调用正确的函数实现。
// 5. `inChargeOf()` 和 `reportsTo()` 成员函数分别用于访问和修改私有成员变量，体现了封装性。

// 注意点:
// 1. 在 `setAll()` 函数中要小心处理 `cin` 和 `getline` 的混合使用，以防止输入缓冲区问题。
// 2. 在继承中，确保子类调用了基类的对应函数，特别是在有多层继承的情况下，如 `highfink` 类的构造函数。
// 3. `abstr_emp` 定义了一个纯虚析构函数，确保类是抽象类，同时避免了未定义行为。
// 4. 虚继承时注意基类的构造顺序，避免未初始化的变量被访问。

#include "test05_head_Chapter14.h"

int main() {
    // 创建一个 employee 对象并输出其信息
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl; // 使用重载的 << 操作符输出信息
    em.setAll(); // 设置新的 employee 信息

    // 创建一个 manager 对象并输出其信息
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout << ma << endl; // 输出 manager 的基本信息
    ma.showAll(); // 显示所有 manager 信息，包括 inchargeof

    // 创建一个 fink 对象并输出其信息
    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout << fi << endl; // 输出 fink 的基本信息
    fi.showAll(); // 显示所有 fink 信息，包括 reportsto

    // 创建一个 highfink 对象（从 manager 和 fink 派生）
    highfink hf(ma, "Curly Kew");
    hf.showAll(); // 显示所有 highfink 信息，包括 inchargeof 和 reportsto

    cout << "Press a key for next phase:\n";
    cin.get(); // 等待用户输入以进入下一阶段

    // 创建另一个 highfink 对象，并通过用户输入设置其信息
    highfink hf2;
    hf2.setAll(); // 设置 highfink 信息

    // 使用基类指针调用派生类的虚函数，体现多态
    cout << "Using an bastr_emp * pointer:\n";
    abstr_emp* tri[4] = {&em, &fi, &hf, &hf2}; // 基类指针数组，指向不同类型的派生类对象
    for (int i = 0; i < 4; ++i) {
        tri[i]->showAll(); // 调用实际对象的 showAll 函数
    }

    return 0;
}