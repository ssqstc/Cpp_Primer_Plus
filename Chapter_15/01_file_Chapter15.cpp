#include "01_head_Chapter15.h"

// Tv 类的成员函数实现

// 增加音量，如果当前音量小于最大值则增加并返回 true，否则返回 false
bool Tv::volUp() {
    if (volume < MaxVol) {
        volume++;
        return true;
    } else {
        return false;
    }
}

// 降低音量，如果当前音量大于最小值则降低并返回 true，否则返回 false
bool Tv::volDown() {
    if (volume > MinVol) {
        volume--;
        return true;
    } else {
        return false;
    }
}

// 增加频道，如果当前频道小于最大频道则增加，否则回到最小频道
void Tv::chanUp() {
    if (channel < MaxChan) {
        channel++;
    } else {
        channel = MinChan;
    }
}

// 降低频道，如果当前频道大于最小频道则降低，否则回到最大频道
void Tv::chanDown() {
    if (channel > MinChan) {
        channel--;
    } else {
        channel = MaxChan;
    }
}

// 显示当前电视的所有设置，包括开关状态、音量、频道和输入模式
void Tv::showSettings() const {
    cout << "TV is " << (state == off ? "off" : "on") << endl;
    if (state == on) {
        cout << "Volume = " << volume << endl;
        cout << "Channel = " << channel << endl;
        cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
    }
}