#ifndef __TEST01_HEAD_CHAPTER09_H__
#define __TEST01_HEAD_CHAPTER09_H__

const int Len = 40; // 定义字符串长度
struct golf{ // 定义 golf 结构体
    char fullname[Len]; // 球员全名
    int handicap; // handicap 值
};

void setgolf(golf &g, const char *name, int hc); // 声明通过参数设置 golf 信息的函数

int setgolf(golf &g); // 声明通过用户输入设置 golf 信息的函数

void handicap(golf &g, int hc); // 声明设置 handicap 的函数

void showgolf(const golf &g); // 声明显示 golf 信息的函数

#endif //__TEST01_HEAD_CHAPTER09_H__