#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 数组中的结构体初始化：
   - 可以在定义结构体数组时使用初始化列表对每个元素进行初始化。

2. 访问结构体数组元素：
   - 使用下标访问结构体数组中的元素。
   - 使用指针访问数组中的第一个元素时，`arr` 表示 `arr[0]`。

3. 结构体数组成员访问：
   - 通过`.`运算符访问结构体成员。

注意点：
- 当使用指针访问数组的第一个元素时，`arr` 相当于 `arr[0]`，可以使用`->`运算符访问成员。
- 使用下标访问数组时，`arr[i]` 表示数组中的第 `i` 个元素。
*/

struct CandyBar
{
    char brand[20];    // 品牌名称
    double weight;     // 重量
    int calories;      // 卡路里
};

int main()
{
    // 定义并初始化结构体数组
    CandyBar arr[3] {
            {"Mocha Munch 1", 1.3, 150},
            {"Mocha Munch 2", 2.3, 250},
            {"Mocha Munch 3", 3.3, 350}
    };

    // 输出结构体数组第一个元素的成员
    cout << "arr1 brand: " << arr->brand
         << " , arr1 weight: " << arr->weight
         << " , arr1 calories: " << arr->calories << endl;

    // 输出结构体数组第二个元素的成员
    cout << "arr2 brand: " << arr[1].brand
         << " , arr2 weight: " << arr[1].weight
         << " , arr2 calories: " << arr[1].calories << endl;

    // 输出结构体数组第三个元素的成员
    cout << "arr3 brand: " << arr[2].brand
         << " , arr3 weight: " << arr[2].weight
         << " , arr3 calories: " << arr[2].calories;

    return 0;  // 返回0表示程序正常结束
}
