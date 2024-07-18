#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 作用域和生命周期：局部变量在其定义的块内有效，块结束后被销毁。
 * 2. 变量地址：通过&运算符可以获取变量的内存地址。
 * 3. 参数传递：函数参数按值传递，传递的是变量的副本。
 *
 * 注意点：
 * 1. 同名变量在不同作用域内是独立的，不会互相影响。
 * 2. 调用函数时，传递的参数是变量的副本，不会影响原变量。
 */

void oil(int x);

int main(){
    int texas = 31;     // 自动变量
    int year = 2011;

    cout << "In main(), texas = " << texas << ", ";    // 在main函数中，texas的值 =
    cout << "&texas = " << &texas << endl;    // texas的地址 =
    cout << "In main(), year = " << year << ", ";    // 在main函数中，year的值 =
    cout << "&year = " << &year << endl;    // year的地址 =

    oil(texas);

    cout << "In main(), texas = " << texas << ", ";    // 在main函数中，texas的值 =
    cout << "&texas = " << &texas << endl;    // texas的地址 =
    cout << "In main(), year = " << year << ", ";    // 在main函数中，year的值 =
    cout << "&year = " << &year << endl;    // year的地址 =

    return 0;
}

void oil(int x){
    int texas = 5;
    cout << "In oil(), texas = " << texas << ", ";    // 在oil函数中，texas的值 =
    cout << "&texas = " << &texas << endl;    // texas的地址 =
    cout << "In oil(), x = " << x << ", ";    // 在oil函数中，x的值 =
    cout << "&x = " << &x << endl;    // x的地址 =

    {
        int texas = 113;
        cout << "In block, texas = " << texas << ", ";    // 在块内，texas的值 =
        cout << "&texas = " << &texas << endl;    // texas的地址 =
        cout << "In block, x = " << x << ", ";    // 在块内，x的值 =
        cout << "&x = " << &x << endl;    // x的地址 =
    }
    cout << "Post-block, texas = " << texas << ", ";    // 块结束后，texas的值 =
    cout << "&texas = " << &texas << endl;    // texas的地址 =
}
