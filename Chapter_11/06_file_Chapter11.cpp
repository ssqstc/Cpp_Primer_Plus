#include "06_head_Chapter11.h"

Stonewt::Stonewt(double lbs) {
    stone = (int)lbs / Lbs_per_stn; // 将磅数转换为英石部分
    pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs; // 计算英石后剩余的磅数
    pounds = lbs; // 总磅数
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn; // 英石部分
    pds_left = lbs; // 磅部分
    pounds = stn * Lbs_per_stn + lbs; // 总磅数
}

Stonewt::Stonewt() {
    stone = pds_left = pounds = 0; // 默认构造函数，初始化为0
}

void Stonewt::show_stn() const {
    cout << stone << " stone, " << pds_left << " pounds." << endl; // 以英石为单位显示重量
}

void Stonewt::show_lbs() const {
    cout << pounds << " pounds." << endl; // 以磅为单位显示重量
}
