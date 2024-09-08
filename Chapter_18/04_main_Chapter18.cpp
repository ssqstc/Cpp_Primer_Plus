/*
知识点：
1. **STL算法**：使用 `std::generate` 填充 `vector`，使用 `std::count_if` 和 `std::for_each` 统计满足特定条件的元素个数。
2. **Lambda表达式**：Lambda表达式被用于自定义条件筛选以及通过捕获列表修改外部变量的值。
3. **随机数生成**：使用 `srand(time(0))` 初始化随机数种子，并通过 `rand()` 生成随机数。

注意点：
1. `rand()` 的生成范围较小，当数据量较大时（如 `SIZE = 390000`），可能会产生偏差或重复值。
2. Lambda表达式中的捕获列表，`[&]` 表示捕获所有外部变量并通过引用传递，这使得可以在 Lambda 表达式内部修改外部变量的值。
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// 定义样本大小为 390000
const int SIZE = 390000;

int main() {
    // 创建大小为 SIZE 的 vector 容器
    vector<int> numbers(SIZE);
    int count3, count13;

    // 初始化两个统计变量
    count3 = count13 = 0;

    // 使用当前时间作为种子初始化随机数生成器
    srand(time(0));

    // 使用 rand() 随机生成数据并填充容器
    generate(numbers.begin(), numbers.end(), rand);

    // 输出样本大小
    cout << "Sample size = " << SIZE << endl;

    // 使用 Lambda 表达式和 count_if 统计能被3整除的元素个数
    count3 = count_if(numbers.begin(), numbers.end(), [](int x){ return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << endl;

    // 使用 Lambda 表达式和 for_each 统计能被13整除的元素个数
    for_each(numbers.begin(), numbers.end(), [&count13](int x) { count13 += x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    // 重置计数器
    count3 = count13 = 0;

    // 使用 Lambda 表达式的引用捕获，统计能被3和能被13整除的元素个数
    for_each(numbers.begin(), numbers.end(), [&](int x) {
        count3 += x % 3 == 0;
        count13 += x % 13 == 0;
    });

    // 输出统计结果
    cout << "Count of numbers divisible by 3: " << count3 << endl;
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    return 0;
}