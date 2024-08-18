#include "01_head_Chapter14.h"

/*
 * 知识点总结：
 * 1. 类的设计与构造函数：`Student` 类设计了多种构造函数，涵盖了默认构造、字符串初始化构造、整数参数构造、字符串和整数参数构造、字符串和数组构造等，展示了多态性的实现。
 * 2. 虚析构函数：`Student` 类的析构函数使用了 `virtual` 关键字，确保在继承时正确调用派生类的析构函数，避免内存泄漏。
 * 3. 数组与运算符重载：使用 `valarray` 作为 `Student` 类的成员类型，实现了对分数数组的管理。同时重载了 `[]` 操作符，方便访问和修改数组元素。
 * 4. 输入与输出：通过重载 `<<` 和 `>>` 操作符，以及 `getline` 函数，定制化了 `Student` 对象的输入输出格式。
 *
 * 注意点：
 * 1. `valarray` 的使用：在操作 `valarray` 时，需确保索引不越界，同时在重载 `[]` 操作符时要区分常量与非常量对象的访问。
 * 2. 动态内存管理：虽然此处 `valarray` 已经处理了动态内存分配，但仍需注意析构函数的定义，确保内存的正确释放。
 * 3. 运算符重载的合理性：在设计运算符重载时，需确保其语义与标准一致，避免使用时产生歧义。
 * 4. 输入处理：在调用 `getline` 后应注意处理输入缓冲区，避免残留字符影响后续输入。
 */

const int PUPILS = 3;  // 学生人数
const int QUIZZES = 5; // 每个学生的测试次数

void set(Student& sa, int n); // 设置学生信息的函数声明

int main() {
    // 初始化三个 Student 对象数组，使用构造函数为每个学生预留 QUIZZES 个成绩空间
    Student ada[PUPILS] = {Student(QUIZZES), Student(QUIZZES), Student(QUIZZES)};
    int i;

    // 使用 set 函数为每个学生输入姓名和成绩
    for (i = 0; i < PUPILS; ++i)
        set(ada[i], QUIZZES);

    cout << "\nStudent List: " << endl;

    // 输出所有学生的姓名
    for (i = 0; i < PUPILS; i++)
        cout << ada[i].Name() << endl;

    cout << "\nResult List: " << endl;

    // 输出每个学生的成绩和平均分
    for (i = 0; i < PUPILS; ++i) {
        cout << ada[i];
        cout << "Average: " << ada[i].average() << endl;
    }

    return 0; // 返回 0，表示程序成功结束
}

// set 函数：用于设置学生的姓名和成绩
void set(Student& sa, int n) {
    cout << "Please enter the student's name:"; // 提示输入学生姓名
    getline(cin, sa); // 使用自定义的 getline 函数输入学生姓名
    cout << "Please enter: " << n << " quiz scores: " << endl; // 提示输入学生的成绩
    for (int i = 0; i < n; ++i)
        cin >> sa[i]; // 通过重载的 [] 操作符输入成绩
    while (cin.get() != '\n'); // 清空输入缓冲区，防止影响后续输入
}