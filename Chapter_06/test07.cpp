#include "iostream"
using namespace std;
#include "cctype"
int main()
{
    string word;
    int vowels_count = 0, consonants_count = 0, count = 0;

    cout << "Enter words (q to quit):";
    while (cin >> word && word != "q")  // 非法输入或输入q退出
    {
        ++count;
        if (isalpha(word[0]))       // 判断是否字母开头
        {
            switch (word[0]) {
                case 'a': case 'e':
                case 'i': case 'o':
                case 'u': case 'A':
                case 'E': case 'I':
                case 'O': case 'U':
                    ++vowels_count;
                    break;
                default:
                    ++consonants_count;
            }
        }
    }
    cout << vowels_count << " words beginning with vowels\n";
    cout << consonants_count << " words beginning with consonants\n";
    cout << count - vowels_count - consonants_count << " others";

    return 0;
}