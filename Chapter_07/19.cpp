#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 函数指针：指向函数的指针，允许通过指针调用函数。
 * 2. auto 关键字：自动推断变量类型。
 * 3. 数组和指针：函数指针数组和指向函数指针数组的指针。
 *
 * 注意点：
 * 1. 函数指针的定义和使用：确保函数指针的类型正确，并且函数调用正确。
 * 2. auto 关键字：了解 auto 推断类型的能力及其应用场景。
 * 3. 数组指针：指向函数指针数组的指针需要正确的定义和解引用方式。
 */

/*
 * !!!  (*pa[2])(av, 3) == f3(av, 3) == 第三个元素的地址
 * !!!  *pa[2](av, 3) == *(f3(av, 3)) == 第三个元素的值
 * !!!  pa是数组名，是数组第一个元素的地址，即&pa[0]，因此它是单个指针的地址。但&pa是整个数组(即N个地址块)的地址。
 * !!!  从数字上说，pa和&pa的值相同，但它们的类型不同。
 * !!!  差别一：pa+1为数组下一个元素的地址，而&pa+1为数组pa后面N个内存块的地址。
 * !!!  差别二：要得到第一个元素的值，只需要对pa解除一次引用，但需要对&pa解除两次引用。  **&pa == *pa == pa[0]
 */

const double *f1(const double ar[], int n);
const double *f2(const double ar[], int n);
const double *f3(const double ar[], int n);

int main() {
    double av[3] = {1112.3, 1542.6, 2227.9};

    // part1:
    // p1(p2): pointer to a function    定义一个函数指针
    const double *(*p1)(const double *, int) = f1;  // 定义一个指向 f1 的函数指针
    auto p2 = f2;  // 使用 auto 关键字推断 p2 类型
    cout << "PART1:--------------------------------------" << endl;
    cout << "Address \t: value" << endl;
    cout << (*p1)(av, 3) << " : " << *(*p1)(av, 3) << endl;  // 使用函数指针调用函数
    cout << p2(av, 3) << " : " << *p2(av, 3) << endl;  // 使用 auto 类型的函数指针调用函数

    // part2:
    // pa(pb) is an array of pointers
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};  // 定义一个函数指针数组
    auto pb = pa;  // 使用 auto 关键字推断 pb 类型
    cout << "PART2:--------------------------------------" << endl;
    cout << "Address \t: value" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << pa[i](av, 3) << " : " << *pa[i](av, 3) << endl;  // 使用函数指针数组调用函数
    }
    for (int i = 0; i < 3; ++i) {
        cout << pb[i](av, 3) << " : " << *pb[i](av, 3) << endl;  // 使用 auto 类型的函数指针数组调用函数
    }

    // part3:
    // pc(pd) is a pointer to an array of function pointers
    auto pc = &pa;  // 定义一个指向函数指针数组的指针
    const double *(*(*pd)[3])(const double *, int) = &pa;  // 定义一个指向函数指针数组的指针
    cout << "PART3:--------------------------------------" << endl;
    cout << "Address \t: value" << endl;
    cout << (*pc)[0](av, 3) << " : " << *(*pc)[0](av, 3) << endl;  // 使用指向函数指针数组的指针调用函数
    const double *pdb = (*pd)[1](av, 3);  // 使用指向函数指针数组的指针调用函数
    cout << pdb << " : " << *pdb << endl;
    cout << (*(*pd)[2])(av, 3) << " : " << *(*(*pd)[2])(av, 3) << endl;  // 使用指向函数指针数组的指针调用函数

    return 0;
}

const double *f1(const double *ar, int n) {  // 返回第一个元素的地址
    return ar;
}
const double *f2(const double ar[], int n) {  // 返回第二个元素的地址
    return ar + 1;
}
const double *f3(const double ar[], int n) {  // 返回第三个元素的地址
    return ar + 2;
}
