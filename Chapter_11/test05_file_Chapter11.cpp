#include "test05_head_Chapter11.h"

Stonewt::Stonewt(double lbs) {
    stone = (int)lbs / Lbs_per_stn;  // 将磅转换为英石
    pds_left = (int)lbs % Lbs_per_stn + lbs - (int)lbs;  // 计算剩余的磅
    pounds = lbs;  // 记录总磅数
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;  // 初始化英石数
    pds_left = lbs;  // 初始化剩余磅数
    pounds = stn * Lbs_per_stn + lbs;  // 计算总磅数
}

Stonewt::Stonewt() {
    stone = pds_left = pounds = 0;  // 默认构造函数初始化为0
}

void Stonewt::set_type(Stonewt::Type m) {
    type = m;  // 设置重量显示类型
}

Stonewt Stonewt::operator+(const Stonewt &st) const {
    return Stonewt(pounds + st.pounds);  // 返回重量和的新对象
}

Stonewt Stonewt::operator-(const Stonewt &st) const {
    return Stonewt(pounds - st.pounds);  // 返回重量差的新对象
}

Stonewt Stonewt::operator*(double n) const {
    return Stonewt(pounds * n);  // 返回乘以n后的新对象
}

ostream &operator<<(ostream &os, const Stonewt &st) {
    if (st.type == Stonewt::STONE) {
        os << st.stone << " stone, " << st.pds_left << " pounds\n";  // 以英石和磅输出
    } else if (st.type == Stonewt::POUNDS) {
        os << int(st.pounds) << " pounds\n";  // 以整数磅输出
    } else if (st.type == Stonewt::FLOAT_POUNDS) {
        os << st.pounds << " pounds\n";  // 以浮动磅输出
    } else {
        os << "Invalid type.\n";  // 无效类型处理
    }
    return os;
}