#include "test01_head_Chapter15.h"

// Tv 类成员函数的实现

bool Tv::volUp() {
    if (volume < MaxVol) {  // 如果音量小于最大值
        volume++;  // 增加音量
        return true;  // 返回 true 表示成功
    } else {
        return false;  // 返回 false 表示无法增加音量
    }
}

bool Tv::volDown() {
    if (volume > MinVol) {  // 如果音量大于最小值
        volume--;  // 减小音量
        return true;  // 返回 true 表示成功
    } else {
        return false;  // 返回 false 表示无法减小音量
    }
}

void Tv::chanUp() {
    if (channel < MaxChan) {  // 如果频道小于最大值
        channel++;  // 增加频道
    } else {
        channel = MinChan;  // 否则将频道设置为最小值
    }
}

void Tv::chanDown() {
    if (channel > MinChan) {  // 如果频道大于最小值
        channel--;  // 减少频道
    } else {
        channel = MaxChan;  // 否则将频道设置为最大值
    }
}

void Tv::showSettings() const {
    cout << "TV is " << (state == off ? "off" : "on") << endl;  // 显示电视的开/关状态
    if (state == on) {  // 如果电视处于开机状态
        cout << "Volume = " << volume << endl;  // 显示音量
        cout << "Channel = " << channel << endl;  // 显示频道
        cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;  // 显示输入模式
    }
}

bool Tv::setCondition(Remote& r) {
    if (state == on) {  // 如果电视处于开机状态
        r.setCondition();  // 切换遥控器模式
        return true;  // 返回 true 表示成功
    }
    return false;  // 返回 false 表示无法切换
}

void Remote::showCondition() const {
    cout << "Condition = " << (condition == COMMON ? "COMMON" : "INTERACTIVE") << endl;  // 显示遥控器的当前模式
}