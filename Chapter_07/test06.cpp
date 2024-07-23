#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 数组处理：使用数组存储和处理数据。
 * 2. 指针操作：通过指针操作部分数组。
 * 3. 输入输出：使用 `cin` 和 `cout` 进行用户输入和输出操作。
 * 4. 函数：定义和使用函数来进行特定任务。
 *
 * 注意点：
 * 1. 输入验证：确保输入的数字有效。
 * 2. 数组边界：操作数组时要注意避免越界。
 * 3. 部分反转：反转数组时要注意起始和结束的位置。
 */

int Fill_array(double arr[], int len);  // 填充数组
void Show_array(double arr[], int len); // 显示数组内容
void Reverse_array(double arr[], int len);   // 反转数组
const int MAX = 40;    // 数组最大长度

int main(){
    double arr[MAX];   // 声明一个长度为 MAX 的数组
    int count;

    count = Fill_array(arr, MAX);  // 填充数组，并获取实际填充的元素个数
    Show_array(arr, count);   // 显示数组内容

    Reverse_array(arr, count);    // 反转整个数组
    Show_array(arr, count);   // 显示反转后的数组内容

    Reverse_array(arr + 1, count - 2);     // 反转数组的子部分（去掉首尾元素）
    Show_array(arr, count);         // 显示最终数组内容

    return 0;
}

int Fill_array(double arr[], int len){     // 填充数组函数
    double num;
    int count = 0;
    cout << "Enter double number: ";   // 提示用户输入数字
    while (count < len && cin >> arr[count]){   // 读取用户输入，直到数组填满或输入无效
        if (!cin){         // 检查输入是否有效
            cin.clear(); // 清除输入错误标志
            while (cin.get() != '\n'); // 丢弃无效输入
            cout << "Invalid input" << endl; // 提示输入无效
            break;      // 退出循环
        }
        ++count;
        if (len < count){ // 如果输入超过数组长度，提示继续输入
            cout << "Enter next number: ";
        }
    }
    return count;  // 返回实际填充的元素个数
}

void Show_array(double arr[], int len){    // 显示数组内容函数
    cout << "The array content: " << endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << "\t";    // 输出每个元素，用制表符分隔
    }
    cout << endl;
}

void Reverse_array(double arr[], int len){      // 反转数组函数
    double temp;
    for (int i = 0; i < (len / 2); ++i) {   // 只需遍历一半元素
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;  // 交换元素位置
    }
}
