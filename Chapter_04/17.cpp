#include "iostream"
using namespace std;

struct inflatable
{
    char name[20];
    float volume;
    double price;
};
int main()
{
    inflatable *ps = new inflatable;
    cout << "Enter name:";
    cin.get(ps->name,20);
    cout << "Enter volume:";
    cin >> (*ps).volume;
    cout << "Enter price:";
    cin >> ps->price;

    cout << "name: " << (*ps).name << " , volume: " << ps->volume << " , price: " << (*ps).price;

    delete ps;
    return 0;
}