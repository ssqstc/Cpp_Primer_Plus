#include "iostream"
using namespace std;

const int ArSize = 80;
int main()
{
    char line[ArSize];
    int space_count = 0;
    cout << "Enter a line of text:" << endl;
    cin.get(line, ArSize);
    cout << "Complete line:" << line << endl;

    for (int i = 0; line[i] != '\0'; ++i) {     // 测试表达式元素为'\0'，结束循环
        if ('.' == line[i])     // '.'跳出循环
            break;
        cout << line[i];
        if (' ' != line[i])     // 不是空格重新循环并累计次数
            continue;
        space_count++;
    }
    cout << "spaces = " << space_count << endl;
    return 0;
}