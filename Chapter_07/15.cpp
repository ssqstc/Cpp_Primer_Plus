#include "iostream"
#include "array"
using namespace std;
// array函数
const int Seasons = 4;
const array <string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};
void fill(array <double, Seasons> *pa);
void show(const array <double, Seasons> *da);

int main(){
    array <double, Seasons> expenses{};       // 创建花费季节花费array对象

    fill(&expenses);
    show(&expenses);
    return 0;
}
void fill(array <double, Seasons> *pa){     // array可以像使用数组一样使用 array对象的指针并不能像数组一样操作
    for (int i = 0; i < Seasons; ++i) {     // 此时pa是array对象的指针 但pa并不是array对象
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];        // pa是array对象的指针 指针里面的值就是array对象 (*pa)取值 取出array对象
    }                           // ！！！ *pa[i]是错的 方括号[]结合的优先级比*高
}
void show(const array <double, Seasons> *da){
    double total = 0.0;
    cout << "EXPENSES:" << endl;
    for (int i = 0; i < Seasons; ++i) {
        cout << Snames[i] << " expenses: $" << (*da)[i] << endl;
        total += (*da)[i];
    }
    cout << "Total expenses: $" << total << endl;
}