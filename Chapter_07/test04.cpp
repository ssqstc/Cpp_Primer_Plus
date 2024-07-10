#include "iostream"
using namespace std;

long double probability(unsigned int number, unsigned int picks);
int main(){
    long double field = probability(47,5);
    long double special = probability(27,1);
    long double result = field * special;
    cout << result << endl;
    cout << "Bye" << endl;
    return 0;
}
long double probability(unsigned int number,  unsigned int picks){      // 定义彩票中奖概率函数
    double n, p;
    long double result = 1.0;
    for (n = number, p = picks; p > 0 ; n--, p--) {
        result = result * p / n;
        return result;
    }
}