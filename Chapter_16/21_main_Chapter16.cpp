#include <iostream>
#include <valarray>
#include <cstdlib>
using namespace std;

typedef valarray<int> vInt; // 将 valarray<int> 简化为 vInt 类型
const int SIZE = 12; // 定义数组的大小为 12

void show(const vInt& v, int cols); // 函数声明，负责打印 valarray 的内容

int main() {
    vInt valint(SIZE); // 创建一个大小为 12 的 valarray
    for (int i = 0; i < SIZE; ++i) {
        valint[i] = rand() % 10; // 使用随机数填充 valarray
    }
    cout << "Original array: " << endl;
    show(valint, 3); // 打印原始数组内容，按 3 列显示

    cout << "Second column: " << endl;
    vInt vcol = (valint[slice(1, 4, 3)]); // 选取数组的第二列（1号索引，每隔3个元素取1个，共4个元素）
    show(vcol, 1); // 打印第二列内容，按 1 列显示

    return 0;
}

void show(const vInt& v, int cols) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i % cols == cols - 1) {
            cout << endl; // 打印列间隔
        } else {
            cout << ' ';
        }
    }
    if (v.size() % cols != 0) {
        cout << endl; // 当行数不满足整列时，强制换行
    }
}