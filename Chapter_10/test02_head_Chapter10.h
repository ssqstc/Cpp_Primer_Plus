#ifndef __TEST02_HEAD_CHAPTER10_H__
#define __TEST02_HEAD_CHAPTER10_H__
#include "string"
#include "iostream"
using namespace std;

/*
 * Person 类定义
 * 模拟个人姓名信息及其显示
 */
class Person{
private:
    static const int LIMIT = 25; // 名字长度限制
    string lname; // 姓
    char fname[LIMIT]{}; // 名
public:
    Person() {lname = ""; fname[0] = '\0';} // 默认构造函数
    Person(const string &ln, const char *fn = "Heyyou"); // 带参数的构造函数
    void show() const; // 显示姓名信息
    void FormalShow() const; // 正式显示姓名信息
};

#endif //__TEST02_HEAD_CHAPTER10_H__
