#include <iostream>
#include <vector>
#include <random>
using namespace std;

/*
 * 知识点总结：
 * 1. **随机数生成与算法库**：使用`random_device`生成真正的随机数种子，通过`mt19937`构造随机数引擎。`shuffle`函数用于随机打乱容器内的元素顺序。
 * 2. **STL容器**：使用`vector`存储数据，并进行数据的操作与处理，展示了动态数组的灵活性和方便性。
 * 3. **范围for循环**：使用范围for循环遍历`vector`中的元素。

 * 注意点：
 * 1. **随机性**：`random_device`提供真正的随机种子，配合`mt19937`伪随机数引擎，保证每次运行结果的随机性。
 * 2. **抽奖逻辑**：抽取元素时，确保从未被选中的元素中随机选择，并避免重复选中。
 */

vector<int> lotto(int x, int y) {
    random_device rd; // 随机数种子
    mt19937 g(rd()); // 随机数生成器

    vector<int> temp, result;
    for (int i = 1; i <= x; ++i) {
        temp.push_back(i); // 初始化1到x的数列
    }
    for (int i = 0; i < y; ++i) {
        shuffle(temp.begin(), temp.end(), g); // 随机打乱数组
        result.push_back(*temp.begin()); // 取打乱后第一个元素
    }
    return result; // 返回y个随机选择的数字
}

int main() {
    vector<int> winners;
    winners = lotto(51, 6); // 从1到51中随机选择6个数字
    for (auto x : winners) {
        cout << x << ' '; // 输出中奖号码
    }
    return 0;
}