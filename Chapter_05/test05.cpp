#include "iostream"
using namespace std;

int main()
{
    const string Month[] = {"1月","2月","3月","4月","5月","6月","7月","8月","9月","10月","11月","12月"};
    int sales_volume[sizeof Month / sizeof Month[0]], total = 0;

    for (int i = 0; i < sizeof Month / sizeof Month[0]; ++i) {
        cout << "Enter " << Month[i] << "《C++ For Fools》book sales volume：";
        cin >> sales_volume[i];
    }
    for (int i = 0; i < sizeof sales_volume / sizeof sales_volume[0]; ++i) {
        total += sales_volume[i];
    }
    cout << "今年销售总额：" << total;
    return 0;
}