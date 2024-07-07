#include "iostream"
using namespace std;
#include "array"
int main()
{
    const int count = 3;
    array <float,count> score;
    cout << "Enter 40m score:";
    cin >> score[0];
    cout << "Enter 40m score:";
    cin >> score[1];
    cout << "Enter 40m score:";
    cin >> score[2];

    cout << "1sh:" << score[0] << endl;
    cout << "2nd:" << score[1] << endl;
    cout << "3rd:" << score[2] << endl;
    cout << count << "次平均成绩：" << (score[0] + score[1] + score[2]) / count;
    return 0;
}