#include "02_head_Chapter14.h"

/*
 * 知识点总结：
 * 1. 私有继承：`Student` 类私有继承了 `string` 和 `valarray<double>`，实现了多重继承的效果，同时隐藏了基类的接口，使其只对 `Student` 类内部可见。
 * 2. 构造函数：`Student` 类的多个构造函数展现了不同的初始化方式，包括通过姓名、成绩数量、数组等方式初始化对象。
 * 3. 运算符重载：重载了 `[]`、`<<`、`>>` 等运算符，便于对学生成绩的操作和输入输出。
 * 4. 输入输出自定义：通过重载的 `<<` 和 `>>` 操作符，以及 `getline` 函数，定制了 `Student` 对象的输入输出格式。
 *
 * 注意点：
 * 1. 私有继承的影响：由于是私有继承，`Student` 对象不能直接使用 `string` 和 `valarray` 的接口，需通过类内部实现接口转发或封装。
 * 2. 访问基类成员：在重载 `<<` 和 `>>` 时，通过强制类型转换 `(string&)` 和 `(const string&)` 访问 `string` 部分，注意保持类型一致性。
 * 3. 运算符重载：重载 `[]` 运算符时，需要同时提供常量版本和非常量版本，以支持对对象的只读和读写操作。
 * 4. 输入处理：使用 `getline` 处理输入时，需注意缓冲区的管理，确保后续输入不受影响。
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
        cout << ada[i].getName() << endl;

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