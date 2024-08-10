#ifndef __TEST02_HEAD_CHAPTER13_H__
#define __TEST02_HEAD_CHAPTER13_H__

#include "iostream"
#include "cstring"
using namespace std;

// Cd类，管理音乐CD的基本信息
class Cd {
private:
    char *m_performers; // 动态分配的表演者信息
    char *m_label; // 动态分配的标签信息
    int m_selections; // 选择数量
    double m_playtime; // 播放时间
public:
    Cd(); // 默认构造函数
    Cd(char * s1, char * s2, int n, double x); // 参数构造函数
    Cd(const Cd & d); // 拷贝构造函数
    virtual ~Cd(); // 虚析构函数
    Cd &operator=(const Cd & d); // 赋值运算符重载
    virtual void report() const; // 虚函数，用于输出对象信息
};

// Classic类，继承自Cd，增加了特有的音乐信息
class Classic : public Cd {
private:
    char *m_str; // 动态分配的特有的音乐信息
public:
    Classic(); // 默认构造函数
    Classic(char * s1, char * s2, char * s3, int n, double x); // 参数构造函数
    Classic(const Classic & classic); // 拷贝构造函数
    virtual ~Classic(); // 虚析构函数
    Classic &operator=(const Classic &classic); // 赋值运算符重载
    virtual void report() const; // 虚函数，覆盖基类的report函数
};

#endif //__TEST02_HEAD_CHAPTER13_H__