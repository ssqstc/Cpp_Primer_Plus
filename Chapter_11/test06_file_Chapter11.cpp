#include "test06_head_Chapter11.h"

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

bool Stonewt::operator==(const Stonewt &st) const {
    return pounds == st.pounds;  // 判断重量是否相等
}
bool Stonewt::operator>(const Stonewt &st) const {
    return pounds > st.pounds;  // 判断重量是否大于
}
bool Stonewt::operator<(const Stonewt &st) const {
    return pounds < st.pounds;  // 判断重量是否小于
}
bool Stonewt::operator<=(const Stonewt &st) const {
    return pounds <= st.pounds;  // 判断重量是否小于等于
}
bool Stonewt::operator>=(const Stonewt &st) const {
    return pounds >= st.pounds;  // 判断重量是否大于等于
}
bool Stonewt::operator!=(const Stonewt &st) const {
    return pounds != st.pounds;  // 判断重量是否不等
}

ostream &operator<<(ostream &os, const Stonewt &st) {
    os << st.pounds << " pounds";  // 输出总磅数
    return os;
}