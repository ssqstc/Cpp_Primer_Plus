/*
知识点：
1. **标准库算法**：使用 `std::generate` 函数填充容器，使用 `std::count_if` 统计符合条件的元素。
2. **Lambda表达式**：在代码末尾部分，通过 Lambda 表达式实现自定义判断条件。
3. **仿函数（函数对象）**：通过自定义的类 `f_mod`，重载 `()` 运算符，定义了一个可调用的对象来判断元素是否为某个数的倍数。
4. **容器动态调整**：使用 `std::vector::resize` 方法调整容器大小，以适应不同规模的数据处理。

注意点：
1. 在使用 `std::generate` 填充随机数时，应该用 `rand()` 函数产生随机数，但由于 `rand()` 函数在部分系统中可能产生较小的随机数序列，在大规模数据时可能需要替换为更高效的随机数生成器（如 `std::mt19937`）。
2. 由于 `rand()` 函数返回范围有限，当数据量大时，可能会出现统计结果与预期不符的情况。
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// 判断是否能被3整除的函数
bool f3(int x) { return x % 3 == 0; }

// 判断是否能被13整除的函数
bool f13(int x) { return x % 13 == 0; }

// 常量定义：不同样本数据的大小
const int SIZE1 = 39;
const int SIZE2 = 3900;
const int SIZE3 = 390000;

int main() {
    // 定义一个大小为 SIZE1 的 vector 容器
    vector<int> numbers(SIZE1);

    // 初始化随机数生成器
    srand(time(0));

    // 使用 rand() 随机生成数据并填充容器
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample size = " << SIZE1 << endl;

    // 统计能被3整除的元素个数
    int count3 = count_if(numbers.begin(), numbers.end(), f3);
    cout << "Count of numbers divisible by 3: " << count3 << endl;

    // 统计能被13整除的元素个数
    int count13 = count_if(numbers.begin(), numbers.end(), f13);
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    // 调整 vector 的大小为 SIZE2
    numbers.resize(SIZE2);

    // 再次使用 rand() 随机生成数据并填充容器
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample size = " << SIZE2 << endl;

    // 仿函数类，用于判断是否为某个数的倍数
    class f_mod {
        int dv;  // 除数
    public:
        // 构造函数，初始化除数
        f_mod(int d = 1) : dv(d) {}

        // 重载 () 运算符，实现可调用对象
        bool operator()(int x) { return x % dv == 0; }
    };

    // 使用仿函数统计能被3整除的元素个数
    count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
    cout << "Count of numbers divisible by 3: " << count3 << endl;

    // 使用仿函数统计能被13整除的元素个数
    count13 = count_if(numbers.begin(), numbers.end(), f_mod(13));
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    // 调整 vector 的大小为 SIZE3
    numbers.resize(SIZE3);

    // 使用 rand() 填充容器
    generate(numbers.begin(), numbers.end(), rand);
    cout << "Sample size = " << SIZE3 << endl;

    // 使用 Lambda 表达式统计能被3整除的元素个数
    count3 = count_if(numbers.begin(), numbers.end(), [](int x){ return x % 3 == 0; });
    cout << "Count of numbers divisible by 3: " << count3 << endl;

    // 使用 Lambda 表达式统计能被13整除的元素个数
    count13 = count_if(numbers.begin(), numbers.end(), [](int x) { return x % 13 == 0; });
    cout << "Count of numbers divisible by 13: " << count13 << endl;

    return 0;
}