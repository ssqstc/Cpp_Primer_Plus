#include "iostream"
using namespace std;

int main()
{
    char first_name[80], last_name[80];

    cout << "Enter your first name: ";
    cin.getline(first_name,80);

    cout << "Enter your last name: ";
    cin.getline(last_name,80);

    strcat(first_name,", ");
    strcat(first_name,last_name);

    cout << "Here's the information in a single string: " << first_name << endl;


    return 0;
}