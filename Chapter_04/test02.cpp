#include "iostream"
using namespace std;

int main()
{
    cout << "Enter your name:\n";
    string name;
    getline(cin,name);

    cout << "Enter your favorite dessert:\n";
    string dessert;
    getline(cin,dessert);

    cout << "I have some delicious " << dessert << " for you, " << name << ".\n";

    return 0;
}