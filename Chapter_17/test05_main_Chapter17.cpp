/*
知识点：
1. `set` 集合：C++ 标准库中的集合类型，自动处理元素的排序和去重。
2. 文件操作：使用 `ifstream` 从文件中读取内容，`ofstream` 将结果输出到新文件。
3. `set_union`：标准库算法，用于求两个集合的并集。

注意点：
1. 在读取文件时，需要检查文件是否成功打开，防止读取无效文件数据。
2. `set` 集合会自动排序且不允许重复元素，因此适合处理不重复的名称数据。
3. `set_union` 函数的最后一个参数是插入迭代器，确保结果写入到并集集合 `Matnpat` 中。

*/

#include <iostream>   // 标准输入输出库
#include <set>        // 标准库中的集合类型
#include <fstream>    // 文件操作库
using namespace std;

int main() {
    // 打开输入文件 mat.dat 和 pat.dat，输出文件 matnpat.dat
    ifstream mat("mat.dat");  // 读取文件 mat.dat
    ifstream pat("pat.dat");  // 读取文件 pat.dat
    ofstream matnpat("matnpat.dat");  // 输出到文件 matnpat.dat
    string name;  // 用于存储从文件中读取的名称
    set<string> Mat, Pat, Matnpat;  // 定义三个集合

    // 检查文件 mat 是否成功打开，并将内容读入 Mat 集合
    if (mat.is_open()) {
        while (getline(mat, name) && name.size() > 0) {
            Mat.insert(name);  // 将读取的名称插入 Mat 集合
        }
    } else {
        cout << "mat open error" << endl;  // 输出错误信息
    }

    // 检查文件 pat 是否成功打开，并将内容读入 Pat 集合
    if (pat.is_open()) {
        while (getline(pat, name) && name.size() > 0) {
            Pat.insert(name);  // 将读取的名称插入 Pat 集合
        }
    } else {
        cout << "pat open error";  // 输出错误信息
    }

    // 计算 Mat 和 Pat 集合的并集，结果存入 Matnpat 集合
    set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(),
              insert_iterator<set<string>>(Matnpat, Matnpat.begin()));

    // 将并集集合 Matnpat 的内容写入文件 matnpat.dat
    for (auto x : Matnpat) {
        matnpat << x << endl;  // 输出每个元素并换行
    }

    // 关闭文件
    mat.close();
    pat.close();
    matnpat.close();

    return 0;  // 返回 0 表示程序成功执行
}