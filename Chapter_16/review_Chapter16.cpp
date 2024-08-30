//class RQ1 {
//private:
//    string st;
//public:
//    RQ1() : st("") {}
//    RQ1(const char* s) : st(s) {}
//    ~RQ1() {}
//};
//不再需要显式复制构造函数、析构程序和赋值运算符，因为string 对象提供 了自己的内存管理功能

//string对象有自己的内存管理功能,会自动调节大小
//可直接进行字符串拼接
//可以将一个string对象赋值给另一个

//void toUpper(string& s) {
//    transform(s.begin(), s.end(), s.begin(), toupper);
//}

//auto_ptr<int> pia(new int[20]); auto_ptr不使用delete[]
//auto_ptr<string>(new string); 未命名
//int rigue = 7;
//auto_ptr<int> pr(&rigue); 只能指向new开辟的内存空间
//auto_ptr dbl (new double); 未指定智能指针模版实例化类型

//先进后出原则

//set键值唯一且键唯一

//迭代器是一种泛型

//使用继承可以提高通用性

//可以相互拷贝、赋值
//可以自动管理内存,调整长度

//list无法做到随机访问

//创建匿名函数对象
//flase