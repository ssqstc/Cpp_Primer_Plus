#include "iostream"
#include "new"
#include "cstring"
using namespace std;

/*
 * 知识点总结：
 * - `placement new` 运算符：在预分配的内存中构造对象，避免频繁分配和释放内存。
 * - 动态内存分配：使用 `new` 运算符在堆上分配内存，并在使用完后释放。
 * - `strcpy` 函数：用于复制字符串内容。
 *
 * 注意点：
 * - 预分配内存缓冲区 `buffer` 的大小为 512 字节。
 * - 使用 `placement new` 运算符在缓冲区中构造 `chaff` 对象数组。
 * - 确保在程序结束前释放动态分配的内存，以避免内存泄漏。
 * - 使用 `cin.getline` 读取字符串输入，并处理换行符。
 */

// 定义结构体 chaff
struct chaff{
    char dross[20]; // 存储字符串，大小为 20 字节
    int slag;       // 存储整数
};

const int SIZE = 512; // 预分配缓冲区大小
char buffer[SIZE];    // 定义缓冲区

void show(const chaff &p); // 函数声明：显示 chaff 结构体内容

int main(){
    chaff *chf1 = new(buffer) chaff[2]; // 在预分配的缓冲区中构造两个 chaff 对象
    chaff *chf2 = new chaff[2];         // 在堆上动态分配两个 chaff 对象
    for (int i = 0; i < 2; ++i) {
        cout << "# " << i + 1 << ": " << endl;
        cout << "Enter the dross: ";   // 提示输入字符串 dross
        cin.getline(chf1[i].dross, 20); // 读取字符串输入
        cout << "Enter the slag: ";    // 提示输入整数 slag
        cin >> chf1[i].slag;            // 读取整数输入
        cin.get();                      // 处理换行符
        strcpy(chf2[i].dross, chf1[i].dross); // 复制字符串到堆上分配的对象
        chf2[i].slag = chf1[i].slag;         // 复制整数到堆上分配的对象
    }
    for (int i = 0; i < 2; ++i) {
        show(chf1[i]); // 显示缓冲区中对象的内容
        show(chf2[i]); // 显示堆上分配对象的内容
    }
    delete [] chf2; // 释放堆上分配的内存
    return 0;
}

// 定义显示 chaff 结构体内容的函数
void show(const chaff &p){
    cout << "The dross is: " << p.dross << endl; // 输出 dross 字符串内容
    cout << "The slag is: " << p.slag << endl;   // 输出 slag 整数内容
}
