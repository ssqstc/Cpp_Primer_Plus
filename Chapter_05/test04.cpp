#include "iostream"
using namespace std;

const int Principal = 100;
int main()
{
    double simple_interest = 0, compound_interest = 0;
    int year;
    for (year = 1; compound_interest <= simple_interest ; ++year) {
        simple_interest += Principal * 0.1;
        compound_interest += (compound_interest + Principal) * 0.05;
    }
    cout << "第" << year << "年，Cleo的投资价值超过Daphne。\n" << "此时，Daphne的单利: " << simple_interest << "$\tCleo的复利：" << compound_interest << "$";

    return 0;
}