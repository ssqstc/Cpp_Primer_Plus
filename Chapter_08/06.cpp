#include "iostream"
using namespace std;

// 结构体定义，用于存储罚球信息
struct free_throws {
    string name;   // 球员姓名
    int made;      // 投中次数
    int attempts;  // 尝试次数
    float percent; // 命中率
};

// 函数声明
void set_pc(free_throws &ft); // 计算罚球命中率
void display(const free_throws &ft); // 显示罚球信息
free_throws &accumulate(free_throws &target, const free_throws &source); // 累计罚球数据

int main(){
    // 定义结构体变量
    free_throws one = {"Rick", 13, 14};
    free_throws two = {"Jack", 10, 16};
    free_throws three = {"Jerry", 7, 9};
    free_throws four = {"Jason", 5, 9};
    free_throws five = {"Micheal", 6, 14};
    free_throws team = {"class 1", 0, 0}; // 初始化一个空的团队统计

    free_throws dup; // 备用结构体变量

    // 计算并显示单个球员的罚球信息
    set_pc(one);
    display(one);

    // 累计罚球数据并显示
    accumulate(team, one);
    display(team);

    display(accumulate(team, two)); // 连续累加并显示

    // 连续调用 accumulate 函数，更新 team 数据并将结果赋给 dup
    dup = accumulate(accumulate(accumulate(team, three), four), five);

    // 显示最终的团队统计和备份的数据
    display(team);
    display(dup);

    return 0;
}

// 计算罚球命中率
void set_pc(free_throws &ft) {
    if (ft.attempts != 0) {
        ft.percent = 100.0 * float(ft.made) / float(ft.attempts);
    } else {
        ft.percent = 0; // 避免除以零
    }
}

// 显示罚球信息
void display(const free_throws &ft) {
    cout << "Name: " << ft.name << endl;
    cout << "Made: " << ft.made << '\t';
    cout << "Attempts: " << ft.attempts << '\t';
    cout << "Percent: " << ft.percent << "%" << endl;
}

// 累计罚球数据并返回更新后的目标结构体
free_throws &accumulate(free_throws &target, const free_throws &source) {
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target); // 更新命中率
    return target;  // 返回更新后的目标结构体
}
