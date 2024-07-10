#include "iostream"
using namespace std;

const int Max = 5;
void show_array(const double arr_begin[], const double arr_end[]);
void revalue(double r, double arr_begin[],const double arr_end[]);
double *fill_array(double arr_begin[], double arr_end[]);

int main(){
    double properties[Max];
    double *pa = fill_array(properties, properties + Max);     // 调用函数输入数据并获取返回值指针
    show_array(properties, pa);

    if (pa > properties){
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)){
            cin.clear();
            while (cin.get() != '\n'){
                continue;
            }
            cout << "Bad input: input process terminated." << endl;     // 错误提示信息
        }
        revalue(factor, properties, pa);
        show_array(properties, pa);
    }
    return 0;
}
double *fill_array(double arr_begin[], double arr_end[]){
    double temp;
    double *pt;
    for (pt = arr_begin; pt != arr_end; ++pt) {
        cout << "Enter value # " << pt - arr_begin + 1 << " : ";
        if (!(cin >> temp)){      // 判断cin是否捕获成功
            cin.clear();        // 清除错误信息
            while (cin.get() != '\n'){      // 清空缓存
                continue;
            }
            cout << "Bad input: input process terminated." << endl;     // 错误提示信息
            break;  // 退出最近的for循环
        } else if (temp < 0){       // 输入值小于0退出
            break;
        } else {
            *pt = temp;
        }
    }
    return pt;
}
void show_array(const double arr_begin[], const double arr_end[]){     // const 禁止修改数据
    for (const double *pt = arr_begin; pt != arr_end; ++pt) {
        cout << "Property #" << pt - arr_begin + 1 << ": $";
        cout << *pt << endl;
    }
}
void revalue(double r, double arr_begin[],const double arr_end[]){    // 根据比例系数修改数据
    double *temp;
    for (temp = arr_begin; temp != arr_end; ++temp) {
        *temp *= r;
    }
}