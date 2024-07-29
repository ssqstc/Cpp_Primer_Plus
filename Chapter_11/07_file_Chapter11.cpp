#include "07_head_Chapter11.h"

// 构造函数实现，将磅数转换为英石和剩余的磅数
Stonewt::Stonewt(double lbs) {
    stone = (int)lbs / Lbs_per_stn;
    pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;
    pounds = lbs;
}

// 构造函数实现，接受英石和磅数
Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

// 默认构造函数，将所有成员初始化为0
Stonewt::Stonewt() {
    stone = pds_left = pounds = 0;
}

// 以英石为单位显示重量
void Stonewt::show_stn() const {
    cout << stone << " stone, " << pds_left << " pounds." << endl;
}

// 以磅为单位显示重量
void Stonewt::show_lbs() const {
    cout << pounds << " pounds." << endl;
}

// 将 Stonewt 对象转换为 int 类型，四舍五入
Stonewt::operator int() const {
    return (int)(pounds + 0.5);
}

// 将 Stonewt 对象转换为 double 类型，返回总磅数
Stonewt::operator double() const {
    return pounds;
}
