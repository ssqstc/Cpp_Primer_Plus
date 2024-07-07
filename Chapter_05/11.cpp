#include "iostream"
using namespace std;
/*
 *
 */
int main()
{
    int n;
    cout << "Enter numbers in the range 1~10 to find my favorite number:";
    cin >> n;
//    while (n != 6)
//    {
//        cin >> n;
//    }
    do {
        cin >> n;
    } while (n != 6);

    return 0;
}