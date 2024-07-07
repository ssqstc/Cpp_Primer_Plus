#include "iostream"
using namespace std;

int main()
{
    cout << "Please enter a word:";
    string word;
    cin >> word;

    int i, j;
    char tmp;

    for (j = 0, i = word.size() -1; j < i; j++, i--)    // 逗号运算符先计算第一个表达式，再计算第二个表达式
    {
        tmp = word[i];
        word[i] = word[j];
        word[j] = tmp;
    }
    cout << word;

    return 0;
}