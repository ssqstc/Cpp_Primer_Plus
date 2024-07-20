#include "test03_head_Chapter10.h"

/*
 * 带参数的构造函数
 * 初始化姓名和差点
 * name - 姓名
 * hc - 差点
 */
Golf::Golf(const char *name, int hc){
    strcpy(info.fullname, name); // 复制姓名到 fullname
    info.handicap = hc; // 设置差点
}

/*
 * 默认构造函数
 * 从用户输入初始化对象
 */
Golf::Golf(){
    cout << "The fullname is: "; // 提示输入姓名
    cin.getline(info.fullname, LEN); // 从输入读取姓名
    if (strcmp(info.fullname, "") != 0){ // 如果输入的姓名不为空
        cout << "The handicap is: "; // 提示输入差点
        cin >> info.handicap; // 从输入读取差点
        cin.get(); // 读取多余的换行符
    }
}

/*
 * 设置差点
 * hc - 新的差点值
 */
void Golf::handicap(int hc){
    info.handicap = hc; // 设置新的差点值
}

/*
 * 显示对象的姓名和差点
 * const 成员函数，保证不修改对象的状态
 */
void Golf::showgolf() const{
    cout << "The fullname is: " << info.fullname << endl; // 输出姓名
    cout << "The handicap is " << info.handicap << endl; // 输出差点
}