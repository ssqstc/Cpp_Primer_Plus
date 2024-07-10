#include "iostream"
using namespace std;
// 递归_2
const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int levels);

int main(){
    char ruler[Len];        // 定义个数组

    for (int i = 0; i < Len; ++i) {     // 将数组元素均设置为空格字符 数组初始内容是未定义的 其中每个元素可能包含随机的值 通常被称为“垃圾值”。
        ruler[i] = ' ';
    }

    int min = 0, max = Len - 2;     //（len - 1） 是'\0'的位置       （len - 2）是数组最后一个可显示字符
    ruler[Len -1] = '\0';           // 数组最后一个元素设置为'\0'字符
    ruler[min] = ruler[max] = '|';

    cout << ruler << endl;
    for (int i = 1; i <= Divs; ++i) {
        subdivide(ruler, min, max, i);     // 用循环调用函数
        cout << ruler << endl;
    }
    return 0;
}
void subdivide(char ar[], int low, int high, int levels){       // 定义函数 传入数组指针 最左边的元素下标 最右边的元素下标 循环分割次数
    if (0 == levels){
        return;
    }
    int mid = (low + high) / 2;     // 计算中间的元素下标
    ar[mid] = '|';

    subdivide(ar, low, mid, levels - 1);    // 递归左半边 每次调用初始循环次数减一
    subdivide(ar, mid, high, levels - 1);   // 递归右半边 每次调用初始循环次数减一
}