#include "iostream"
using namespace std;

int golf_score(double *, int);
void golf_show(double *arr, int len);
void golf_avg(double *arr, int len);

int main(){
    double score[10];       // 定义高尔夫成绩数组
    int len = golf_score(score, 10);    // 返回数组实际长度

    if (len > 0){
        golf_show(score, len);      // 展示高尔夫成绩
        golf_avg(score, len);       // 计算成绩平均值
    } else {
        cout << "There is no scores!" << endl;
    }

    return 0;
}
int golf_score(double *arr, int len){       // 定义成绩录入函数并返回数组实际长度
    int count = 0;      // 实际录入次数计数
    double temp;        // 定义数据存储临时变量
    cout << "Enter ten of golf score:" << endl;
    while (count < len){
        cout << "Enter value #" << count + 1 << " :";
        cin >> temp;
        if (!cin){      // 检查输入流 cin 是否处于错误状态
            cin.clear();    // 清除输入流的错误标志
            while (cin.get() != '\n');   // 循环读取输入缓冲区中的字符，直到遇到换行符 \n 为止。
            cout << "Invalid input, terminate." << endl;    // 提示当前输入无效,退出循环
            break;
        } else if (temp < 0){       // 成绩小于0，退出循环
            break;
        } else {
            arr[count] = temp;      // 录入有效数据
            ++count;        // 计数加一
        }
    }
    return count;
}
void golf_show(double *arr, int len){       // 定义高尔夫成绩展示函数
    for (int i = 0; i < len; ++i) {
        cout << "#" << i + 1 << " score: " << arr[i] << endl;
    }
}
void golf_avg(double *arr, int len){        // 定义高尔夫成绩平均值计数函数
    double sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    cout << "golf average: " << sum / len << endl;
}