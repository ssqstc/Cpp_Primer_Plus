#include <iostream>
using namespace std;

int main()
{
    // 设置cout为固定小数点格式输出浮点数
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;     // tub: 浮点数，精确到小数点后约6位
    double mint = 10.0 / 3.0;   // mint: 双精度浮点数，精确到小数点后约15位
    const float Million = 1.0e6; // 常量，表示一百万

    // 输出tub的值
    cout << "tub = " << tub;
    // 输出一百万个tub的值
    cout << ", a Million tubs = " << Million * tub;
    // 输出一千万个tub的值
    cout << ", \nand ten Million tubs = ";
    cout << 10 * Million * tub << endl;

    // 输出mint的值
    cout << "mint = " << mint << " and a Million mints = ";
    // 输出一百万个mint的值
    cout << Million * mint << endl;

    return 0;
}
