#ifndef HEAD_01_CHAPTER14_H
#define HEAD_01_CHAPTER14_H

#include <iostream>
#include <valarray> // 引入 valarray 库，方便数组操作

using namespace std;

// Student 类：表示一个学生的姓名和成绩
class Student {
private:
    typedef valarray<double> ArrayDb; // 使用 typedef 定义成绩数组类型
    string name; // 学生姓名
    ArrayDb scores; // 学生成绩

public:
    // 构造函数：
    Student() : name("Null student"), scores() {} // 默认构造函数，初始化为空学生
    explicit Student(const string& s) : name(s), scores() {} // 使用姓名初始化
    explicit Student(int n) : name("Null student"), scores(n) {} // 使用成绩数组大小初始化
    Student(const string& s, int n) : name(s), scores(n) {} // 使用姓名和成绩数组大小初始化
    Student(const string& s, const ArrayDb& db) : name(s), scores(db) {} // 使用姓名和成绩数组初始化
    Student(const string& s, const double* pd, int n) : name(s), scores(pd, n) {} // 使用姓名和 C 风格数组初始化
    virtual ~Student() {} // 虚析构函数，确保继承时正确释放资源

    double average() const; // 计算平均成绩
    const string& Name() const; // 获取学生姓名
    double& operator[](int n); // 重载 [] 操作符，返回成绩的引用
    double operator[](int n) const; // 重载 [] 操作符，返回成绩的值

    friend istream& operator>>(istream& is, Student& stu); // 重载 >> 操作符，输入学生信息
    friend istream& getline(istream& is, Student& stu); // 自定义 getline 函数，输入学生姓名
    friend ostream& operator<<(ostream& os, const Student& st); // 重载 << 操作符，输出学生信息
};

#endif // HEAD_01_CHAPTER14_H