//class Stonewt{
//private:
//    enum {Lbs_per_stn = 14};
//    int stone;
//    double pounds;
//    double pds_left;
//public:
//    Stonewt operator*(double n) const{
//        Stonewt temp;
//        temp.stone = stone * n + pds_left * n / Lbs_per_stn;
//        temp.pds_left = int(pds_left * n) % Lbs_per_stn;
//        temp.pounds = pounds * n;
//        return temp;
//    }
//    friend Stonewt operator*(double n, const Stonewt &st){
//        return st * n;
//    }
//};

//成员函数是类的一部分,具备权限访问内部所有数据成员.
//友元函数是非成员函数,其访问权限与成员函数相同.

//对(前提类成员是private)

//同1

//至少有一个参数是用户自定义类型
//不能违反原运算符规则
//必须是有效的C++运算符,不能创建新的运算符

//只能通过成员函数重载

//class Vector{
//    double x, y, mag, ang;
//    ·····
//public:
//    operator double() const{
//        return mag;
//    }
//};