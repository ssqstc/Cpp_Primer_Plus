#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 数组操作：通过指针操作数组。
 * 2. 输入处理：使用 cin 进行输入，包含错误处理。
 * 3. 函数传递：将数组和长度传递给函数进行处理。
 *
 * 注意点：
 * 1. 输入有效性：确保输入为有效的数字，负数或非数字输入将终止输入过程。
 * 2. 输入长度：最多输入 10 个高尔夫成绩，但可以提前终止输入。
 * 3. 显示和计算：分别显示和计算高尔夫成绩和平均值。
 */

int golf_score(double *, int);
void golf_show(double *arr, int len);
void golf_avg(double *arr, int len);

int main(){
    double score[10];     // 存储高尔夫成绩的数组
    int len = golf_score(score, 10);    // 获取输入的高尔夫成绩的数量

    if (len > 0){
        golf_show(score, len);     // 显示高尔夫成绩
        golf_avg(score, len);      // 计算并显示平均值
    } else {
        cout << "There is no scores!" << endl;  // 如果没有有效的输入，输出提示信息
    }

    return 0;
}

int golf_score(double *arr, int len){       // 读取高尔夫成绩的函数
    int count = 0;     // 记录有效成绩的数量
    double temp;       // 临时变量用于存储输入值
    cout << "Enter ten golf scores:" << endl;  // 提示用户输入高尔夫成绩
    while (count < len){
        cout << "Enter value #" << count + 1 << " :";  // 提示输入成绩编号
        cin >> temp;
        if (!cin){      // 检查输入是否为有效数字
            cin.clear();   // 清除错误状态
            while (cin.get() != '\n');  // 清空输入缓冲区
            cout << "Invalid input, terminate." << endl;   // 输出错误提示信息
            break;
        } else if (temp < 0){      // 检查输入是否为负数，负数终止输入
            break;
        } else {
            arr[count] = temp;      // 将有效成绩存储到数组中
            ++count;        // 增加有效成绩的数量
        }
    }
    return count;  // 返回有效成绩的数量
}

void golf_show(double *arr, int len){       // 显示高尔夫成绩的函数
    for (int i = 0; i < len; ++i) {
        cout << "#" << i + 1 << " score: " << arr[i] << endl;  // 输出每个成绩
    }
}

void golf_avg(double *arr, int len){        // 计算并显示平均成绩的函数
    double sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];  // 计算成绩总和
    }
    cout << "Golf average: " << sum / len << endl;  // 输出平均成绩
}
