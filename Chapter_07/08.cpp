#include "iostream"
using namespace std;

// 数组区间的使用
int sum_arr(const int *begin, const int *end);
const int ArSize = 8;
int main(){
    int cookies[ArSize] = {1,2,4,8,16,32,64,128};

    int sum = sum_arr(cookies, &cookies[ArSize]);
    cout << "Total cookies eaten: " << sum << endl;     // 全家吃了多少饼干

    sum = sum_arr(cookies, cookies + 3);
    cout << "First three eater ate: " << sum << endl;   // 前三人吃了多少饼干

    sum = sum_arr(cookies + 4, cookies + ArSize);
    cout << "Last four eater ate: " << sum << endl;     // 后四人吃了多少饼干
    return 0;
}

int sum_arr(const int *begin, const int *end){  // 使用数组区间的函数
    int total = 0;
    const int *pt;
    for (pt = begin; pt != end; ++pt) {
        total += *pt;
    }
    return total;
}