/*
 * 知识点总结：
 * 1. **模板类（Template Class）**：`Stack` 类使用模板技术，可以处理任意类型的数据，提供了代码复用性。
 * 2. **栈操作**：`Stack` 类实现了常见的栈操作，如判断栈是否为空 (`isEmpty`)、是否已满 (`isFull`)、压栈 (`push`) 和出栈 (`pop`)。
 * 3. **静态成员变量**：`MAX` 是一个静态常量，定义了栈的最大容量，且在类的所有实例中共享。
 * 4. **字符指针数组**：`in` 和 `out` 数组存储了指向字符串字面值的指针，这些指针被压入和弹出栈。
 * 5. **循环与条件判断**：`while` 循环用来遍历数组，控制栈的压入和弹出操作。

 * 注意点：
 * 1. **边界检查**：在执行 `push` 和 `pop` 操作时，必须检查栈是否已满或为空，以避免越界操作。
 * 2. **指针操作**：在处理字符串时，注意 `in` 和 `out` 数组中的指针指向的是常量字符串，这些字符串不可修改。
 * 3. **内存管理**：栈的操作涉及对指针的操作，需确保指针操作的安全性，避免非法访问或内存泄漏。
 */

#include "iostream"
#include "07_head_Chapter14.h"
using namespace std;

const int NUM = 10; // 定义栈的大小

int main() {
    int nextIn = 0; // 下一个要压入栈的元素的索引
    int processed = 0; // 已经处理的出栈元素的计数
    const char* in[NUM] = {"1: Hank", "2: Kiki", "3: Betty", "4: Ian", "5: Wolf",
                           "6: Portia", "7: Joy", "8: Xav", "9: Juan", "10: Misha"};
    // 定义一个包含10个字符串指针的数组，代表要压入栈的数据
    Stack<const char*> st; // 创建一个存储字符指针的栈

    // 将所有元素压入栈中，直到栈满为止
    while (!st.isFull()) {
        st.push(in[nextIn++]); // 将当前元素压入栈，并移动索引指针
    }

    const char* out[NUM]; // 定义一个包含10个字符指针的数组，用于存储出栈的元素

    // 将所有元素从栈中弹出，直到栈为空为止
    while (!st.isEmpty()) {
        st.pop(out[processed++]); // 将栈顶元素弹出，并移动已处理计数
    }

    // 输出所有出栈的元素
    for (int i = 0; i < NUM; ++i) {
        cout << out[i] << endl; // 输出每个出栈的元素
    }

    return 0; // 程序结束
}