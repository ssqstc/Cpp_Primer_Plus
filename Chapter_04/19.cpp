#include "iostream"
using namespace std;

struct antarctica_year_end
{
    int year;
};
int main()
{
    antarctica_year_end s01, s02, s03;      // 创建结构体变量
    s01.year = 1998;

    antarctica_year_end * pa = &s02;        // 将s02变量的地址赋值给指针pa
    pa->year = 1999;

    antarctica_year_end trio[3];        // 创建结构体数组
    trio[0].year = 2003;
    cout << trio->year << endl;     // 2003

    const antarctica_year_end *arp[3] = {&s01,&s02,&s03};       // 创建结构体指针数组
    cout << arp[1]->year << endl;       // 1999

    const antarctica_year_end **ppa = arp;      // 创建结构体指针的指针  *ppa == &s01
    cout << (*ppa)->year << endl;       // 1998

    auto ppb = arp;     // ppb是指向结构体的指针
    cout << (*(ppb + 1))->year;     // 1999 (*(ppb + 1)) == &s02
    return 0;
}