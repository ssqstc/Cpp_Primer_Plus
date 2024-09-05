//iostream文件定义了用于管理输入和输出的类、常量和操作符,这些对象管理用于处理I/Od流和缓冲区.该文件还创建类一些标准对象(cin、cout、cerr和clog以及对应的宽字符对象), 用于处理和每个程序相连的标准输入和输出流.

//键入的是字符,要将字符类型转换为int类型

//默认情况下,标准输出和标准错误都发送至显示设备,假如要求重定向到文件,标准输出将与文件相连,但标准错误仍与显示器相连.

//C++为每种基本类型都重载了operator<<()函数

//operator<<()的范围类型为ostream&

//#include <iostream>
//#include <iomanip>
//using namespace std;
//int main() {
//    int num;
//    cout << "Enter a number: ";
//    cin >> num;
//    cout << showbase;
//    cout << setw(15) << "dec: " << setw(15) << "hex: " << setw(15) << "oct: " << endl;
//    cout << dec << setw(15) << num << hex << setw(15) << num << oct << setw(15) << num << endl;
//    return 0;
//}

//#include <iostream>
//#include <iomanip>
//using namespace std;
//int main() {
//    string name;
//    double wages;
//    double worked;
//    cout << "Enter your name: ";
//    getline(cin, name);
//    cout << "Enter your hourly wages: ";
//    cin >> wages;
//    cout << "Enter number of hours worked: ";
//    cin >> worked;
//    cout << "First format: " << endl;
//    cout << showpoint << fixed;
//    cout << setw(30) << name << ": $" << setw(10) << setprecision(2) << wages << ": " << setw(5) << setprecision(1) << worked << endl;
//    cout << "Second format: " << endl;
//    cout << left << setw(30) << name << ": $" << setw(10) << setprecision(2) << wages << ": " << setprecision(1) << setw(5) << worked << endl;
//    return 0;
//}

//ct1 = 5; ct2 = 9

//while(cin.get() != '\n'); 一直读取直到遇到换行
//cin.ignore(80, '\n'); 忽略80个字符或者遇到换行符