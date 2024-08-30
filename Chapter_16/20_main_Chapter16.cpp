#include <iostream>
#include <vector>
#include <valarray>

using namespace std;

/*
 * 知识点总结:
 * 1. `vector` 是一个动态数组容器，适合在需要频繁添加或删除元素的情况下使用。
 * 2. `valarray` 是一种用于数值计算的数组类，支持数组间的算术运算，适用于需要高效进行数值运算的场景。
 * 3. `sort` 函数可以对容器中的元素进行排序，需要包含 `<algorithm>` 头文件。
 * 4. 循环控制结构（`while`）用于实现输入数据直到用户输入一个非正数。
 *
 * 注意点:
 * 1. 在使用 `cin` 输入数据时，需要检查输入是否符合预期，防止因输入错误导致的程序异常。
 * 2. `valarray` 中的数组运算是元素级别的，`numbers + 2.0` 表示将 `numbers` 中的每个元素都加上 2.0。
 */

int main() {
    double temp;
    vector<double> data;
    cout << "Enter numbers (<= 0 to quit) : " << endl;

    // 用户输入一组数字，直到输入<=0的数字时停止输入
    while (cin >> temp && temp > 0) {
        data.push_back(temp);  // 将输入的数字添加到 vector 中
    }

    sort(data.begin(), data.end());  // 对输入的数据进行排序
    int size = data.size();  // 获取数据的大小

    valarray<double> numbers(size);  // 创建一个 valarray，用于存储输入的数字
    for (int i = 0; i < size; ++i) {
        numbers[i] = data[i];  // 将 vector 中的数据赋值给 valarray
    }

    valarray<double> result(size);  // 创建另一个 valarray，用于存储计算结果
    result = numbers + 2.0;  // 将 numbers 中的每个元素都加上 2.0

    // 输出原始数据及其对应的计算结果
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << ": " << result[i] << endl;
    }

    return 0;
}