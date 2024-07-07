#include "iostream"
using namespace std;

struct patron
{
    string patron_name;
    double patron_money{};
};
int main()
{
    int patron_num;
    cout << "输入捐献者数目:";
    cin >> patron_num;      // 获取捐献人数
    auto *p_patron = new patron[patron_num];    // 动态创建结构体数组

    for (int i = 0; i < patron_num; ++i) {
        cout << "输入 " << i + 1 << " 号捐献者名字:";
        cin >> p_patron[i].patron_name;
        cout << "输入 " << i + 1 << " 号捐献数目:";
        cin >> p_patron[i].patron_money;
    }

    cout << "Grand Patrons: " << endl;      // 遍历重要捐款人
    int count = 0;
    for (int i = 0; i < patron_num; ++i) {
        if (p_patron[i].patron_money > 10000)
        {
            cout << p_patron[i].patron_name << " ,捐款: " << p_patron[i].patron_money << endl;
            ++count;
        }
    }
    if (count == 0)
        cout << "none" << endl;

    cout << "Patrons: " << endl;      // 遍历其他捐款人
    for (int i = 0; i < patron_num; ++i) {
        if (p_patron[i].patron_money <= 10000)
            cout << p_patron[i].patron_name << " ,捐款: " << p_patron[i].patron_money << endl;
    }

    delete [] p_patron;
    return 0;
}