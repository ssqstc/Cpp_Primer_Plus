#include "iostream"
using namespace std;
// cin 使用空白（空格、制表符和换行符）来确定字符串的结束位置。
// cin.getline(name,20)； 通过输入回车或者达到指定数目来确定输入结尾。
int main()
{
    const int Size = 20;
    char name1[Size];
    char dessert[Size];

    cout << "Enter your name:\n";
    cin.getline(name1,Size);
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert,Size);
    cout << "I have some delicious " << dessert;
    cout << " for you , " << name1 << endl;
    return 0;
}