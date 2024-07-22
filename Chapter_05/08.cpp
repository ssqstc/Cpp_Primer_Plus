#include "iostream"
#include "cstring" // 包含strcmp函数的头文件
using namespace std;

/*
知识点总结和注意点：
1. `strcmp`函数：
   - 用于比较两个C风格字符串的函数，返回值大于0表示第一个字符串大，返回值小于0表示第一个字符串小，返回值等于0表示两个字符串相等。
2. 字符数组的操作：
   - 可以通过直接赋值方式改变字符数组中的元素，从而改变字符串内容。

注意点：
- 在for循环中，`strcmp`函数用于判断是否结束循环。
- 当`strcmp`函数返回0时，循环结束，即字符串匹配成功。
- 确保字符数组足够大以容纳变化的字符串，并且不会导致越界访问。

*/

int main()
{
    char word[5] = "?ate"; // 初始化字符串
    for (char ch = 'a'; strcmp(word, "mate"); ch++) { // 当字符串不等于"mate"时继续循环
        cout << word << endl;
        word[0] = ch; // 修改字符串的第一个字符
    }
    cout << "After loop ends, word is " << word << endl; // 循环结束后的字符串
    return 0;
}
