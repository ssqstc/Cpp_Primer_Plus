#include "iostream"
using namespace std;

struct William_Wingate
{
    char name[50];
    double diameter, weight;
};
int main()
{
    William_Wingate information;

    cout << "Enter pizza company name: ";
    cin.getline(information.name,50);

    cout << "Enter pizza diameter: ";
    cin >> information.diameter;

    cout << "Enter pizza weight: ";
    cin >> information.weight;

    cout << "Pizza company name: " << information.name << " ,pizza diameter " << information.diameter << " ,pizza weight: " << information.weight;
    return 0;
}