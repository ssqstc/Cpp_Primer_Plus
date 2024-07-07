#include "iostream"
using namespace std;
#include "array"

const int SIZE = 10;
int main()
{
    array<double, SIZE> donation {};
    double input, sum = 0;
    int count = 0, average_count = 0;
    cout << "Enter number:";
    while (count < SIZE && cin >> input)     // 如果输入不是有效的双精度浮点数，cin 将会进入错误状态。返回false
    {
        donation[count++] = input;     // donation存入数组 同时计数count++
        sum += input;        // 求和
        if (count < SIZE)
            cout << "Enter next number:";
    }
    if (count == 0)
        cout << "No valid enter" << endl;       // count为0时提示
    else
    {
        cout << "average = " << sum / count;
        for (int i = 0; i < count; ++i)
        {
            if ((sum / count) <  donation[i])       // 大于平均值计数
                ++average_count;
        }
        cout << ", " << average_count << " more than the average." << endl;
    }

    return 0;
}