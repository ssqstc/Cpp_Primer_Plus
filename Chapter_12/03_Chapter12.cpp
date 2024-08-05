#include "iostream"
#include "string"
#include "new"

using namespace std;

const int BUF = 512;  // 定义缓冲区大小

class JustTesting {
private:
    string words;  // 字符串成员变量
    int number;    // 整数成员变量
public:
    // 构造函数，带默认参数
    JustTesting(const string &s = "Just Testing", int n = 0) {
        words = s;
        number = n;
        cout << words << " constructed\n";  // 输出构造信息
    }

    // 析构函数
    ~JustTesting() {
        cout << words << " destroyed\n";  // 输出析构信息
    }

    // 显示对象内容
    void show() const {
        cout << words << ", " << number << endl;
    }
};

/*
知识点总结:
1. **内存分配**: 使用 `new` 操作符在堆和缓冲区上分配内存，缓冲区上的内存分配需要显式调用析构函数。
2. **定位 new 操作符**: 使用定位 `new` 操作符在指定地址（缓冲区）上创建对象。
3. **构造函数和析构函数**: 在对象创建和销毁时输出调试信息。
4. **动态内存管理**: 确保正确释放堆和缓冲区的内存。

注意点:
1. **内存泄漏**: 确保所有 `new` 分配的内存都能正确释放，避免内存泄漏。
2. **显式调用析构函数**: 对于在缓冲区上创建的对象，必须显式调用析构函数来释放资源。
3. **缓冲区大小**: 确保缓冲区足够大以容纳所有定位 `new` 操作符创建的对象。
4. **指针使用**: 在输出内存地址时，将指针转换为 `void*` 以显示实际地址。
*/

int main() {
    char *buffer = new char[BUF];  // 动态分配内存作为缓冲区
    JustTesting *pc1, *pc2;

    // 在缓冲区上创建对象
    pc1 = new(buffer) JustTesting;
    // 在堆上创建对象
    pc2 = new JustTesting("Heap1", 20);

    cout << "buffer: " << (void *)buffer << endl;  // 输出缓冲区地址
    cout << "heap: " << pc2 << endl;  // 输出堆地址

    // 显示对象信息
    cout << pc1 << ": ";
    pc1->show();
    cout << pc2 << ": ";
    pc2->show();

    JustTesting *pc3, *pc4;
    // 在缓冲区上的另一个位置创建对象
    pc3 = new(buffer + sizeof(JustTesting)) JustTesting("Bad Idea", 6);
    // 在堆上创建另一个对象
    pc4 = new JustTesting("heap2", 10);

    // 显示新对象信息
    cout << pc3 << ": ";
    pc3->show();
    cout << pc4 << ": ";
    pc4->show();

    // 删除堆上的对象
    delete pc2;
    delete pc4;

    // 显式调用析构函数删除缓冲区上的对象
    pc3->~JustTesting();
    pc1->~JustTesting();
    // 释放缓冲区
    delete []buffer;

    return 0;
}