#ifndef HEAD_08_CHAPTER14_H
#define HEAD_08_CHAPTER14_H

#include <iostream>
using namespace std;

// 类模板定义，用于创建包含固定大小数组的类
template <class T, int n>
class ArrayTp {
private:
    T ar[n]; // 数组，包含 n 个类型为 T 的元素
public:
    T& operator[](int i); // 重载运算符[]，返回数组的非 const 引用
    T operator[](int i) const; // 重载运算符[]，返回数组的 const 值
};

// 重载运算符[]，实现数组元素的访问和修改
template <class T, int n>
T& ArrayTp<T, n>::operator[](int i) {
    return ar[i]; // 返回数组元素的引用，允许修改
}

// 重载运算符[]，实现数组元素的只读访问
template <class T, int n>
T ArrayTp<T, n>::operator[](int i) const {
    return ar[i]; // 返回数组元素的值，不能修改
}

#endif //HEAD_08_CHAPTER14_H