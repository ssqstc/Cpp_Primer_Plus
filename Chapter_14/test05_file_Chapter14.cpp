#include "test05_head_Chapter14.h"

// abstr_emp 类的成员函数实现
void abstr_emp::showAll() const {
// 输出员工的名字、姓氏和职位
    cout << "name: " << fname << ' ' << lname << endl;
    cout << "job: " << job << endl;
}

void abstr_emp::setAll() {
// 设置员工的名字、姓氏和职位
    cout << "Enter your first name: ";
    getline(cin, fname); // 获取名字
    cout << "Enter your last name: ";
    getline(cin, lname); // 获取姓氏
    cout << "Enter your job: ";
    getline(cin, job); // 获取职位
}

ostream& operator<<(ostream& os, const abstr_emp& e) {
// 输出员工的名字、姓氏和职位
    os << "name: " << e.fname << ' ' << e.lname << endl;
    os << "job: " << e.job << endl;
    return os;
}

// manager 类的成员函数实现
void manager::showAll() const {
// 输出管理者的所有信息，包括管理的员工数量
    abstr_emp::showAll(); // 调用基类函数显示基本信息
    cout << "inchargeof: " << inchargeof << endl; // 显示管理的员工数量
}

void manager::setAll() {
// 设置管理者的所有信息，包括管理的员工数量
    abstr_emp::setAll(); // 调用基类函数设置基本信息
    cout << "Enter your inchargeof: ";
    cin >> inchargeof; // 设置管理的员工数量
}

// fink 类的成员函数实现
void fink::showAll() const {
// 输出 fink 的所有信息，包括汇报对象
    abstr_emp::showAll(); // 调用基类函数显示基本信息
    cout << "reportsto: " << reportsto << endl; // 显示汇报对象
}

void fink::setAll() {
// 设置 fink 的所有信息，包括汇报对象
    abstr_emp::setAll(); // 调用基类函数设置基本信息
    cout << "Enter your reportsto: ";
    getline(cin, reportsto); // 设置汇报对象
}

// highfink 类的成员函数实现
void highfink::showAll() const {
// 输出 highfink 的所有信息，包括管理的员工数量和汇报对象
    abstr_emp::showAll(); // 调用基类函数显示基本信息
    cout << "reportsto: " << reportsTo() << endl; // 显示汇报对象
    cout << "inchargeof: " << inChargeOf() << endl; // 显示管理的员工数量
}

void highfink::setAll() {
// 设置 highfink 的所有信息，包括管理的员工数量和汇报对象
    abstr_emp::setAll(); // 调用基类函数设置基本信息
    cout << "Enter your inchargeof: ";
    cin >> inChargeOf(); // 设置管理的员工数量
    cout << "Enter your reportsto: ";
    getline(cin, reportsTo()); // 设置汇报对象
}