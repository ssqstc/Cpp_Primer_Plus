#include "test03_head_Chapter14.h"

/*
 * 知识点总结：
 * 1. **模板类**：`Queue` 类是一个模板类，能够存储任意类型的数据，这里用作存储指向 `Worker` 对象的指针。
 * 2. **链表**：`Queue` 类内部使用链表结构来管理队列元素，通过 `Node` 结构体来连接队列中的每一个元素。
 * 3. **队列的基本操作**：`enqueue` 和 `dequeue` 方法实现了队列的入队和出队操作，`isEmpty` 和 `isFull` 方法用于检查队列状态。
 * 4. **构造函数与析构函数**：`Queue` 类使用构造函数进行初始化，并在析构函数中清理动态分配的内存，防止内存泄漏。
 * 5. **输入与输出**：`Worker` 类展示了基本的输入输出操作，尤其是使用 `cin` 和 `getline` 从标准输入中获取数据。
 *
 * 注意点：
 * 1. **模板类的使用**：在使用模板类时，确保理解模板的类型推导和实例化过程，避免模板特化和模板类型不匹配的问题。
 * 2. **链表内存管理**：链表节点的动态分配与释放必须成对出现，避免内存泄漏。在析构函数中应确保所有节点均被正确删除。
 * 3. **队列操作的边界条件**：在执行队列操作（如 `enqueue` 和 `dequeue`）时，注意队列的边界条件，防止溢出或操作空队列。
 * 4. **类的构造与析构**：在定义和使用类的构造函数与析构函数时，注意正确管理资源，尤其是动态分配的内存和其他资源。
 */

const int SIZE = 3;

int main() {
    // 创建一个大小为3的Queue队列用于存储Worker对象指针
    Queue<Worker*> wk(SIZE);

    // 创建并设置Worker对象 w1
    Worker w1;
    w1.set();
    w1.show();

    // 将w1指针入队到队列wk
    wk.enqueue(&w1);
    cout << "Now queue has: " << wk.queueCount() << " items. " << endl;

    // 创建并设置Worker对象 w2
    Worker w2;
    w2.set();
    w2.show();

    // 将w2指针入队到队列wk
    wk.enqueue(&w2);
    cout << "Now queue has: " << wk.queueCount() << " items. " << endl;

    // 创建并设置Worker对象 w3
    Worker w3;
    w3.set();
    w3.show();

    // 将w3指针入队到队列wk
    wk.enqueue(&w3);
    cout << "Now queue has: " << wk.queueCount() << " items. " << endl;

    return 0;
}