#include "08_head_Chapter14.h"

/*
 * 知识点总结：
 * 1. 类模板：`ArrayTp` 是一个类模板，支持创建包含固定大小数组的类实例。
 * 2. 运算符重载：`ArrayTp` 通过重载 `[]` 运算符，实现了对数组元素的访问。
 * 3. 模板的嵌套：使用类模板 `ArrayTp` 创建了二维数组 `twodee`，这表明模板类可以用于实现更复杂的数据结构。

 * 注意点：
 * 1. 数组边界：在访问数组元素时，确保索引在合法范围内，避免越界访问。
 * 2. 类型转换：计算平均值时，需要将整型转换为浮点型以避免整数除法带来的精度丢失。
 * 3. 模板实例化：模板类 `ArrayTp` 通过显式实例化指定了模板参数，在实例化时需要提供合适的类型和大小参数。
 */

int main() {
    ArrayTp<int, 10> sums; // 创建一个包含10个整型元素的数组对象 sums
    ArrayTp<double, 10> aves; // 创建一个包含10个双精度浮点型元素的数组对象 aves

    // 创建一个包含10个5维整型数组的二维数组对象 twodee
    ArrayTp<ArrayTp<int, 5>, 10> twodee;

    // 初始化 twodee 数组，并计算每行的和与平均值
    for (int i = 0; i < 10; ++i) {
        sums[i] = 0; // 初始化 sums 数组的元素为 0
        for (int j = 0; j < 5; ++j) {
            twodee[i][j] = (i + 1) * (j + 1); // 计算并存储 twodee 数组的元素
            sums[i] += twodee[i][j]; // 累加每行的元素值，存储到 sums 数组
        }
        aves[i] = (double)sums[i] / 10; // 计算平均值，注意类型转换以确保浮点除法
    }

    // 输出 twodee 数组的元素值，以及每行的和与平均值
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout.width(2); // 设置输出宽度为2
            cout << twodee[i][j] << ' '; // 输出 twodee 数组的元素
        }
        cout << ": sum = " << sums[i] << ", average = " << aves[i] << endl; // 输出和与平均值
    }

    return 0;
}