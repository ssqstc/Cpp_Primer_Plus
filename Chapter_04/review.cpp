#include "iostream"
using namespace std;
#include "array"
#include "vector"
int main()
{
    char actor1[30];
    short betsie1[100];
    float chuck1[13];
    long double dipsea1[64];

    array <char, 30> actor2;
    array <short, 100> betsie2;
    array <float, 13> chuck2;
    array <long double, 64> dipsea2;

    int test3[] = {1,3,5,7,9};

    int even = test3[0] + test3[4];

    int ideas[] = {1,2,3};
    cout << ideas[1];

    char test6[] = "chesseburger";

    string test7 = "WaldorfSalad";

    struct fish
    {
        string var;
        int weight_ounce;
        double length_inch;
    };

    fish goldfish = {"金鱼",6,6.6};

    enum Response {No,Yes,Maybe};

    double ted = 1.6;
    double* p_ted = &ted;
    cout << *p_ted;

    float treacle[10] = {1,2,3,4,5,6,7,8,9,10};
    float *p_treacle = treacle;
    cout << p_treacle << " " << p_treacle[9];

    cout << "输入一个正整数";
    int tmp;
    cin >> tmp;
    int *test13_1= new int[tmp];
    vector <int> test13_2(tmp);

    // address

    fish *p_fish = new fish;
    cout << p_fish->var << p_fish->weight_ounce << p_fish->length_inch;

    // Don't enter space

    const int tmp2 = 10;
    std::vector <std::string> vec(tmp2);
    std::array <std::string, tmp2> arr;

    return 0;
}