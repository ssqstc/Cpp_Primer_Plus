#include "iostream"     // IO输出流    ostream->cout(输出流自带cout对象）   istream->cin（输入流自带cin对象）
#include "fstream"      // 文件流      ofstream    ifstream
using namespace std;

/*
 * 知识点总结：
 * - 文件操作：使用 `ofstream` 类进行文件输出操作。
 * - 格式化输出：通过 `fixed`，`precision` 和 `setf` 控制输出格式。
 * - 输入操作：使用 `cin.getline` 获取一整行输入。
 *
 * 注意点：
 * - 确保文件能够正确打开和关闭。
 * - 使用 `fixed` 和 `precision` 控制浮点数的输出格式。
 * - 保证输入输出操作的正确顺序。
 */

int main()
{
    char automobile[50]; // 存储汽车的品牌和型号
    int year; // 存储汽车的年份
    double a_price, b_price; // 存储汽车的原价和折后价

    ofstream outFile; // 定义文件输出流对象
    outFile.open("carinfo.txt"); // 打开文件用于输出

    cout << "Enter the make and model of automobile: "; // 提示输入汽车的品牌和型号
    cin.getline(automobile, 50); // 获取输入的品牌和型号
    cout << "Enter the model year: "; // 提示输入汽车的年份
    cin >> year; // 获取输入的年份
    cout << "Enter the original asking price: "; // 提示输入汽车的原价
    cin >> a_price; // 获取输入的原价
    b_price = a_price * 0.913; // 计算折后价

    cout << fixed; // 设置浮点数的输出格式为定点格式
    cout.precision(2); // 设置浮点数输出的精度为小数点后两位
    cout.setf(ios_base::showpoint); // 强制显示小数点
    cout << "Make and model: " << automobile << endl; // 输出品牌和型号
    cout << "Year: " << year << endl; // 输出年份
    cout << "Was asking: " << a_price << endl; // 输出原价
    cout << "Now asking: " << b_price << endl; // 输出折后价

    outFile << fixed; // 设置文件输出的浮点数格式为定点格式
    outFile.precision(2); // 设置文件输出的浮点数精度为小数点后两位
    outFile.setf(ios_base::showpoint); // 强制文件输出小数点
    outFile << "Make and model: " << automobile << endl; // 将品牌和型号写入文件
    outFile << "Year: " << year << endl; // 将年份写入文件
    outFile << "Was asking: " << a_price << endl; // 将原价写入文件
    outFile << "Now asking: " << b_price << endl; // 将折后价写入文件

    outFile.close(); // 关闭文件
    return 0; // 返回0表示程序成功执行
}
