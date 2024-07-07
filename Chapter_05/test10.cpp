#include "iostream"
using namespace std;

int main()
{
    cout << "Enter number of rows: ";
    int count;
    cin >> count;

    for (int i = 1; i <= count; ++i) {

        for (int j = count - i; j > 0; --j) {
            cout << ".";
        }
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}