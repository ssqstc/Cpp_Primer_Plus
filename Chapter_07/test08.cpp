#include "iostream"
#include "array"
using namespace std;

const int Seasons = 4;
const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double *arr, int len);
void show(const double *arr, int len);

int main(){
    double expenses[Seasons]{};

    fill(expenses, Seasons);
    show(expenses,Seasons);
    return 0;
}
void fill(double *arr, int len){
    for (int i = 0; i < len; ++i) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> arr[i];
    }
}
void show(const double *arr, int len){
    double total = 0.0;
    cout << "EXPENSES:" << endl;
    for (int i = 0; i < len; ++i) {
        cout << Snames[i] << " expenses: $" << arr[i] << endl;
        total += arr[i];
    }
    cout << "Total expenses: $" << total << endl;
}