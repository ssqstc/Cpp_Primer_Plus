#include "iostream"
using namespace std;

int main()
{
    char word[5] = "?ate";
    for (char ch = 'a'; strcmp(word, "mate"); ch++) {   // strcmp比较C语言字符串 比较结果大于1 小于-1 等于0
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;
    return 0;
}