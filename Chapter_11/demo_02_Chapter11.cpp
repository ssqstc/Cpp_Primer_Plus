#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 构造函数：初始化对象时会自动调用的特殊成员函数。
 * - 运算符重载：通过重载运算符实现类对象的特殊行为。
 * - 输出调试信息：在构造函数和重载运算符中输出信息，以观察程序执行流程。
 * - 当类中未定义赋值运算符重载功能的时候 代码中出现赋值运算时 程序将调用与右值相匹配的构造函数
 *
 * 注意点：
 * - 默认构造函数和带参数构造函数的实现。
 * - 重载赋值运算符 `operator=`，使其接受一个 `int` 类型的参数。
 * - 赋值运算符重载后的调用方式以及其作用。
 */

class Num{
private:
    int n; // 数字成员变量
public:
    Num(); // 默认构造函数
    Num(int m); // 带参数构造函数
    void operator=(int l); // 重载赋值运算符
};

// 默认构造函数，初始化 n 为 0 并输出信息
Num::Num() {
    n = 0;
    cout << "Hello world" << endl; // 输出 "Hello world"
}

// 带参数构造函数，初始化 n 为 m 并输出信息
Num::Num(int m) {
    n = m;
    cout << "Good morning" << endl; // 输出 "Good morning"
}

// 重载赋值运算符，将 l 赋值给 n 并输出信息
void Num::operator=(int l) {
    n = l;
    cout << "dadada" << endl; // 输出 "dadada"
}

int main(){
    Num a; // 调用默认构造函数，输出 "Hello world"
    a = 10; // 调用重载的赋值运算符，输出 "dadada"

    return 0;
}
