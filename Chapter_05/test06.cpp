#include "iostream"
using namespace std;

int main()
{
    const string Month[] = {"1月","2月","3月","4月","5月","6月","7月","8月","9月","10月","11月","12月"};
    int sales_volume[3][12], total[3]{};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 12; ++j) {
            cout << "Enter " << i + 1 << "year\t" << Month[j] << "《C++ For Fools》book sales volume：";
            cin >> sales_volume[i][j];
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 12; ++j) {
            total[i] += sales_volume[i][j];
        }
        cout << i + 1 << " year sales volume：" << total[i] << endl;
    }
    cout << "今年销售总额：" << total[0] + total[1] + total[2];
    return 0;
}