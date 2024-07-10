#include "iostream"
using namespace std;
// 深入函数指针

const double *f1(const double ar[], int n);
const double *f2(const double ar[], int n);
const double *f3(const double ar[], int n);

int main(){
    double av[3] = {1112.3, 1542.6, 2227.9};

    // part1:
    // p1(p2): pointer to a function    定义一个函数指针
    const double *(*p1)(const double *, int) = f1;       // p1 是一个指向函数的指针 这个函数接受 const double * 和 int 类型的参数，并返回 const double *
    auto p2 = f2;       // auto关键字自动推断指针类型 指向f2
    cout << "PART1:--------------------------------------" << endl;
    cout << "Address \t: value" << endl;
    cout << (*p1)(av, 3) << " : " << *(*p1)(av, 3) << endl;     // !!! (*p1)(av,3) == f1(av,3)
    cout << p2(av, 3) << " : " << *p2(av, 3) << endl;       // p2(av, 3) == f2(av, 3)   p2是函数指针 （*p2)是函数 这两者等价

    // part2:
    // pa(pb) is an array of pointers
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};       // 定义一个pa数组 数组中每个元素都是函数指针 分别指向f1、f2、f3
    auto pb = pa;       // 使用 auto 自动推断 pb 的类型，使其指向函数指针数组 pa
    cout << "PART2:--------------------------------------" << endl;
    cout << "Address \t: value" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << pa[i](av, 3) << " : " << *pa[i](av, 3) << endl;  // 使用 pa[i] 调用对应的函数
    }
    for (int i = 0; i < 3; ++i) {
        cout << pb[i](av, 3) << " : " << *pb[i](av, 3) << endl;  // 使用 pb[i] 调用对应的函数
    }

    // part3:
    // pc(pd) is a pointer to an array of function pointers
    auto pc = &pa;      // pc 是指向 pa 数组的指针 是一个指向有三个函数指针作为元素的数组的指针
    const double *(*(*pd)[3])(const double *,int) = &pa;    // // pd 是一个指向包含 3 个函数指针的数组的指针
    cout << "PART3:--------------------------------------" << endl;
    cout << "Address \t: value" << endl;
    cout << (*pc)[0](av, 3) << " : " << *(*pc)[0](av, 3)  << endl;        // (*pc) == pa --> (*pc)[0](av, 3) == pa[0](av, 3)
    const double *pdb = (*pd)[1](av, 3);        // (*pd)[1](av, 3) == pa[1](av, 3) == f2(av, 3)
    cout << pdb << " : " << *pdb << endl;
//    cout << (*pd)[2](av, 3) << " : " << *(*pc)[2](av, 3) << endl;     // 直接使用函数指针调用函数。
    cout << (*(*pd)[2])(av, 3) << " : " << *(*(*pd)[2])(av, 3) << endl;     // 通过解引用函数指针调用函数
// !!!  (*pa[2])(av, 3) == f3(av, 3) == 第三个元素的地址
// !!!  *pa[2](av, 3) == *(f3(av, 3)) == 第三个元素的值
/*
 * !!!  pa是数组名，是数组第一个元素的地址，即&pa[0]，因此它是单个指针的地址。但&pa是整个数组(即N个地址块)的地址。
 * !!!  从数字上说，pa和&pa的值相同，但它们的类型不同。
 * !!!  差别一：pa+1为数组下一个元素的地址，而&pa+1为数组pa后面N个内存块的地址。
 * !!!  差别二：要得到第一个元素的值，只需要对pa解除一次引用，但需要对&pa解除两次引用。  **&pa == *pa == pa[0]
 */
    return 0;
}
const double *f1(const double *ar, int n){      // 定义f1函数 返回第一个元素地址 包含数组指针（指针表示法）及数组元素个数
    return ar;
}
const double *f2(const double ar[], int n){     // 定义f2函数 返回第二个元素地址 包含数组指针（数组表示法）及数组元素个数
    return ar + 1;
}
const double *f3(const double ar[], int n){     // 返回数组的第三个元素的地址
    return ar + 2;
}