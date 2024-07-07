#include "iostream"
using namespace std;

// 结构体每个成员可以相互赋值
struct inflatable
{
    char name[20];
    float volume;
    double price;
} ssqstc;   // 可以同时定义结构体并创建结构体变量
int main()
{
    inflatable bouquet = {"sunflowers",0.20,12.49};
    inflatable choice;

    cout << bouquet.name << " " << bouquet.volume << " " << bouquet.price << endl;

    choice = bouquet;

    cout << choice.name << " " << choice.volume << " " << choice.price << endl;

    return 0;
}