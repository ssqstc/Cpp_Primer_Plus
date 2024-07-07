#include "iostream"
using namespace std;
// switch语句，更适用于从大型列表中进行选择
void show_menu(void);
void report(void);
void comfort(void);
int main()
{

    int choice;
    do {
        show_menu();
        cin >> choice;

        switch (choice)
        {
            case 1: cout << "Waring!" << endl;
                break;
            case 2: report();
                break;
            case 3: cout << "The boss was in all day" << endl;
                break;
            case 4: comfort();
                break;
            default: cout << "That is not a choice." << endl;
        }

        cout << "------------分割线------------" << endl;
    }while (choice != 5);

    return 0;
}
void show_menu(void)
{
    cout << "Please enter 1,2,3,4,5 as your choice:" << endl;
    cout << "1) alarm    2) report" << endl;
    cout << "3) alibi    4) comfort" << endl;
    cout << "5) quit" << endl;
}
void report(void)
{
    cout << "Sales are up 120%. Expenses are down 35%." << endl;
}
void comfort(void)
{
    cout << "You are the best CEO!" << endl;
}