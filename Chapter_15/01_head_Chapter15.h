#ifndef HEAD_01_CHAPTER15_H
#define HEAD_01_CHAPTER15_H

#include <iostream>
using namespace std;

// Tv 类表示电视机，包含状态、音量、频道和输入模式的设置
class Tv {
private:
    enum { off, on }; // 电视状态，off表示关闭，on表示开启
    enum { MinVol, MaxVol = 20 }; // 音量范围，最小0，最大20
    enum { MinChan = 1, MaxChan = 100 }; // 频道范围，最小1，最大100
    enum { TV, DVD }; // 输入模式，TV表示电视，DVD表示DVD
    int state; // 电视当前的开关状态
    int volume; // 当前音量
    int channel; // 当前频道
    int input; // 当前输入模式
public:
    // 构造函数，初始化电视状态、音量、频道和输入模式
    Tv(int s = off) : state(s), volume(5), channel(6), input(TV) {}

    // 打开或关闭电视
    void onOff() { state = (state == on) ? off : on; }

    // 增加音量，如果当前音量小于最大值则增加
    bool volUp();

    // 降低音量，如果当前音量大于最小值则降低
    bool volDown();

    // 增加频道，如果当前频道小于最大频道则增加，否则回到最小频道
    void chanUp();

    // 降低频道，如果当前频道大于最小频道则降低，否则回到最大频道
    void chanDown();

    // 切换输入模式，在TV和DVD之间切换
    void setInput() { input = (input == TV) ? DVD : TV; }

    // 显示当前电视的所有设置
    void showSettings() const;

    // 声明 Remote 为 Tv 的友元类，允许 Remote 访问 Tv 的私有成员
    friend class Remote;
};

// Remote 类表示遥控器，可以控制 Tv 类的操作
class Remote {
private:
    int mode; // 遥控器的模式
public:
    // 构造函数，初始化遥控器模式，默认为 TV 模式
    Remote(int m = Tv::TV) : mode(m) {}

    // 打开或关闭电视
    void onOff(Tv& tv) { tv.onOff(); }

    // 增加音量，返回是否成功
    bool volUp(Tv& tv) { return tv.volUp(); }

    // 降低音量，返回是否成功
    bool volDown(Tv& tv) { return tv.volDown(); }

    // 增加频道
    void chanUp(Tv& tv) { tv.chanUp(); }

    // 降低频道
    void chanDown(Tv& tv) { tv.chanDown(); }

    // 设置电视的频道
    void setChannel(Tv& tv, int n) { tv.channel = n; }

    // 切换输入模式
    void setInput(Tv& tv) { tv.setInput(); }
};

#endif //HEAD_01_CHAPTER15_H