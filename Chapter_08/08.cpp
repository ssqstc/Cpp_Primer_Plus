#include "iostream"
#include "fstream"
#include "cstdlib"
using namespace std;

/*
 * 知识点：
 * 1. 文件操作：使用 `fstream` 进行文件读写操作。
 * 2. 标准库函数：使用 `exit(EXIT_FAILURE)` 终止程序。
 * 3. 传引用：通过引用传递 `ostream` 对象。
 *
 * 注意点：
 * 1. 文件操作：在使用文件前需检查文件是否成功打开，避免文件操作错误。
 * 2. 浮点数运算：在浮点数运算中使用 `int` 类型转换和四舍五入。
 * 3. 输入输出：使用 `cin` 和 `cout` 获取和显示数据，并确保数据类型匹配。
 */

const int LIMIT = 5; // 常量定义

// 函数声明，打印望远镜数据到输出流
void file_it(ostream &os, double fo, const double fe[], int n);

int main(){
    fstream fout;
    const char *fn = "ep-data.txt"; // 文件名定义
    fout.open(fn); // 打开文件

    if (!fout.is_open()){ // 检查文件是否成功打开
        cout << "Can't open " << fn << ". Bye." << endl;
        exit(EXIT_FAILURE); // 终止程序
    }

    double objective;
    cout << "Enter the focal length of your telescope objective in mm: "; // 获取望远镜焦距
    cin >> objective;

    double eps[LIMIT]; // 存储目镜焦距的数组
    for (int i = 0; i < LIMIT; ++i) {
        cout << "EyePiece #" << i + 1 << ": ";
        cin >> eps[i]; // 获取每个目镜的焦距
    }

    file_it(cout, objective, eps, LIMIT); // 打印到控制台
    file_it(fout, objective, eps, LIMIT); // 打印到文件

    cout << "Done." << endl;
    return 0;
}

// 函数定义，打印望远镜数据
void file_it(ostream &os, double fo, const double fe[], int n){
    os << "Focal length of objective: " << fo << endl;
    os << "f.1. eyepieces magnification " << endl;
    for (int i = 0; i < n; ++i) {
        os << "\t\t" << fe[i] << "\t\t\t" << int(fo / fe[i] + 0.5) << endl; // 四舍五入计算放大倍数
    }
}
