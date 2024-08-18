#include "01_head_Chapter14.h"

// 实现部分：Student 类的成员函数与运算符重载

// 计算学生的平均成绩
double Student::average() const {
    if (scores.size() > 0)
        return scores.sum() / scores.size(); // 使用 valarray 的 sum 和 size 方法计算平均分
    else
        return 0; // 如果成绩数组为空，返回 0
}

// 返回学生的姓名
const string& Student::Name() const {
    return name; // 返回 name 成员
}

// 重载 [] 操作符：返回对学生成绩的引用，可以修改成绩
double& Student::operator[](int n) {
    return scores[n]; // 返回 scores 数组中的第 n 个元素的引用
}

// 重载 [] 操作符：只读方式访问学生成绩
double Student::operator[](int n) const {
    return scores[n]; // 返回 scores 数组中的第 n 个元素的值
}

// 重载 >> 操作符：输入学生的姓名
istream& operator>>(istream& is, Student& stu) {
    is >> stu.name; // 输入 name 成员
    return is;
}

// 自定义 getline 函数：用于输入包含空格的学生姓名
istream& getline(istream& is, Student& stu) {
    getline(is, stu.name); // 使用标准库 getline 函数输入 name 成员
    return is;
}

// 重载 << 操作符：输出学生的成绩列表
ostream& operator<<(ostream& os, const Student& st) {
    os << "Scores for " << st.name << ": " << endl; // 输出学生姓名
    int lim = st.scores.size(); // 获取成绩数组的大小
    if (lim > 0) {
        int i;
        for (i = 0; i < lim; ++i) {
            os << st.scores[i] << " "; // 输出成绩
            if (i % 5 == 4) // 每 5 个成绩换行
                os << endl;
        }
        if (i % 5 != 0)
            os << endl; // 如果最后一行未满 5 个成绩，强制换行
    } else
        os << "Empty array!" << endl; // 如果成绩数组为空，输出提示信息
    return os;
}