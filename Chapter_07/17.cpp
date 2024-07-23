#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 递归：函数 `subdivide` 通过递归调用自身来实现标尺的细分。
 * 2. 数组操作：操作字符数组 `ruler` 实现可视化的标尺细分效果。
 * 3. 中点计算：计算区间的中点 `mid` 来确定细分的位置。

 * 注意点：
 * 1. 递归终止条件：确保递归有明确的终止条件（这里是 `levels == 0`）。
 * 2. 数组边界：注意数组索引的边界条件，避免越界访问。
 * 3. 字符数组初始化：在使用数组前应确保其已初始化，避免未定义行为。
 */

const int Len = 66;    // 标尺长度
const int Divs = 6;    // 细分层数
void subdivide(char ar[], int low, int high, int levels);

int main() {
    char ruler[Len];    // 定义字符数组作为标尺

    for (int i = 0; i < Len; ++i) {  // 初始化数组为空格字符
        ruler[i] = ' ';
    }

    int min = 0, max = Len - 2;    // 初始化标尺的最小和最大索引
    ruler[Len - 1] = '\0';         // 将最后一个字符设为字符串终止符
    ruler[min] = ruler[max] = '|'; // 标尺两端设为 '|'

    cout << ruler << endl;  // 输出初始标尺
    for (int i = 1; i <= Divs; ++i) {
        subdivide(ruler, min, max, i);   // 调用细分函数
        cout << ruler << endl;           // 输出细分后的标尺
    }
    return 0;
}

void subdivide(char ar[], int low, int high, int levels) {
    if (0 == levels) {  // 递归终止条件
        return;
    }
    int mid = (low + high) / 2;  // 计算中点索引
    ar[mid] = '|';               // 在中点处放置 '|'

    subdivide(ar, low, mid, levels - 1);  // 递归细分左半部分
    subdivide(ar, mid, high, levels - 1); // 递归细分右半部分
}
