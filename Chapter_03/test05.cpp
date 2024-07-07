#include "iostream"
using namespace std;

/* 主函数，程序的入口点 */
int main()
{
    /* 定义两个长整型变量，用于存储世界人口和日本人口 */
    long long world_people, jp_people;

    /* 请求用户输入世界人口总数 */
    cout << "Enter the world's population:";
    /* 从标准输入读取世界人口数据 */
    cin >> world_people;
    /* 请求用户输入日本人口总数 */
    cout << "Enter the population of the JP:";
    /* 从标准输入读取日本人口数据 */
    cin >> jp_people;

    /* 计算日本人口占世界人口的比例，并转换为百分比形式 */
    double proportion = (double)jp_people / world_people * 100;
    /* 输出日本人口占世界人口的百分比 */
    cout << "The population of the JP is " << proportion << "% of the world population.";
    return 0;
}
