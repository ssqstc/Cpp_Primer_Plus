#include "iostream"
using namespace std;

struct CandyBar
{
    char brand[20];
    double weight;
    unsigned int calories;
};
int main()
{
    CandyBar snack = {"Mocha Munch",2.3,350};
    cout << "brand: " << snack.brand << " ,weight: " << snack.weight << " ,calories: " << snack.calories;

    return 0;
}