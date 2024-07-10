#include "iostream"
#include "array"
using namespace std;

const int Seasons = 4;
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct expenditure{
    double exp[Seasons];
};

void fill2(expenditure *pa2, int len);
void show2(const expenditure *da2, int len);

int main(){
    expenditure expenses{};

    fill2(&expenses, Seasons);
    show2(&expenses,Seasons);
    return 0;
}

void fill2(expenditure *pa2, int len){
    for (int i = 0; i < len; ++i) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pa2->exp[i];
    }
}
void show2(const expenditure *da2, int len){
    double total = 0.0;
    cout << "EXPENSES:" << endl;
    for (int i = 0; i < len; ++i) {
        cout << Snames[i] << " expenses: $" << da2->exp[i] << endl;
        total += da2->exp[i];
    }
    cout << "Total expenses: $" << total << endl;
}