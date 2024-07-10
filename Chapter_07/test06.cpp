#include "iostream"
using namespace std;

int Fill_array(double arr[], int len);   // 函数声明：填充数组
void Show_array(double arr[], int len);  // 函数声明：显示数组
void Reverse_array(double arr[], int len);   // 函数声明：反转数组
const int MAX = 40;     // 定义输入最大值

int main(){
    double arr[MAX];    // 定义一个double数组
    int count;

    count = Fill_array(arr,MAX);    // 调用函数填充数组
    Show_array(arr, count);     // 调用函数展示数组

    Reverse_array(arr,count);       // 反转数组所有元素
    Show_array(arr, count);     // 再次展示数组

    Reverse_array(arr + 1, count - 2);      // 反转数组除首位和末位的所有元素  ！！！数组长度为什么减二？因为去掉了首位和末尾两个元素
    Show_array(arr, count);                 // 最后展示数组

    return 0;
}
int Fill_array(double arr[], int len){       // 定义数组填充函数
    double num;
    int count = 0;
    cout << "Enter double number: ";
    while (count < len && cin >> arr[count]){
        if (!cin){          // 如果cin进入错误状态（如输入非数字字符）
            cin.clear();  // 清除错误状态
            while (cin.get() != '\n');  // 清空输入缓冲区
            cout << "Invalid input" << endl;
            break;       // 跳出循环
        }
        ++count;
        if (len < count){
            cout << "Enter next number: ";
        }
    }
    return count;
}
void Show_array(double arr[], int len){      // 定义展示函数
    cout << "The array content: " << endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void Reverse_array(double arr[], int len){       // 定义反转函数
    double temp;
    for (int i = 0; i < (len / 2); ++i) {
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}