#include "iostream"
using namespace std;

int main()
{
    // version1两个判断语句都将执行到，version2更高效

    // char字符被强制转换成int类型数字  类型提升

    // H$i$!$
    // $S$e$n$d$ $ct1 = 9, ct2 = 9

    // weight >= 115 && weight < 125
    // ch == 'q' || ch == 'Q'
    // (x % 2 == 0) && (x != 26)
    // (x % 2 == 0) && (x % 26 != 0)
    // (donation >= 1000 && donation << 2000) || (1 == guest)
    // (ch >= 'a' && ch <= 'z') || (ch >= 'A' & & ch <= 'Z')

    // 不一定，假如x为10，则!x为0,!!x为1.  假如x为bool变量，则!!x为x。

    // if (x < 0)
    //      x = -x;
    // ps:  (x < 0) ? -x : x;   三目运算符

    // switch (ch)
    // {
    //      case 'A':   a_grade++;  break;
    //      case 'B':   b_grade++;  break;
    //      case 'C':   c_grade++;  break;
    //      case 'D':   d_grade++;  break;
    //      default:    f_grade++;
    // }

    // 如使用整数标签，且输入了非整数，程序将因为整数输入不能处理字符而挂起。使用字符标签，用户输入整数（如5），字符输入将5作为字符处理

    // int line = 0;
    // char ch;
    // while (cin.get(ch) && ch != 'Q')
    // {
    //      if (ch == '\n')
    //          line++;
    // }

    return 0;
}