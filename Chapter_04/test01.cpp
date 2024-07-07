#include "iostream"
using namespace std;

int main()
{
    const int Size = 20;
    char first_name[Size], last_name[Size];
    char grade;
    float age;

    cout << "What is your first name? ";
    cin.getline(first_name,Size);

    cout << "What is your last name? ";
    cin.getline(last_name,Size);

    cout << "What letter grade do you deserve? ";
    cin >> grade;
    grade++;

    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << last_name << ", " << first_name << "\nGrade: " << grade << "\nAge: " << age;
    return 0;
}