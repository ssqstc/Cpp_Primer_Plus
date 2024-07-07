#include "iostream"
using namespace std;
void menu();
void carnivore();
void pianist();
void tree();
void game();
int main()
{
    char ch;
    menu();
    do {
        cin >> ch;
        switch (ch) {
            case 'c': carnivore();  break;
            case 'p': pianist();    break;
            case 't': tree();       break;
            case 'g': game();       break;
            default: cout << "Please enter a c, p, t, g: ";
        }

    }while ('c' != ch && 'p' != ch && 't' != ch && 'g' != ch);

    return 0;
}
void menu()
{
    cout << "Please enter one of the following choices:\n";
    cout << "c)\tcarnivore\t\t\tp)\tpianist\nt)\ttree\t\t\t\tg)\tgame" << endl;
}
void carnivore()
{
    cout << "A maple is a carnivore." << endl;
}
void pianist()
{
    cout << "A maple is a pianist." << endl;
}
void tree()
{
    cout << "A maple is a tree." << endl;
}
void game()
{
    cout << "A maple is a game." << endl;
}