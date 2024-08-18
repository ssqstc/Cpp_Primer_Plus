#ifndef HEAD_05_CHAPTER14_H
#define HEAD_05_CHAPTER14_H

#include <iostream>
#include <string>
using namespace std;

class Worker {
private:
    string fullName; // 全名
    long id;         // 工号
protected:
    virtual void data() const; // 显示基本数据
    virtual void get();        // 获取基本数据
public:
    Worker() : fullName("none one"), id(0) {} // 默认构造函数
    Worker(const string& s, long n) : fullName(s), id(n) {} // 带参构造函数
    virtual ~Worker() {} // 虚析构函数
    virtual void set() = 0;   // 纯虚函数，设置对象数据
    virtual void show() const = 0; // 纯虚函数，显示对象数据
};

class Waiter : virtual public Worker {
private:
    int panache; // 风度评分
protected:
    virtual void data() const; // 显示风度评分
    virtual void get();        // 获取风度评分
public:
    Waiter() : Worker(), panache(0) {} // 默认构造函数
    Waiter(const string& s, long n, int p = 0) : Worker(s, n), panache(p) {} // 带参构造函数
    Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {} // 拷贝构造函数
    virtual void set();  // 设置 Waiter 对象的数据
    virtual void show() const; // 显示 Waiter 对象的数据
};

class Singer : virtual public Worker {
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor}; // 声乐类型枚举
    enum {vTypes = 7}; // 声乐类型的数量
    virtual void data() const; // 显示声乐类型
    virtual void get();        // 获取声乐类型
private:
    static const char* pv[vTypes]; // 静态字符数组，存储声乐类型
    int voice; // 声乐类型的索引
public:
    Singer() : Worker(), voice(other) {} // 默认构造函数
    Singer(const string& s, long n, int v = other) : Worker(s, n), voice(v) {} // 带参构造函数
    Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {} // 拷贝构造函数
    virtual void set();  // 设置 Singer 对象的数据
    virtual void show() const; // 显示 Singer 对象的数据
};

class SingingWaiter : public Waiter, public Singer {
protected:
    virtual void data() const {} // 重写，但不需额外实现
    virtual void get() {}        // 重写，但不需额外实现
public:
    SingingWaiter() {} // 默认构造函数
    SingingWaiter(const string& s, long n, int p = 0, int v = other)
            : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {} // 带参构造函数
    SingingWaiter(const Worker& wk, long p = 0, int v = other)
            : Worker(wk), Waiter(wk, p), Singer(wk, v) {} // 拷贝构造函数
    virtual void set();  // 设置 SingingWaiter 对象的数据
    virtual void show() const; // 显示 SingingWaiter 对象的数据
};

#endif //HEAD_05_CHAPTER14_H