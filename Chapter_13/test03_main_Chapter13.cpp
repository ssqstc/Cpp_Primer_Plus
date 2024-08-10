/*
知识点总结:
1. **多态性**：通过指针数组 `ABC *p_abc[CLIENTS]` 使用多态性，根据用户输入创建不同类型的派生类对象。
2. **动态内存分配**：使用 `new` 操作符动态分配内存，并在使用完毕后通过 `delete` 释放，避免内存泄漏。
3. **虚函数**：通过 `virtual` 关键字实现基类的虚函数 `view()`，从而在运行时调用正确的派生类方法。
4. **输入处理**：包括使用 `cin` 和 `getline` 获取用户输入，并处理输入缓冲区。
5. **对象销毁**：循环遍历对象指针数组并释放每个对象，确保内存安全。

注意点:
1. **内存泄漏**：确保在程序结束时释放所有动态分配的内存，防止内存泄漏。
2. **输入验证**：使用循环确保用户输入在预期范围内，并且正确处理换行符，避免输入问题。
3. **多态性使用**：确保基类指针能够指向正确的派生类对象，并调用相应的虚函数。
*/

#include "test03_head_Chapter13.h"

const int CLIENTS = 3;

int main() {
    ABC *p_abc[CLIENTS];
    int choice;
    char label[100], color[40], style[100];
    int rating;

    for (int i = 0; i < CLIENTS; ++i) {
        cout << "Enter 1 to baseDMA, 2 to lacksDMA, 3 to hasDMA: ";
        while (cin >> choice && (choice == 1 || choice == 2 || choice == 3)) {
            while (cin.get() != '\n');
            cout << "Enter label: ";
            cin.getline(label, 100);
            cout << "Enter rating: ";
            cin >> rating;
            while (cin.get() != '\n');

            switch (choice) {
                case 1:
                    p_abc[i] = new baseDMA(label, rating);
                    break;
                case 2:
                    cout << "Enter color: ";
                    cin.getline(color, 40);
                    p_abc[i] = new lacksDMA(label, rating, color);
                    break;
                case 3:
                    cout << "Enter style: ";
                    cin.getline(style, 100);
                    p_abc[i] = new hasDMA(label, rating, style);
            }
            break;
        }
    }
    for (int i = 0; i < CLIENTS; ++i) {
        p_abc[i]->view();
    }
    for (int i = 0; i < CLIENTS; ++i) {
        delete p_abc[i];
    }

    return 0;
}