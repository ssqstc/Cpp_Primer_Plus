#include "iostream"
using namespace std;

// 主函数
// string类的其他操作
int main()
{
    // 定义一个字符数组charr1，未初始化
    char charr1[20];
    // 定义一个字符数组charr2，并初始化为"ssqstc666"
    char charr2[20] = "ssqstc666";
    // 定义一个空字符串str1
    string str1;
    // 定义一个初始化为"dadada"的字符串str2
    string str2 = "dadada";

    // 将str2的值赋给str1
    str1 = str2;
    // 将字符数组charr2的内容复制到charr1中
    strcpy(charr1,charr2);
    // 在str1的末尾追加字符串"dadada"
    str1 += "dadada";
    // 在字符数组charr1的末尾追加字符串"lalala"
    strcat(charr1,"lalala");

    // 获取str1的长度
    int len1 = str1.size();
    // 获取charr1的长度
    int len2 = strlen(charr1);

    // 输出str1的长度
    cout << "The string " << str1 << " contains " << len1 << " characters.\n";
    // 输出charr1的长度
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n";

    return 0;
}
