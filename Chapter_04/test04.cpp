#include "iostream"
using namespace std;

/*
知识点总结和注意点：
1. 结构体（struct）的定义与使用：
   - 结构体用于组合不同类型的数据。
   - 在定义结构体时，所有成员共享结构体实例的内存空间。

2. 结构体初始化：
   - 可以在定义结构体变量时使用初始化列表进行初始化。

3. 访问结构体成员：
   - 使用点运算符（`.`）访问结构体成员。

注意点：
- 结构体的成员变量应根据实际需求设置合适的类型和大小。
- 在输出结构体成员时，确保正确访问每个成员变量。
*/

struct CandyBar
{
    char brand[20];       // 品牌名称
    double weight;        // 重量
    unsigned int calories; // 卡路里
};

int main()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};  // 定义并初始化结构体变量snack

    // 输出结构体成员
    cout << "brand: " << snack.brand
         << " , weight: " << snack.weight
         << " , calories: " << snack.calories;

    return 0;  // 返回0表示程序正常结束
}
