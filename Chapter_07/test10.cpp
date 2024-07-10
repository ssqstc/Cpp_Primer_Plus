#include "iostream"
using namespace std;

double calculate(double a, double b, double (*pa)(double, double));
double add(double x, double y);
double reduce(double  x, double y);
double take(double  x, double y);
double remove(double  x, double y);

int main(){
    double num1, num2;
    double (*pf[4])(double, double) = {add, reduce, take, remove};
    cout << "Enter two number: \n";
    while (cin >> num1 >> num2){
        for (int i = 0; i < 4; ++i) {
            cout << calculate(num1, num2, pf[i]) << endl;
        }
        cout << "Next two number: \n";
    }
    return 0;
}
double calculate(double a, double b, double (*pa)(double, double)){
    return pa(a,b);
}
double add(double x, double y){
    return x + y;
}
double reduce(double  x, double y){
    return x - y;
}
double take(double  x, double y){
    return x * y;
}
double remove(double  x, double y){
    return x / y;
}