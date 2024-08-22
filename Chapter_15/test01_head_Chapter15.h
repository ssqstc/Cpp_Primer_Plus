#ifndef HEAD_TEST01_CHAPTER15_H
#define HEAD_TEST01_CHAPTER15_H

#include <iostream>  // 包含标准输入输出流库
using namespace std;

// 声明 Remote 类以供友元声明使用
class Remote;

// Tv 类定义
class Tv {
private:
    enum { off, on };  // 定义电视状态的枚举
    enum { MinVol, MaxVol = 20 };  // 定义音量的最小值和最大值
    enum { MinChan = 1, MaxChan = 100 };  // 定义频道的范围
    enum { TV, DVD };  // 定义输入模式
    int state;  // 当前状态（开/关）
    int volume;  // 当前音量
    int channel;  // 当前频道
    int input;  // 当前输入模式
    friend class Remote;  // 将 Remote 类声明为友元类，使其可以访问 Tv 的私有成员
public:
    Tv(int s = off) : state(s), volume(5), channel(6), input(TV) {}  // 构造函数，带有默认参数
    void onOff() { state = (state == on) ? off : on; }  // 切换电视的开/关状态
    bool volUp();  // 增加音量
    bool volDown();  // 减小音量
    void chanUp();  // 增加频道
    void chanDown();  // 减少频道
    void setInput() { input = (input == TV) ? DVD : TV; }  // 切换输入模式
    void showSettings() const;  // 显示当前电视设置
    bool setCondition(Remote& r);  // 设置遥控器模式
};

// Remote 类定义
class Remote {
private:
    enum { COMMON, INTERACTIVE };  // 定义遥控器模式
    int mode;  // 当前模式
    int condition;  // 遥控器当前状态
    friend class Tv;  // 将 Tv 类声明为友元类，使其可以访问 Remote 的私有成员
public:
    Remote(int m = Tv::TV, int c = COMMON) : mode(m), condition(c) {}  // 构造函数，带有默认参数
    void onOff(Tv& tv) { tv.onOff(); }  // 控制电视的开/关
    bool volUp(Tv& tv) { return tv.volUp(); }  // 控制电视的音量增加
    bool volDown(Tv& tv) { return tv.volDown(); }  // 控制电视的音量减小
    void chanUp(Tv& tv) { tv.chanUp(); }  // 控制电视的频道增加
    void chanDown(Tv& tv) { tv.chanDown(); }  // 控制电视的频道减小
    void setChannel(Tv& tv, int n) { tv.channel = n; }  // 设置电视的频道
    void setInput(Tv& tv) { tv.setInput(); }  // 切换电视的输入模式
    void showCondition() const;  // 显示遥控器的当前模式
    void setCondition() { condition = (condition == COMMON ? INTERACTIVE : COMMON); }  // 切换遥控器模式
};

#endif //HEAD_TEST01_CHAPTER15_H