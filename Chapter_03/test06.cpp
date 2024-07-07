#include "iostream"
using namespace std;
const double KILOMETER_TO_MILE = 62.14;
const double GALLON_TO_LITER = 3.875;
int main()
{
    double kilometer, liter;
    cout << "输入驱车里程（公里）：";
    cin >> kilometer;
    cout << "输入使用油量（升）：";
    cin >> liter;
    cout << "每100公里耗油" << liter / kilometer * 100 << "升。" << endl;
    cout << "耗油一加仑里程" << kilometer / 100 * KILOMETER_TO_MILE / GALLON_TO_LITER / liter;
    return 0;
}