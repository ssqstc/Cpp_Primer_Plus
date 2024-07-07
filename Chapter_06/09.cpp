#include "iostream"
using namespace std;

// 高尔夫得分案例
const int Max = 5;

int main()
{
    int golf[Max];
    cout << "Please enter your golf scores: " << endl;
    cout << "You must enter " << Max << " rounds." << endl;

    int i;
    for (i = 0; i < Max; i++)
    {
        cout << "Round #" << i + 1 << ": "  << endl;
        while (!(cin >> golf[i]))       // 判断是否输入错误
        {
            cin.clear();        // 重置cin接受新的输入
            while (cin.get() != '\n') continue;      // 删除错误输入
            cout << "Please enter a number: ";      // 提示用户再输入
        }
    }
    double total = 0.0;
    for (int j = 0; j < Max; ++j)       // 计算总得分
        total += golf[j];

    cout << "Average score: " << total / Max;

    return 0;
}