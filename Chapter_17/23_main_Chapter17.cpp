/*
知识点：
1. 使用 `tmpnam` 函数生成临时文件名。
2. TMP_MAX 和 L_tmpnam 是标准库定义的常量，分别表示可以生成的最大临时文件名数量和每个临时文件名的最大长度。
3. 基本的数组初始化和字符串处理。

注意点：
1. `tmpnam` 生成的临时文件名在不同操作系统上可能表现不同，不会自动创建文件，仅返回一个唯一的名字。
2. 生成的临时文件名没有特别安全性保证，建议现代程序使用更安全的函数如 `mkstemp`。
*/

#include <iostream>   // 包含输入输出流库
#include <cstdio>     // 包含 C 标准库中的输入输出函数，例如 tmpnam
using namespace std;  // 使用标准命名空间

int main() {
    // 输出系统可以生成的最大临时文件名数量和每个文件名的最大字符数
    cout << "This system can generate up to " << TMP_MAX
         << " temporary names of up to " << L_tmpnam << " characters.\n";

    // 定义字符数组存储临时文件名，并初始化为空字符串
    char pszName[L_tmpnam] = { '\0' };

    // 输出提示信息，表示即将生成十个临时文件名
    cout << "Here are ten names:\n";

    // 循环生成 10 个临时文件名并输出
    for (int i = 0; i < 10; ++i) {
        tmpnam(pszName);  // 使用 tmpnam 生成临时文件名，存入 pszName
        cout << pszName << endl;  // 输出生成的临时文件名
    }

    return 0;  // 返回 0，表示程序成功执行
}