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
    CandyBar *pointer = new CandyBar[3];

    strcpy(pointer[0].brand,"Mocha Munch 1");
    pointer[0].weight = 1.3;
    pointer[0].calories = 150;

    strcpy(pointer[1].brand,"Mocha Munch 2");
    pointer[1].weight = 2.3;
    pointer[1].calories = 250;

    strcpy(pointer[2].brand,"Mocha Munch 3");
    pointer[2].weight = 3.3;
    pointer[2].calories = 350;

    cout << "pointer[0] brand: " << pointer->brand << " ,pointer[0] weight: " << pointer->weight << " ,pointer[0] calories: " << pointer->calories << endl;
    cout << "pointer[1] brand: " << pointer[1].brand << " ,pointer[1] weight: " << pointer[1].weight << " ,pointer[1] calories: " << pointer[1].calories << endl;
    cout << "pointer[2] brand: " << pointer[2].brand << " ,pointer[2] weight: " << pointer[2].weight << " ,pointer[2] calories: " << pointer[2].calories << endl;

    delete [] pointer;     // 记得释放空间 结构体数组 记得方括号
    return 0;
}