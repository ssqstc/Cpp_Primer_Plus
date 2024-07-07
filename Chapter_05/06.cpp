#include "iostream"
using namespace std;

/*
 * 1.   *++pt
 * 2.   ++*pt
 * 3.   (*pt)++
 * 4.   *pt++
 */
int main()
{
    double arr[5] = {21.1,32.8,23.4,45.2,37.4};
    double *pt = arr;

//    cout << *pt << endl;    // 21.1

    cout << "*++pt = " << *++pt << endl;    // 32.8 前缀递增、递减和取值运算符优先级相同，按从右至左的顺序。
    cout << "++*pt = " << ++*pt << endl;    // 33.8 当前pt指针指向[1]下标元素即32.8，按从右至左的顺序，先取值再自加一。
    cout << "(*pt)++ = " << (*pt)++ << endl;    // 33.8 圆括号优先级高，先提取[1]下标元素，此时值为33.8，再赋值给cout输出，最后自加一，值为34.8.
    cout << "*pt = " << *pt << endl;    // 34.8
    cout << "*pt++ = " << *pt++ << endl;    // 34.8 后缀递增运算符 ++ 的优先级高于解引用运算符 *。因此后缀递增运算符 pt++ 会返回 pt 的当前值，然后将 pt 增加 1。
    cout << "*pt = " << *pt << endl;    // 23.4

    return 0;
}