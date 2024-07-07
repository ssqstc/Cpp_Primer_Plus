#include <iostream>
using namespace std;

// 定义常量，用于将度、分、秒转换为度
#define DEGREES_TO_MINUTE 60
#define MINUTE_TO_SECOND 60

int main()
{
    int degrees, minute, second; // 声明变量用于存储度、分、秒

    // 请求用户输入纬度的度、分、秒值
    cout << "Enter a latitude in degress, minutes, and seconds:\n";

    // 逐一输入度、分、秒
    cout << "First, enter the degress:";
    cin >> degrees;

    cout << "Nest, enter the minutes of arc:";
    cin >> minute;

    cout << "Finally, enter the seconds of arc:";
    cin >> second;

    // 将输入的度、分、秒转换为度，并输出
    cout << degrees << " degress, " << minute << " minutes, " << second << " seconds = "
         << (double)second / MINUTE_TO_SECOND / DEGREES_TO_MINUTE + (double)minute / DEGREES_TO_MINUTE + (double)degrees << " degress";
    
    return 0;
}
