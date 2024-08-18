#include "test04_head_Chapter14.h"
#include "ctime"

/*
 * 知识点总结：
 * 1. **虚继承与多重继承**：类 `Gunslinger` 和 `PokerPlayer` 都虚继承自 `Person`，而 `BadDude` 多重继承自 `Gunslinger` 和 `PokerPlayer`，虚继承用于避免“菱形继承”问题。
 * 2. **多态性**：通过基类指针调用派生类对象的 `set()` 和 `show()` 方法，展示了多态的应用场景。
 * 3. **随机数的使用**：在 `PokerPlayer` 中，通过 `rand()` 生成随机牌面，`srand(time(NULL))` 用于种子初始化。
 * 4. **纯虚函数**：`Person` 类中的 `set()` 和 `show()` 为虚函数，可以在派生类中重写以实现不同的行为。
 *
 * 注意点：
 * 1. **内存管理**：`pop` 数组中的每个对象在使用后需要手动调用 `delete` 进行释放，避免内存泄漏。
 * 2. **随机数种子初始化**：随机数种子应在程序开始时初始化一次，避免重复初始化导致随机数序列相同。
 * 3. **输入检查**：在输入时，应检查输入值的合法性，并处理非法输入，如 `strchr` 的使用。
 * 4. **虚函数的覆盖**：确保在派生类中覆盖基类虚函数时，函数签名完全匹配，包括函数参数类型和数量。
 */

const int SIZE = 4;

int main() {
    srand(time(NULL)); // 随机数种子初始化，基于当前时间

    Person* pop[SIZE]; // 创建一个指向Person类对象的指针数组

    for (int i = 0; i < SIZE; ++i) {
        char choice;
        cout << "Enter p:person\tg:gunslinger\tk:pokerPlayer\tb:badDude\tq:quit" << endl;
        cin >> choice;

        // 输入检查，确保用户输入的选择是合法的
        while (strchr("pgkbq", choice) == NULL) {
            cout << "Please enter p,g,k,b,q:";
            cin >> choice;
        }

        if (choice == 'q') {
            break; // 用户选择退出
        }

        // 根据用户的选择创建相应的对象并存储到指针数组中
        switch (choice) {
            case 'p':
                pop[i] = new Person;
                break;
            case 'g':
                pop[i] = new Gunslinger;
                break;
            case 'k':
                pop[i] = new PokerPlayer;
                break;
            case 'b':
                pop[i] = new BadDude;
                break;
        }

        // 清除输入缓冲区，避免影响后续输入
        while (cin.get() != '\n');

        // 设置对象的属性
        pop[i]->set();
    }

    // 显示每个对象的信息
    for (int i = 0; i < SIZE; ++i) {
        cout << endl;
        pop[i]->show();
    }

    // 释放每个对象的内存
    for (int i = 0; i < SIZE; ++i) {
        delete pop[i];
    }

    return 0;
}