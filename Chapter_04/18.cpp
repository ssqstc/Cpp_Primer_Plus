#include "iostream"
using namespace std;
char * getname();
int main()
{
    char *name;
    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete []name;

    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete []name;
    return 0;
}
char * getname()
{
    char tmp[80];
    cout << "Enter your name:";
    cin >> tmp;
    char *pn = new char[strlen(tmp)+1];
    strcpy(pn,tmp);
    return pn;
}