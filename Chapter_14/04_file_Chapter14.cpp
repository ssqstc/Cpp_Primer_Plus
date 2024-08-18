#include "04_head_Chapter14.h"

// Worker 类的 `set` 方法：设置员工的姓名和 ID
void Worker::set() {
    cout << "Enter worker's fullname: ";
    getline(cin, fullName); // 输入员工姓名
    cout << "Enter worker's ID: ";
    cin >> id; // 输入员工 ID
    while (cin.get() != '\n'); // 清空输入缓冲区
}

// Worker 类的 `show` 方法：显示员工的姓名和 ID
void Worker::show() const {
    cout << "Name: " << fullName << endl;
    cout << "Employee ID: " << id << endl;
}

// Waiter 类的 `set` 方法：设置服务员的风度评分
void Waiter::set() {
    Worker::set(); // 调用基类的 `set` 方法设置姓名和 ID
    cout << "Enter waiter's panache rating: ";
    cin >> panache; // 输入风度评分
    while (cin.get() != '\n'); // 清空输入缓冲区
}

// Waiter 类的 `show` 方法：显示服务员的姓名、ID 和风度评分
void Waiter::show() const {
    Worker::show(); // 调用基类的 `show` 方法显示姓名和 ID
    cout << "Panache rating: " << panache << endl; // 显示风度评分
}

// Singer 类的静态常量字符数组，表示各个声部的名称
const char* Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

// Singer 类的 `set` 方法：设置歌手的声部
void Singer::set() {
    Worker::set(); // 调用基类的 `set` 方法设置姓名和 ID
    int i;
    // 显示声部选项供用户选择
    for (i = 0; i < vTypes; ++i) {
        cout << i << ": " << pv[i];
        if (i % 4 == 3) { // 每行显示 4 个选项
            cout << endl;
        }
    }
    if (i % 4 != 0) {
        cout << endl; // 换行，确保输出格式美观
    }
    cout << "Please enter a value >=0 and <" << vTypes << endl;
    cin >> voice; // 输入声部的索引值
    while (cin.get() != '\n'); // 清空输入缓冲区
}

// Singer 类的 `show` 方法：显示歌手的姓名、ID 和声部
void Singer::show() const {
    Worker::show(); // 调用基类的 `show` 方法显示姓名和 ID
    cout << "Voice range: " << pv[voice] << endl; // 显示歌手的声部
}