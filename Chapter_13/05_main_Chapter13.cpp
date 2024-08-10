#include "05_head_Chapter13.h"

/*
知识点总结:
1. **深拷贝与浅拷贝**: 演示了深拷贝的必要性，特别是在类中包含动态分配的内存时。
2. **运算符重载**: 通过重载赋值运算符（`operator=`）和输出运算符（`operator<<`）实现对象的深度复制和显示功能。
3. **虚析构函数**: 确保基类的指针删除时能够正确调用派生类的析构函数。

注意点:
1. **动态内存管理**: 注意在赋值运算符重载中先释放已有内存以避免内存泄漏。
2. **复制构造函数**: 要特别注意在复制构造函数中处理动态内存，防止多次释放同一块内存。
*/

int main() {
    baseDMA shirt("Portabella", 8);
    cout << "Displaying baseDMA object: " << endl;
    cout << shirt;
    cout << "----------------Dividing----------------" << endl;

    lacksDMA ballon("Blimp", 4, "red");
    cout << "Displaying lacksDMA object: " << endl;
    cout << ballon;
    cout << "----------------Dividing----------------" << endl;

    lacksDMA ballon2(ballon);
    cout << "Result of lacksDMA copy: " << endl;
    cout << ballon2;
    cout << "----------------Dividing----------------" << endl;

    hasDMA map("Keys", 5, "Mercator");
    cout << "Displaying hasDMA object: " << endl;
    cout << map;
    cout << "----------------Dividing----------------" << endl;

    hasDMA map2 = map;
    cout << "Result of hasDMA copy: " << endl;
    cout << map2;

    return 0;
}
