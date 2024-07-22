#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 逗号运算符：
   - 在for循环中，逗号运算符用于分隔多个表达式，依次执行每个表达式。
2. 字符串反转算法：
   - 通过交换字符串首尾元素，逐步缩小交换范围，达到反转字符串的效果。

注意点：
- 交换字符时要注意数组的边界，防止越界访问。
- for循环中的逗号运算符可以简化多变量的操作。

*/

int main()
{
    cout << "Please enter a word:";  // 输入提示
    string word;
    cin >> word;

    int i, j;
    char tmp;

    // 通过交换字符的方式实现字符串反转
    for (j = 0, i = word.size() - 1; j < i; j++, i--)  // 逗号运算符先计算第一个表达式，再计算第二个表达式
    {
        tmp = word[i];
        word[i] = word[j];
        word[j] = tmp;
    }
    cout << word;  // 输出反转后的字符串

    return 0;
}
