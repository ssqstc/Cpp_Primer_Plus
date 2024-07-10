#include "iostream"
using namespace std;

char *buildstr(char c, int n);

int main(){
    char ch;
    int times;
    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;

    char *ps = buildstr(ch, times);
    cout << ps << endl;

    delete []ps;
    return 0;
}
char *buildstr(char c, int n){
    char *pstr = new char[n + 1];
    pstr[n] = '\0';
    for (int i = 0; i < n; ++i) {
        pstr[i] = c;
    }
    return pstr;
}