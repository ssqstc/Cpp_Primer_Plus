#include "iostream"
using namespace std;
#include "cstring"

int main()
{
    char word[20];
    int count = 0;
    cout << "Enter words (to stop, type the word done):";
    cin >> word;
    while (strcmp(word, "done") != 0)
    {
        cin >> word;
        count++;
    }
    cout << "You entered a total of " << count << " words.";

    return 0;
}