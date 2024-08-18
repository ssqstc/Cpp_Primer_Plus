#include "05_head_Chapter14.h"

// Worker 类的成员函数实现
void Worker::get() {
    cout << "Enter worker's fullname: "; // 提示输入全名
    getline(cin, fullName); // 获取全名
    cout << "Enter worker's ID: "; // 提示输入工号
    cin >> id; // 获取工号
    while (cin.get() != '\n'); // 清除输入缓冲区
}

void Worker::data() const {
    cout << "Name: " << fullName << endl; // 显示全名
    cout << "Employee ID: " << id << endl; // 显示工号
}

// Waiter 类的成员函数实现
void Waiter::get() {
    cout << "Enter waiter's panache rating: "; // 提示输入风度评分
    cin >> panache; // 获取风度评分
    while (cin.get() != '\n'); // 清除输入缓冲区
}

void Waiter::data() const {
    cout << "Panache rating: " << panache << endl; // 显示风度评分
}

void Waiter::set() {
    Worker::get(); // 获取 Worker 类的基本数据
    get(); // 获取 Waiter 类的特有数据
}

void Waiter::show() const {
    Worker::data(); // 显示 Worker 类的基本数据
    data(); // 显示 Waiter 类的特有数据
}

// Singer 类的静态成员初始化
const char* Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

// Singer 类的成员函数实现
void Singer::get() {
    int i;
    for (i = 0; i < vTypes; ++i) {
        cout << i << ": " << pv[i]; // 显示每种声乐类型
        if (i % 4 == 3) {
            cout << endl; // 每行显示四种类型
        }
    }
    if (i % 4 != 0) {
        cout << endl; // 如果未满四个类型则换行
    }
    cout << "Please enter a value >=0 and <" << vTypes << endl; // 提示输入有效的声乐类型编号
    cin >> voice; // 获取用户选择的声乐类型
    while (cin.get() != '\n'); // 清除输入缓冲区
}

void Singer::data() const {
    cout << "Voice range: " << pv[voice] << endl; //显示声乐类型
}

void Singer::set() {
    Worker::get(); // 获取 Worker 类的基本数据
    get(); // 获取 Singer 类的特有数据
}

void Singer::show() const {
    Worker::data(); // 显示 Worker 类的基本数据
    data(); // 显示 Singer 类的特有数据
}

// SingingWaiter 类的成员函数实现
void SingingWaiter::set() {
    Worker::get(); // 获取 Worker 类的基本数据
    Waiter::get(); // 获取 Waiter 类的特有数据
    Singer::get(); // 获取 Singer 类的特有数据
}

void SingingWaiter::show() const {
    Worker::data(); // 显示 Worker 类的基本数据
    Waiter::data(); // 显示 Waiter 类的特有数据
    Singer::data(); // 显示 Singer 类的特有数据
}