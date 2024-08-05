//未将str指针初始化,应使用new[]或者nullptr来初始化它.
//没有创建新的字符串,只是复制来原油字符串的地址应使用new[]和strcpy().
//复制来字符串,但没有分配存储空间,应使用new char[len + 1]来分配适量的内存.

//如果在构造函数中使用new初始化指针成员,则应在析构函数中使用delete
//如果析构函数对指针类成员使用delete来释放内存,则构造函数应使用new来初始化指针,或将它设置为空指针.
//在构造函数中使用new来分配内存时,必须在相应的析构函数中使用delete来释放内存,且使用new[]分配内存时,与之相对应使用delete[]来释放内存.
//应定义一个分配内存(而不是将指针指向已有内存)的复制构造函数,这样程序能将类对象初始化为另一个类对象.
//应定义一个重载赋值运算符的类成员函数,进行深度赋值,使之复制数据,而不是指针.

//默认构造函数 初始化成员对象
//默认析构函数 对象生命周期结束后自动运行
//复制构造函数 将一个对象复制到新建对象中
//赋值运算符 为成员对象进行赋值
//地址运算符 返回调用对象的地址(即this指针的值)

//#include "iostream"
//class nifty {
//private:
//    char *m_personality;
//    int m_talents;
//public:
//    nifty();
//    nifty(const char *a_s);
//    ~nifty() { delete m_personality; }
//    friend std::ostream &operator<<(std::ostream &a_os, const nifty &a_n);
//};
//nifty::nifty() {
//    m_personality = nullptr;
//    m_talents = 0;
//}
//nifty::nifty(const char *a_s) {
//    m_personality = new char [strlen(a_s) + 1];
//    strcpy(m_personality, a_s);
//    m_talents = 0;
//}
//std::ostream &operator<<(std::ostream &a_os, const nifty &a_n) {
//    a_os << a_n.m_personality << ", " << a_n.m_talents;
//    return a_os;
//}

//Golfer nancy;   Golfer();
//Golfer lulu("Little Lulu"); Golfer(const char *name, int g = 0);
//Golfer roy("Roy Hobbs", 12);    Golfer(const char *name, int g = 0);
//Golfer *par = new Golfer;   Golfer();
//Golfer next = lulu; Golfer(const Golfer &g);
//Golfer hazzard = "Weed Thwacker";   Golfer(const char *name, int g = 0);
//*par = nancy;   调用默认赋值运算符
//nancy = "Nancy Putter"; Golfer(const char *name, int g = 0); 调用默认赋值运算符
//
//注意,对于语句5和6,有些编译器还将调用默认的赋值运算符.
//类应定义一个复制数据(而不是地址)的赋值运算符.