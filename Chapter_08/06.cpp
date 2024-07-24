#include "iostream"
using namespace std;

struct free_throws {
    string name;   // 名字
    int made;      // 投中次数
    int attempts;  // 尝试次数
    float percent; // 命中率
};

void set_pc(free_throws &ft); // 设置命中率
void display(const free_throws &ft); // 显示球员信息
free_throws &accumulate(free_throws &target, const free_throws &source); // 累积球员数据

int main(){
    free_throws one = {"Rick", 13, 14}; // 初始化球员信息
    free_throws two = {"Jack", 10, 16}; // 初始化球员信息
    free_throws three = {"Jerry", 7, 9}; // 初始化球员信息
    free_throws four = {"Jason", 5, 9}; // 初始化球员信息
    free_throws five = {"Micheal", 6, 14}; // 初始化球员信息
    free_throws team = {"class 1", 0, 0}; // 初始化球队信息

    free_throws dup; // 声明一个free_throws结构体变量用于存储复制的数据

    set_pc(one); // 设置球员one的命中率
    display(one); // 显示球员one的信息

    accumulate(team, one); // 将球员one的数据累积到team
    display(team); // 显示球队信息

    display(accumulate(team, two)); // 将球员two的数据累积到team并显示累积后的信息

    // 将球员three, four, five的数据依次累积到team，并将最终的累积结果存储到dup
    dup = accumulate(accumulate(accumulate(team, three), four), five);

    display(team); // 显示球队信息
    display(dup); // 显示累积结果

    return 0;
}

void set_pc(free_throws &ft) {
    if (ft.attempts != 0) {
        ft.percent = 100.0 * float(ft.made) / float(ft.attempts); // 计算命中率
    } else {
        ft.percent = 0; // 若尝试次数为0，命中率为0
    }
}

void display(const free_throws &ft) {
    cout << "Name: " << ft.name << endl; // 输出名字
    cout << "Made: " << ft.made << '\t'; // 输出投中次数
    cout << "Attempts: " << ft.attempts << '\t'; // 输出尝试次数
    cout << "Percent: " << ft.percent << "%" << endl; // 输出命中率
}

free_throws &accumulate(free_throws &target, const free_throws &source) {
    target.attempts += source.attempts; // 累积尝试次数
    target.made += source.made; // 累积投中次数
    set_pc(target); // 重新计算命中率
    return target; // 返回累积后的结果
}
