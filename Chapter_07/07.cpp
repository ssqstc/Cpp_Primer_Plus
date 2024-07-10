#include "iostream"
using namespace std;

const int Max = 5;
void show_array(const double arr[], int n);
void revalue(double r, double arr[], int n);
int fill_array(double arr[], int Max);

int main(){
    double properties[Max];

    int size = fill_array(properties, Max);     // 调用函数输入数据
    show_array(properties, size);
    if (size > 0){      // 如果size大于0 输入评估系数
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)){
            cin.clear();
            while (cin.get() != '\n'){
                continue;
            }
            cout << "Bad input: input process terminated." << endl;     // 错误提示信息
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    return 0;
}
int fill_array(double arr[], int Max){
    double temp;
    int i;
    for (i = 0; i < Max; ++i) {
        cout << "Enter value # " << i + 1 << " : ";
        if (!(cin >> temp)){      // 判断cin是否捕获成功
            cin.clear();        // 清除错误信息
            while (cin.get() != '\n'){      // 清空缓存
                continue;
            }
            cout << "Bad input: input process terminated." << endl;     // 错误提示信息
            break;  // 退出最近的for循环
        } else if (temp < 0){       // 输入值小于0退出
            break;
        } else
            arr[i] = temp;
    }
    return i;
}
void show_array(const double arr[], int n){     // const 禁止修改数据
    for (int i = 0; i < n; ++i) {
        cout << "Property # " << i + 1 << " :$ ";       // 遍历数据
        cout << arr[i] << endl;
    }
}
void revalue(double r, double arr[], int n){    // 根据比例系数修改数据
    for (int i = 0; i < n; ++i) {
        arr[i] *= r;
    }
}