#include "iostream"
using namespace std;
// 函数指针
void estimate(int lines, double (*pf)(int));        // 声明estimate函数原型
double Rick(int lines);     // 声明Rick的函数原型
double Jack(int lines);     // 声明Jack的函数原型

int main(){
    int code;

    cout << "How many lines of code do you need? ";     // 你需要多少行代码
    cin >> code;
    cout << "Here is Rick's estimate: " << endl;        // 这是Rick的估计
    estimate(code, Rick);

    cout << "Here is Jack's estimate: " << endl;        // 这是Jack的估计
    estimate(code, Jack);

    return 0;
}

double Rick(int lines){     // 定义Rick函数 根据行数计算所需的时间
    return lines * 0.05;
}
double Jack(int lines){     // 定义Jack函数 根据行数计算所需的时间
    return 0.03 * lines + 0.0004 * lines * lines;
}
void estimate(int lines, double (*pf)(int)){        // 定义estimate函数 接收行数和一个函数指针作为参数
    cout << lines << " lines code will take " << (*pf)(lines) << " hours." << endl;
}