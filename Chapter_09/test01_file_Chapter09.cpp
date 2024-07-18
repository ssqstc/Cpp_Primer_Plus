#include <iostream>
#include "test01_head_Chapter09.h"
#include <cstring>

using namespace std;

void setgolf(golf &g, const char *name, int hc){ // 通过参数设置 golf 信息
    strcpy(g.fullname, name); // 复制名字
    g.handicap = hc; // 设置 handicap
}

int setgolf(golf &g){ // 通过用户输入设置 golf 信息
    cout << "The fullname is: "; // 提示输入全名
    cin.getline(g.fullname, Len); // 读取全名
    if (strcmp(g.fullname, "") == 0){ // 判断全名是否为空
        return 0;
    } else{
        cout << "The handicap is: "; // 提示输入 handicap
        cin >> g.handicap; // 读取 handicap
        cin.get(); // 清除缓冲区
        return 1;
    }
}

void handicap(golf &g, int hc){ // 设置 handicap
    g.handicap = hc;
}

void showgolf(const golf &g){ // 显示 golf 信息
    cout << g.fullname << " handicap is " << g.handicap << endl;
}