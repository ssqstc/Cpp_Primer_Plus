#include "iostream"
using namespace std;

int main()
{
    string word;
    int count = 0;
    cout << "Enter words (to stop, type the word done):";
    cin >> word;
    while (!(word == "done"))
    {
        cin >> word;
        count++;
    }
    cout << "You entered a total of " << count << " words.";

    return 0;
}