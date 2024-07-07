#include "iostream"
using namespace std;

struct CandyBar
{
    char brand[20];
    double weight;
    int calories;
};
int main()
{
    CandyBar arr[3] {
            {"Mocha Munch 1",1.3,150},
            {"Mocha Munch 2",2.3,250},
            {"Mocha Munch 3",3.3,350}
    };

    cout << "arr1 brand: " << arr->brand << " ,arr1 weight: " << arr->weight << " ,arr1 calories: " << arr->calories << endl;
    cout << "arr2 brand: " << arr[1].brand << " ,arr2 weight: " << arr[1].weight << " ,arr2 calories: " << arr[1].calories << endl;
    cout << "arr3 brand: " << arr[2].brand << " ,arr3 weight: " << arr[2].weight << " ,arr3 calories: " << arr[2].calories;

    return 0;
}