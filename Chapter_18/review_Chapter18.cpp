//double x { 8.8 };
//string s { "What a bracing effect!" };
//int k { 99 };
//Z200 zip { 200, 'Z', 0675 };
//vector<int> ai { 3, 9, 4, 7, 1 };

//const double& rx = w;
//const double& rx = w + 1; 指向w + 1临时拷贝的副本
//指向 up(w)返回值的临时变量
//double& rx = w;
//左值引用不能指向右值
//左值引用不能指向右值
//左值不能传递给右值引用
//double&& rx = w + 1;
//指向 up(w)的临时返回值

//double & rx
//const double & rx
//const double & rx
//
//double & rx
//double && rx
//double && rx
//
//const double & rx
//double && rx
//double && rx

//默认构造函数、复制构造函数、赋值构造函数、析构函数、移动构造函数、移动赋值函数
//未显示申明会自动创建

//标准数组没有所有权转让机制
//使用动态内存分配以适配移动构造函数

//#include <iostream>
//template<typename T>
//void show2(double x, T fp) { std::cout << x << " -> " << fp(x) << '\n'; }
//int main() {
//    show2(18.0, [](double x) { return 1.8 * x + 32; });
//    return 0;
//}

//#include <iostream>
//#include <array>
//const int Size = 5;
//template<typename T>
//void sum(std::array<double, Size> a, T fp);
//int main() {
//    double total = 0.0;
//    std::array<double, Size> temp_c = { 32.1, 34.3, 37.8, 35.2, 34.7 };
//    sum(temp_c, [&total](double x) { total += x; });
//    std::cout << "total: " << total << '\n';
//    return 0;
//}
//template<typename T>
//void sum(std::array<double, Size> a, T fp) {
//    for (auto pt = a.begin(); pt != a.end(); ++pt) {
//        fp(*pt);
//    }
//}