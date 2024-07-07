#include "iostream"
using namespace std;

// cin.get()； 与cin.getline()类似，都读取到行尾，但是get()并不再读取并丢弃换行符。
int main()
{
    const int Size = 20;
    char name1[Size];
    char dessert[Size];

    cout << "Enter your name:\n";
//    cin.get(name1,Size);
//    cin.get();  //  读取换行符     不带参数的get()读取下一个字符
    cin.get(name1,Size).get();
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert,Size);
    cout << "I have some delicious " << dessert;
    cout << " for you , " << name1 << endl;
    return 0;
}