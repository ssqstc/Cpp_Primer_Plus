#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 结构体定义：
   - 使用`struct`关键字定义结构体。结构体是一种用户自定义的数据类型，可以包含不同类型的数据成员。
   - 结构体成员可以是基本数据类型，如`char`、`float`、`double`等。

2. 结构体初始化：
   - 可以在定义结构体变量时使用花括号初始化所有成员。
   - 也可以在之后通过逐个赋值或直接赋值另一个结构体变量来初始化结构体变量。

3. 结构体赋值：
   - 可以将一个结构体变量赋值给另一个结构体变量，两个结构体变量的所有成员都将被复制。

4. 输出结构体成员：
   - 使用`cout`输出结构体的成员，直接通过`结构体变量.成员`的方式访问。

注意点：
- 结构体变量在使用前需要正确初始化，否则可能包含未定义值。
- 结构体赋值是逐成员赋值，适用于相同结构的结构体。
- 输出结构体成员时需要注意格式化输出，以便清晰显示结构体内容。
*/

struct inflatable
{
    char name[20];   // 结构体成员：名称（字符数组）
    float volume;    // 结构体成员：体积（浮点型）
    double price;    // 结构体成员：价格（双精度浮点型）
} ssqstc;           // 结构体变量ssqstc

int main()
{
    // 定义并初始化结构体变量bouquet
    inflatable bouquet = {"sunflowers", 0.20, 12.49};

    // 定义结构体变量choice
    inflatable choice;

    // 输出bouquet结构体的成员
    cout << bouquet.name << " " << bouquet.volume << " " << bouquet.price << endl;

    // 将bouquet赋值给choice
    choice = bouquet;

    // 输出choice结构体的成员，应该与bouquet相同
    cout << choice.name << " " << choice.volume << " " << choice.price << endl;

    return 0; // 返回0表示程序正常结束
}
