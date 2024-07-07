#include "iostream"
using namespace std;
const int strsize = 40;
const int usersize = 4;
void print_by_fullname();
void print_by_title();
void print_by_bopname();
void print_by_pref();

struct bop
{
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int perference;    // 0 = fullname, 1 = title, 2 = bopname
};
bop user[usersize] = {
        {"Rick","Level_A","RR",0},
        {"Jack","Level_B","JJ",1},
        {"Micheal","Level_C","MM",2},
        {"Rose","Level_D","RR",0},
};
void menu();
int main()
{
    char input;
    menu();
    cin >> input;
    while ('q' != input)
    {
        switch (input)
        {
            case 'a': print_by_fullname(); break;
            case 'b': print_by_title(); break;
            case 'c': print_by_bopname(); break;
            case 'd': print_by_pref(); break;
            default:
                cout << "Please enter character a, b, c, d, q:" << endl;
        }
        menu();
        cin >> input;
    }
    cout << "Bye" << endl;
    return 0;
}

void menu()
{
    cout << "Benevolent Order of  Programmers Report" << endl;
    cout << "a. display by name\t\t\tb. display by title\n"
            "c. display by bopname\t\td. display by preference\n"
            "q. quit\n";
}
void print_by_fullname()
{
    for (int i = 0; i < usersize; ++i)
        cout << user[i].fullname << endl;
}
void print_by_title()
{
    for (int i = 0; i < usersize; ++i)
        cout << user[i].title << endl;
}
void print_by_bopname()
{
    for (int i = 0; i < usersize; ++i)
        cout << user[i].bopname << endl;
}
void print_by_pref()
{
    for (int i = 0; i < usersize; ++i)
    {
        switch (user[i].perference)
        {
            case 0: cout << user[i].fullname << endl; break;
            case 1: cout << user[i].title << endl; break;
            case 2: cout << user[i].bopname << endl; break;
        }
    }
}