#include "iostream"
using namespace std;

// 当确定循环次数的时候用for循环，while循环更适用于条件表达式

const int ArSize = 20;
int main()
{

    char name[ArSize];
    cout << "Your first name please: ";
    cin >> name;

    cout << "Here is your name: " << endl;
    int i = 0;
    while (name[i] != '\0')     // while(name[i])
    {
        cout << name[i] << ": " << (int)name[i] << endl;
        i++;
    }
    return 0;
}