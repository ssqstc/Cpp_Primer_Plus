// 知识点总结:
// 1. 该代码展示了一个基于链表实现的模板化队列类 `Queue`，该类可以存储任意类型的数据，并支持队列的基本操作，如入队和出队。
// 2. 使用了类的内嵌类 `Node` 来表示队列中的每个节点，节点包含数据和指向下一个节点的指针。
// 3. 通过模板机制实现泛型编程，使 `Queue` 类可以处理不同的数据类型，而无需为每种数据类型单独定义队列类。
// 4. 队列的大小是由用户指定的，默认情况下大小为10（通过枚举 `Q_SIZE` 定义）。
// 5. `Queue` 类包含队列的常见操作：`enqueue`（入队）、`dequeue`（出队）、`isEmpty`（判断是否为空）、`isFull`（判断是否已满）和 `queueCount`（获取队列中的元素数量）。

// 注意点:
// 1. `Queue` 类在析构函数中需要确保所有动态分配的节点内存都被正确释放，以防止内存泄漏。
// 2. 在 `enqueue` 操作时，需检查队列是否已满；同样，在 `dequeue` 操作时，需检查队列是否为空。
// 3. 在处理链表时要特别注意指针的操作，避免出现空指针解引用或内存泄漏等问题。
// 4. 对模板类的实现，需将模板类的实现代码放在头文件中，否则编译器可能无法正确生成相应的代码。

#include "03_head_Chapter15.h"

int main() {
    // 创建一个队列 `cs`，容量为 5
    Queue<string> cs(5);
    string temp;

    // 循环输入客户姓名，直到队列满为止
    while (!cs.isFull()) {
        cout << "Please enter client's name, then push to queue: " << endl;
        getline(cin, temp);
        cs.enqueue(temp);
    }

    cout << "The queue is full, Processing begin!" << endl;

    // 循环处理队列中的客户姓名，直到队列为空为止
    while (!cs.isEmpty()) {
        cs.dequeue(temp);
        cout << "Now processing: " << temp << endl;
    }
    return 0;
}