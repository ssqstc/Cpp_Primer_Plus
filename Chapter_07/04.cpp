#include "iostream"
using namespace std;

long double probability(unsigned int number, unsigned int picks);
int main(){
    unsigned int total, choices;
    cout << "Enter the total number of choices on the game card and the number of picks allowed:" << endl;
    while ((cin >> total >> choices) && choices <= total) {     // 连续输入两个数 分别存在在两个变量中
        cout << "You have one chance in " << probability(total, choices) << " of winning." << endl;   // 调用函数
        cout << "Please enter next to number(q to quit): " ;
    }
    cout << "Bye" << endl;
    return 0;
}
long double probability(unsigned int number,  unsigned int picks){      // 定义彩票中奖概率函数
    double n, p;
    long double result = 1.0;
    for (n = number, p = picks; p > 0 ; n--, p--) {
        result = result * n / p;
        return result;
    }
}