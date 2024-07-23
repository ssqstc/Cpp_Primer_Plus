#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 结构体：定义和使用结构体。
 * 2. 动态内存分配：使用 `new` 和 `delete` 进行动态内存分配和释放。
 * 3. 输入输出：使用 `cin` 和 `cout` 进行数据输入和输出。
 * 4. 函数传参：通过值传递、指针传递和数组传递函数参数。
 *
 * 注意点：
 * 1. 输入验证：确保用户输入的数据是有效的。
 * 2. 内存管理：动态分配的内存要及时释放，避免内存泄漏。
 * 3. 指针操作：指针的使用要谨慎，确保指针在有效范围内。
 * 4. 数组边界：操作数组时注意边界，防止越界访问。
 */

const int SLEN = 30;  // 字符串最大长度
struct student {
    char fullname[SLEN];  // 学生全名
    char hobby[SLEN];     // 学生爱好
    int ooplevel;         // 学生编程水平
};

// 函数声明
int getinfo(student pa[], int n); // 获取学生信息
void display1(student st); // 显示学生信息，值传递
void display2(const student *ps); // 显示学生信息，指针传递
void display3(const student pa[], int n); // 显示学生信息，数组传递

int main(){
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size; // 输入班级人数
    while (cin.get() != '\n'){
        continue; // 清除输入缓冲区
    }

    student *ptr_stu = new student[class_size]; // 动态分配学生数组
    int entered = getinfo(ptr_stu, class_size); // 获取输入的学生信息

    for (int i = 0; i < entered; ++i) {
        display1(ptr_stu[i]); // 使用值传递显示学生信息
        display2(&ptr_stu[i]); // 使用指针传递显示学生信息
    }

    display3(ptr_stu, entered); // 使用数组传递显示所有学生信息
    delete [] ptr_stu; // 释放动态分配的内存
    cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n){ // 获取学生信息
    int i;
    for (i = 0; i < n; ++i) {
        cout << "Enter the name of a student: ";
        cin >> pa[i].fullname; // 输入学生姓名
        cout << "Enter the hobby of a student: ";
        cin >> pa[i].hobby; // 输入学生爱好
        cout << "Enter the level of a student: ";
        cin >> pa[i].ooplevel; // 输入学生编程水平

        if (!cin){
            cin.clear(); // 清除错误状态
            while (cin.get() != '\n'); // 清除输入缓冲区
            break;
        }
    }
    return i; // 返回输入的学生数量
}

void display1(student st){ // 显示学生信息，值传递
    cout << "fullname = " << st.fullname << " ,hobby = " << st.hobby << " ,ooplevel = " << st.ooplevel << endl;
}

void display2(const student *ps){ // 显示学生信息，指针传递
    cout << "fullname = " << ps->fullname << " ,hobby = " << ps->hobby << " ,ooplevel = " << ps->ooplevel << endl;
}

void display3(const student pa[], int n){ // 显示所有学生信息，数组传递
    for (int i = 0; i < n; ++i) {
        cout << "fullname = " << pa[i].fullname << " ,hobby = " << pa[i].hobby << " ,ooplevel = " << pa[i].ooplevel << endl;
    }
}
