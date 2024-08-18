#include "03_head_Chapter14.h"

/*
 * 知识点总结：
 * 1. `using` 声明：使用 `using` 声明将基类 `valarray<double>` 的 `size()` 和 `operator[]` 引入 `Student` 类的公共接口中，使其对外可见。
 * 2. 私有继承：`Student` 类私有继承了 `string` 和 `valarray<double>`，对基类成员进行封装，并通过类型转换或 `using` 声明选择性暴露接口。
 * 3. 运算符重载：重载了 `[]`、`<<`、`>>` 等操作符，方便操作 `Student` 对象的数据，并自定义输入输出格式。
 * 4. 构造函数多态：提供了多个构造函数，支持通过不同参数（如名字、成绩数组等）初始化 `Student` 对象。

 * 注意点：
 * 1. `using` 声明：注意通过 `using` 声明引入的基类成员，其访问权限会变成当前类的访问权限。
 * 2. 私有继承：由于私有继承，基类的接口在 `Student` 类之外是不可见的，只有通过显式声明或友元函数才能访问。
 * 3. 兼顾类型转换：在实现操作符重载时，需兼顾基类的类型转换和访问权限，避免访问错误。
 * 4. 输入处理：使用 `getline` 处理输入时，需注意缓冲区的管理，确保不影响后续输入操作。
 */

const int PUPILS = 3;  // 学生人数
const int QUIZZES = 5; // 每个学生的测验次数

void set(Student& sa, int n); // 设置学生信息的函数声明

int main() {
    // 初始化三个 `Student` 对象数组，使用构造函数为每个学生预留 QUIZZES 个成绩空间
    Student ada[PUPILS] = {Student(QUIZZES), Student(QUIZZES), Student(QUIZZES)};
    int i;

    // 使用 `set` 函数为每个学生输入姓名和成绩
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

// `set` 函数：用于设置学生的姓名和成绩
void set(Student& sa, int n) {
    cout << "Please enter the student's name:"; // 提示输入学生姓名
    getline(cin, sa); // 使用自定义的 `getline` 函数输入学生姓名
    cout << "Please enter: " << n << " quiz scores: " << endl; // 提示输入学生的成绩
    for (int i = 0; i < n; ++i)
        cin >> sa[i]; // 通过重载的 `[]` 操作符输入成绩
    while (cin.get() != '\n'); // 清空输入缓冲区，防止影响后续输入
}