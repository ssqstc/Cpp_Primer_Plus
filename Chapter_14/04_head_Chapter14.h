#ifndef HEAD_04_CHAPTER14_H
#define HEAD_04_CHAPTER14_H

#include <iostream>
#include <string>

using namespace std;

// `Worker` 类：表示一个员工的基本信息
class Worker {
private:
    string fullName; // 员工姓名
    long id; // 员工 ID
public:
    Worker() : fullName("none one"), id(0) {} // 默认构造函数
    Worker(const string& s, long n) : fullName(s), id(n) {} // 带参数的构造函数
    virtual ~Worker() {} // 虚析构函数，确保派生类资源的正确释放
    virtual void set(); // 虚函数，设置员工信息
    virtual void show() const; // 虚函数，显示员工信息
};

// `Waiter` 类：派生自 `Worker`，表示一个服务员
class Waiter : public Worker {
private:
    int panache; // 服务员的风度评分
public:
    Waiter() : Worker(), panache(0) {} // 默认构造函数，初始化风度评分为 0
    Waiter(const string& s, long n, int p = 0) : Worker(s, n), panache(p) {} // 带参数的构造函数
    Waiter(const Worker& wk, int p = 0) : Worker(wk), panache(p) {} // 使用基类对象初始化
    virtual void set(); // 重写 `set` 方法，设置服务员特有的信息
    virtual void show() const; // 重写 `show` 方法，显示服务员特有的信息
};

// `Singer` 类：派生自 `Worker`，表示一个歌手
class Singer : public Worker {
protected:
    // 枚举类型，定义不同的声部
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {vTypes = 7}; // 声部种类数量
private:
    static const char* pv[vTypes]; // 静态常量字符数组，表示声部名称
    int voice; // 歌手的声部
public:
    Singer() : Worker(), voice(other) {} // 默认构造函数，初始化为 `other` 声部
    Singer(const string& s, long n, int v = other) : Worker(s, n), voice(v) {} // 带参数的构造函数
    Singer(const Worker& wk, int v = other) : Worker(wk), voice(v) {} // 使用基类对象初始化
    virtual void set(); // 重写 `set` 方法，设置歌手特有的信息
    virtual void show() const; // 重写 `show` 方法，显示歌手特有的信息
};

#endif //HEAD_04_CHAPTER14_H