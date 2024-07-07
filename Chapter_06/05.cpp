#include "iostream"
using namespace std;

enum {red, orange, yellow, green, violet, indigo};

int main()
{
    int code;
    cout << "Enter color code (0~6):";
    cin >> code;

    while (code >= red && code <= indigo)
    {
        switch (code)
        {
            case red: cout << "You choose red" << endl; break;
            case orange: cout << "You choose orange" << endl; break;
            case yellow: cout << "You choose yellow" << endl; break;
            case green: cout << "You choose green" << endl; break;
            case violet: cout << "You choose violet" << endl; break;
            case indigo: cout << "You choose indigo" << endl; break;
        }
        cout << "Enter color code (0~6):";
        cin >> code;
    }
    cout << "Bye!" << endl;
    return 0;
}