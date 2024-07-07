#include "iostream"     // IO输出流    ostream->cout(输出流自带cout对象）   istream->cin（输入流自带cin对象）
#include "fstream"      // 文件流      ofstream    ifstream
using namespace std;

// 写入文本文件
int main()
{
    char automobile[50];
    int year;
    double a_price, b_price;

    ofstream outFile;   // 1.create object of output file stream(ofstream)  创建一个ofstream对象
    outFile.open("carinfo.txt");    // associate with a ffile 关联一个文件

    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    b_price = a_price * 0.913;

    cout << fixed;      // 用小数点的方式显示
    cout.precision(2);      // 显示小数点后两位精度
    cout.setf(ios_base::showpoint);     // 强制显示小数点后内容
    cout << "Make and model: " << automobile  << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking: " << a_price << endl;
    cout << "Now asking: " << b_price << endl;

    outFile << fixed;      // 用小数点的方式显示
    outFile.precision(2);      // 显示小数点后两位精度
    outFile.setf(ios_base::showpoint);     // 强制显示小数点后内容
    outFile << "Make and model: " << automobile  << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking: " << a_price << endl;
    outFile << "Now asking: " << b_price << endl;

    outFile.close();    // 关闭打开文件
    return 0;
}