#include "test02_head_Chapter10.h"

/*
 * 知识点总结：
 * - 默认构造函数和带参数的构造函数：提供默认构造函数和带参数的构造函数，方便对象初始化。
 * - 字符数组与字符串的结合使用：使用 `char` 数组和 `string` 对象存储姓名信息。
 * - const 成员函数：用于不修改对象状态的成员函数，保证函数不会修改对象的状态。
 * - 字符串处理：使用 `strcpy` 函数将 `char*` 类型字符串复制到 `char` 数组中。
 *
 * 注意点：
 * - 构造函数初始化列表：可以使用初始化列表来初始化类成员。
 * - 字符数组边界：需要确保 `char` 数组的大小足够存储字符串，并且在操作时不会越界。
 * - `const` 成员函数：用于保证成员函数不会修改对象状态。
 */

/*
 * 主函数：演示 Person 类的使用
 * - 创建 Person 对象并显示姓名信息
 * - 调用显示函数展示不同格式的姓名
 */
int main(){
    Person one; // 使用默认构造函数创建对象
    Person two("Smythecraft"); // 使用单个参数创建对象
    Person three("Dimwiddy", "Sam"); // 使用两个参数创建对象

    one.show(); // 显示对象 one 的姓名
    one.FormalShow(); // 正式显示对象 one 的姓名
    cout << endl;

    two.show(); // 显示对象 two 的姓名
    two.FormalShow(); // 正式显示对象 two 的姓名
    cout << endl;

    three.show(); // 显示对象 three 的姓名
    three.FormalShow(); // 正式显示对象 three 的姓名

    return 0;
}