#include "iostream"
using namespace std;
int main()
{
    double income;

        cout << "输入收入：";
    while (cin >> income && income > 0)
    {
        if (income <= 5000)
            cout << "所得税 = 0 tvarps\n";
        else if (income <= 15000)
            cout << "所得税 = " << (income - 5000) * 0.10 << " tvarps\n";
        else if (income <= 35000)
            cout << "所得税 = " << (income - 15000) * 0.15 + 10000 * 0.10 << " tvarps\n";
        else
            cout << "所得税 = " << (income - 35000) * 0.20 + 10000 * 0.10 + 20000 * 0.15 << " tvarps\n";
        cout << "输入收入：";
    }
    return 0;
}