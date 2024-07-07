#include <iostream>
using namespace std;

int main()
{
    float height_inch;
    cout << "你的身高是:_";
    cin >> height_inch;
    const int FOOT_TO_INCH = 12;
    float height_foot = height_inch / FOOT_TO_INCH ;
    cout << "你的身高是：" << height_inch << " 英寸, " << height_foot << "英尺。";
    return 0;
}
