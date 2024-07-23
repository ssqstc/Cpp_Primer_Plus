#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 指针遍历数组：通过指针可以遍历数组元素，实现灵活的数组操作。
 * 2. 指针运算：指针可以进行加减运算，指向不同的数组元素。
 * 3. 函数参数：指针作为函数参数，可以实现对数组的部分或全部操作。
 *
 * 注意点：
 * 1. 指针在遍历数组时，需要注意边界，避免越界访问。
 * 2. 指针运算需要保证结果在合法范围内，否则会导致未定义行为。
 */

const int ArSize = 8;

int sum_arr(const int *begin, const int *end); // 函数声明：计算数组片段之和

int main() {
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128}; // 定义并初始化数组

    int sum = sum_arr(cookies, &cookies[ArSize]); // 计算整个数组的和
    cout << "Total cookies eaten: " << sum << endl; // 总共吃了多少饼干

    sum = sum_arr(cookies, cookies + 3); // 计算前三个元素的和
    cout << "First three eater ate: " << sum << endl; // 前三位吃了多少饼干

    sum = sum_arr(cookies + 4, cookies + ArSize); // 计算后四个元素的和
    cout << "Last four eater ate: " << sum << endl; // 后四位吃了多少饼干

    return 0;
}

int sum_arr(const int *begin, const int *end) { // 函数定义：计算数组片段之和
    int total = 0; // 初始化总和为0
    const int *pt; // 定义指针pt
    for (pt = begin; pt != end; ++pt) { // 遍历数组片段
        total += *pt; // 累加数组元素值
    }
    return total; // 返回计算结果
}
