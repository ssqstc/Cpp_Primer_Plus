#ifndef TEST05_HEAD_CHAPTER14_H
#define TEST05_HEAD_CHAPTER14_H

#include <iostream>
#include <string>
using namespace std;

// 抽象基类 abstr_emp，定义了基本的员工信息并且包含纯虚函数
class abstr_emp {
private:
    string fname; // 员工的名字
    string lname; // 员工的姓氏
    string job;   // 员工的职位
public:
    // 默认构造函数
    abstr_emp() : fname("null"), lname("null"), job("null") {}

    // 带参数的构造函数，用于初始化成员变量
    abstr_emp(const string& fn, const string& ln, const string& j) : fname(fn), lname(ln), job(j) {}

    // 虚函数，显示所有员工信息
    virtual void showAll() const;

    // 虚函数，设置所有员工信息
    virtual void setAll();

    // 重载的输出运算符，友元函数
    friend ostream& operator<<(ostream& os, const abstr_emp& e);

    // 纯虚析构函数，确保类为抽象类
    virtual ~abstr_emp() = 0;
};

// 派生类 employee，继承自 abstr_emp，表示普通员工
class employee : public abstr_emp {
public:
    // 默认构造函数
    employee() : abstr_emp() {}
    // 带参数的构造函数，调用基类构造函数初始化
    employee(const string& fn, const string& ln, const string& j) : abstr_emp(fn, ln, j) {}

    // 覆盖基类的 showAll 函数，显示员工信息
    void showAll() const override { abstr_emp::showAll(); }

    // 覆盖基类的 setAll 函数，设置员工信息
    void setAll() override { abstr_emp::setAll(); }
};

// 派生类 manager，虚继承自 abstr_emp，表示管理者
class manager : virtual public abstr_emp {
private:
    int inchargeof; // 管理的员工数量
protected:
    // 用于获取管理的员工数量
    int inChargeOf() const { return inchargeof; }

    // 用于设置管理的员工数量
    int& inChargeOf() { return inchargeof; }
public:
    // 默认构造函数
    manager() : abstr_emp(), inchargeof(0) {}

    // 带参数的构造函数，初始化基类和 inchargeof 成员
    manager(const string& fn, const string& ln, const string& j, int ico = 0) : abstr_emp(fn, ln, j), inchargeof(ico) {}

    // 使用基类对象和管理数量的构造函数
    manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico) {}

    // 拷贝构造函数
    manager(const manager& m) : abstr_emp(m), inchargeof(m.inchargeof) {}

    // 覆盖基类的 showAll 函数，显示管理者信息
    void showAll() const override;

    // 覆盖基类的 setAll 函数，设置管理者信息
    void setAll() override;
};

// 派生类 fink，虚继承自 abstr_emp，表示打小报告的人
class fink : virtual public abstr_emp {
private:
    string reportsto; // 汇报对象
protected:
    // 获取汇报对象
    const string reportsTo() const { return reportsto; }

    // 设置汇报对象
    string& reportsTo() { return reportsto; }
public:
    // 默认构造函数
    fink() : abstr_emp(), reportsto("null") {}

    // 带参数的构造函数，初始化基类和 reportsto 成员
    fink(const string& fn, const string& ln, const string& j, const string& rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}

    // 使用基类对象和汇报对象的构造函数
    fink(const abstr_emp& e, const string& rpo) : abstr_emp(e), reportsto(rpo) {}

    // 拷贝构造函数
    fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto) {}

    // 覆盖基类的 showAll 函数，显示 fink 信息
    void showAll() const override;

    // 覆盖基类的 setAll 函数，设置 fink 信息
    void setAll() override;
};

// 派生类 highfink，继承自 manager 和 fink，表示高级管理者
class highfink : public manager, public fink {
public:
    // 默认构造函数
    highfink() : abstr_emp(), manager(), fink() {}

    // 带参数的构造函数，初始化基类和派生类成员
    highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico) : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico) {}

    // 使用基类对象的构造函数
    highfink(const abstr_emp& e, const string& rpo, int ico) : abstr_emp(e), fink(e, rpo), manager(e, ico) {}

    // 使用 fink 对象和管理数量的构造函数
    highfink(const fink& f, int ico) : abstr_emp(f), fink(f) { inChargeOf() = ico; }

    // 使用 manager 对象和汇报对象的构造函数
    highfink(const manager& m, const string& rpo) : abstr_emp(m), manager(m) { reportsTo() = rpo; }
    // 拷贝构造函数
    highfink(const highfink& h) : abstr_emp(h), fink(h), manager(h) {}

// 覆盖基类的 showAll 函数，显示 highfink 信息
    void showAll() const override;

// 覆盖基类的 setAll 函数，设置 highfink 信息
    void setAll() override;
};

#endif // TEST05_HEAD_CHAPTER14_H