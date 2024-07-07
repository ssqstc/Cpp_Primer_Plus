#include "iostream"
using namespace std;

struct William_Wingate
{
    char name[50];
    double diameter, weight;
};

int main()
{
    William_Wingate *information = new William_Wingate;

    cout << "Enter pizza diameter: ";
    cin >> information->diameter;

    cout << "Enter pizza company name: ";
    cin.get();
    cin.getline(information->name,50);

    cout << "Enter pizza weight: ";
    cin >> information->weight;

    cout << "Pizza company name: " << information->name << " ,pizza diameter " << information->diameter << " ,pizza weight: " << information->weight;

    delete information;     // 记得释放空间
    return 0;
}