#include "iostream"
using namespace std;

void n_chars(char c, int n);
int main(){
    char ch;
    int times;

    cout << "Enter a character: ";
    cin >> ch;  // cin.get() 会读取回车和空白字符，cin会跳过空白字符

    while ('q' != ch){      // 输入q退出循环
        cout << "Enter a integer:";     // 输入一个整形数
        cin >> times;

        n_chars(ch, times);     // 调用函数

//        cout << "\ntimes = " << times << endl;  // 运行结束后 times值没变 证明实参传递的是拷贝值

        cout << endl;
        cout << "Enter another character or press 'q' to quit:" << endl;    // 开始下一次循环 再次输入字符或者输入q退出
        cin >> ch;
    }

    return 0;
}

void n_chars(char c, int n){
    while (--n > 0){
        cout << c;
    }
}