#include <iostream>
using namespace std;

const int HOUR_TO_DAY = 24; // 常量：1天等于24小时
const int MINUTE_TO_HOUR = 60; // 常量：1小时等于60分钟
const int SECOND_TO_MINUTE = 60; // 常量：1分钟等于60秒

/*
 * 知识点总结：
 * - 常量定义：使用`const`定义转换单位的常量，提高代码可读性和维护性。
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 算术运算：使用除法和取模运算将总秒数转换为天、小时、分钟和秒。
 *
 * 注意点：
 * - 输入输出的格式和提示信息：确保用户能够正确理解和输入数据。
 * - 算术运算的顺序：按从大到小的单位（天、小时、分钟、秒）依次进行转换和取模。
 */

/*
 * 主函数：将用户输入的秒数转换为天、小时、分钟和秒的表示
 */
int main()
{
    long second, second_first; // 用户输入的总秒数和初始秒数
    int day, hour, minute; // 转换后的天、小时和分钟

    cout << "Enter the number of seconds:"; // 提示用户输入秒数
    cin >> second;
    second_first = second;

    // 将总秒数转换为天数，并计算剩余秒数
    day = second / (HOUR_TO_DAY * MINUTE_TO_HOUR * SECOND_TO_MINUTE);
    second = second % (HOUR_TO_DAY * MINUTE_TO_HOUR * SECOND_TO_MINUTE);

    // 将剩余秒数转换为小时数，并计算剩余秒数
    hour = second / (MINUTE_TO_HOUR * SECOND_TO_MINUTE);
    second = second % (MINUTE_TO_HOUR * SECOND_TO_MINUTE);

    // 将剩余秒数转换为分钟数，并计算剩余秒数
    minute = second / SECOND_TO_MINUTE;
    second = second % SECOND_TO_MINUTE;

    // 输出转换结果
    cout << second_first << " seconds = " << day << " days, " << hour << " hours, "
         << minute << " minutes, " << second << " seconds";

    return 0;
}
