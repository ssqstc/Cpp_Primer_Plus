#include "iostream"
#include "cstring" // 需要包含<cstring>头文件以使用strlen函数
using namespace std;

/*
知识点总结和注意点：
1. 字符串初始化和长度计算：
   - C风格字符串（char数组）：使用strlen计算字符串长度。未初始化的char数组可能包含随机值，调用strlen可能导致未定义行为。
   - C++字符串对象（string）：使用string::size计算字符串长度。C++字符串对象在初始化时为空字符串，长度为0。
2. 输入字符串：
   - cin.getline：用于从输入流中读取一行字符，存储在C风格字符串中。它会读取指定数量的字符或直到遇到换行符。
   - getline：用于从输入流中读取一行字符，存储在C++字符串对象中。它会读取整行字符直到遇到换行符。
3. 数组和字符串的区别：
   - C风格字符串：需要手动管理字符串的长度和结束符（'\0'）。
   - C++字符串对象：自动管理字符串的长度和内存分配，更加方便和安全。
4. 初始化和未初始化数组：
   - 在使用strlen之前，应确保C风格字符串已被初始化，否则可能导致未定义行为。

注意点：
- 安全性：在使用strlen之前，应确保字符串数组已被正确初始化。
- 输入流处理：使用cin.getline读取C风格字符串，使用getline(cin, str)读取C++字符串对象。
- 内存管理：C++字符串对象自动管理内存，而C风格字符串需要手动管理内存和字符串结束符。
- 兼容性：在混合使用C风格字符串和C++字符串对象时，注意函数和方法的不同。
*/

int main()
{
    char charr[20];     // 声明一个大小为20的C风格字符串数组
    string str;         // 声明一个C++字符串对象

    // 输出charr和str的初始长度。此时charr未被初始化，可能包含随机值
    cout << "charr数组字符串长度：" << strlen(charr) << endl; // 注意：charr未初始化，strlen可能会导致未定义行为
    cout << "str数组字符串长度：" << str.size() << endl;     // str在初始化时为空字符串，长度为0

    // 输入字符至charr数组
    cout << "输入字符至charr：" << endl;
    cin.getline(charr, 20);  // 使用getline读取一行字符，最多读取19个字符（保留1个字符给'\0'）
    cout << "输入charr内容是：" << charr << endl;

    // 输入字符至C++字符串对象str
    cout << "输入字符至str：" << endl;
    getline(cin, str);  // 使用getline读取一整行字符，直到遇到换行符
    cout << "输入str内容是：" << str << endl;

    // 输出输入数据后的charr和str的长度
    cout << "输入数据后，charr数组字符串长度：" << strlen(charr) << endl;  // 输出charr的长度
    cout << "输入数据后，str数组字符串长度：" << str.size() << endl;      // 输出str的长度

    return 0;  // 返回0表示程序正常结束
}
