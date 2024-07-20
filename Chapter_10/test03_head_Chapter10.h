#ifndef __TEST03_HEAD_CHAPTER10_H__
#define __TEST03_HEAD_CHAPTER10_H__
#include <iostream>
using namespace std;

/*
 * Golf 类定义
 * 模拟高尔夫球员的姓名和差点信息
 */
class Golf{
private:
    static const int LEN = 40; // 姓名长度限制
    struct golf{
        char fullname[LEN]; // 姓名
        int handicap; // 差点
    };
    golf info{}; // golf 结构体实例
public:
    Golf(); // 默认构造函数
    Golf(const char *name, int hc); // 带参数的构造函数
    void handicap(int hc); // 设置差点
    void showgolf() const; // 显示姓名和差点
};

#endif //__TEST03_HEAD_CHAPTER10_H__