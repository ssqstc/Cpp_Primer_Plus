#include "iostream"
#include "fstream"
#include "cstdlib"
using namespace std;

const int LIMIT = 5; // 定义目镜数组的大小
void file_it(ostream &os, double fo, const double fe[], int n);

int main(){
    fstream fout;
    const char *fn = "ep-data.txt";
    fout.open(fn); // 打开文件以进行输出

    if (!fout.is_open()){ // 检查文件是否成功打开
        cout << "Can't open " << fn << ". Bye." << endl;
        exit(EXIT_FAILURE); // 失败则退出程序
    }

    double objective;
    cout << "Enter the focal length of your telescope objective in mm: "; // 输入物镜的焦距（毫米为单位）
    cin >> objective;

    double eps[LIMIT]; // 定义目镜数组
    for (int i = 0; i < LIMIT; ++i) {
        cout << "EyePiece #" << i + 1 << ": ";
        cin >> eps[i]; // 输入每个目镜的焦距
    }

    file_it(cout, objective, eps, LIMIT); // 将数据输出到控制台
    file_it(fout, objective, eps, LIMIT); // 将数据输出到文件

    cout << "Done." << endl;
    return 0;
}

// 该函数输出物镜焦距和目镜信息到指定的输出流中
void file_it(ostream &os, double fo, const double fe[], int n){
    os << "Focal length of objective: " << fo << endl;
    os << "f.1. eyepieces magnification " << endl;
    for (int i = 0; i < n; ++i) {
        os << "\t\t" << fe[i] << "\t\t\t" << int(fo / fe[i] + 0.5) << endl;
    }
}
