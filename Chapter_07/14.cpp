#include "iostream"
using namespace std;
// string函数
void display(const string sa[], int n);
const int SIZE = 5;
int main(){
    string list[SIZE];
    cout << "Enter " << SIZE << " favorite food: " << endl;     // 依次输入最喜欢的食物
    for (int i = 0; i < SIZE; ++i) {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }
    cout << "Your list: " << endl;
    display(list, SIZE);

    return 0;
}
void display(const string sa[], int n){     // 创建展示的函数
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": " << sa[i] << endl;
    }
}