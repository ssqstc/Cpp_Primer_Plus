#include "iostream"
using namespace std;

/*
 * 知识点总结：
 * - 类型转换：使用`(double)`进行显式类型转换，以确保浮点数除法正确进行。
 * - 输入输出流：使用`cin`从标准输入读取数据，使用`cout`向标准输出打印数据。
 * - 算术运算：计算日本人口占世界人口的百分比。
 *
 * 注意点：
 * - 类型转换：确保整数除法转换为浮点数除法，以避免精度损失。
 * - 输入输出的格式和提示信息：确保用户能够正确理解和输入数据。
 */

/*
 * 主函数：计算日本人口占世界人口的百分比
 */
int main()
{
    long long world_people, jp_people; // 世界人口和日本人口

    cout << "Enter the world's population:"; // 提示用户输入世界人口
    cin >> world_people;

    cout << "Enter the population of the JP:"; // 提示用户输入日本人口
    cin >> jp_people;

    // 计算日本人口占世界人口的百分比
    double proportion = (double)jp_people / world_people * 100; // 计算比例并转换为百分比

    cout << "The population of the JP is " << proportion << "% of the world population."; // 输出结果

    return 0;
}
