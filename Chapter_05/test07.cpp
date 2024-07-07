#include "iostream"
using namespace std;

struct car
{
    string manufacturer;
    float year;
};
int main()
{
    int num = 0;
    cout << "How many cars do you wish to catalog? ";
    cin >> num;

    car* p_car = new car[num];

    for (int i = 0; i < num; ++i) {
        cin.get();
        cout << "Car #" << i + 1 << ":\n";
        cout << "Please enter the make:";
        getline(cin,p_car[i].manufacturer);
        cout << "Please enter the year made:";
        cin >> p_car[i].year;
    }
    for (int i = 0; i < num; ++i) {
        cout << p_car[i].year << " " << p_car[i].manufacturer << endl;
    }

    delete [] p_car;
    return 0;
}