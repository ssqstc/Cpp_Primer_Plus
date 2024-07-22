#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 结构体：定义一个 `patron` 结构体，用于存储捐献者的名字和捐款数目。
 * - 动态内存分配：使用 `new` 操作符动态分配数组内存，并在程序结束时使用 `delete[]` 释放内存。
 * - 输入输出：通过 `cin` 获取用户输入，并通过 `cout` 输出结果。
 * - 条件判断：根据捐款金额分为 "Grand Patrons" 和 "Patrons" 两类。

 * 注意点：
 * - 输入验证：确保用户输入正确的捐献者数目和捐款数目。
 * - 内存管理：确保动态分配的内存在使用完毕后释放，防止内存泄漏。
 * - 循环控制：通过循环读取多个捐献者的信息，并根据条件分类输出。
 */

struct patron
{
    string patron_name; // 捐献者名字
    double patron_money{}; // 捐献数目
};

int main()
{
    int patron_num;
    cout << "输入捐献者数目:";
    cin >> patron_num;
    auto *p_patron = new patron[patron_num]; // 动态分配数组内存

    for (int i = 0; i < patron_num; ++i) {
        cout << "输入 " << i + 1 << " 号捐献者名字:";
        cin >> p_patron[i].patron_name; // 输入捐献者名字
        cout << "输入 " << i + 1 << " 号捐献数目:";
        cin >> p_patron[i].patron_money; // 输入捐献数目
    }

    cout << "Grand Patrons: " << endl;
    int count = 0;
    for (int i = 0; i < patron_num; ++i) {
        if (p_patron[i].patron_money > 10000) {
            cout << p_patron[i].patron_name << " ,捐款: " << p_patron[i].patron_money << endl; // 输出捐款超过10000的捐献者
            ++count;
        }
    }
    if (count == 0)
        cout << "none" << endl; // 如果没有捐款超过10000的捐献者，输出"none"

    cout << "Patrons: " << endl;
    for (int i = 0; i < patron_num; ++i) {
        if (p_patron[i].patron_money <= 10000)
            cout << p_patron[i].patron_name << " ,捐款: " << p_patron[i].patron_money << endl; // 输出捐款不超过10000的捐献者
    }

    delete [] p_patron; // 释放动态分配的数组内存
    return 0;
}
