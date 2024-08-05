#include "test06_head_Chapter12.h"

/*
知识点总结:
1. **队列的实现**: 使用链表实现队列，包含基本操作如入队、出队、检查队列是否为空和是否已满。
2. **客户类**: 用于表示客户，包含到达时间和处理时间。
3. **随机数生成**: 用于模拟客户到达。
4. **模拟**: 模拟银行柜员机的工作，计算客户等待时间和服务速率。
5. **双队列处理**: 模拟场景中有两个队列，分别对应两个柜员机。

注意点:
1. **内存管理**: 在队列的析构函数中，确保所有节点的内存都被正确释放，避免内存泄漏。
2. **边界检查**: 在入队和出队操作时检查队列是否已满或为空，防止非法操作。
3. **随机数生成的正确使用**: 确保随机数生成器被正确初始化，避免伪随机数序列重复。
4. **负载平衡**: 将客户分配到较短的队列中，确保负载平衡。
*/

const int MIN_PER_HR = 60; // 每小时的分钟数

// 检查是否有新客户到达
bool newCustomer(double x);

int main() {
    srand(time(0)); // 随机数种子

    cout << "Case Study: Bank of Heather Automatic Teller\n"; // 案例研究：希瑟银行自动柜员
    cout << "Enter maximum size of queue: "; // 输入队列的最大容量
    int qs;
    cin >> qs;
    Queue line1(qs), line2(qs); // 创建两个队列对象，容量为qs

    cout << "Enter the number of simulation hours: "; // 输入模拟的小时数
    int hours;
    cin >> hours;
    long cycleLimit = MIN_PER_HR * hours; // 总的模拟周期数

    Item temp; // 临时变量，用于存储客户信息
    long served;    // 模拟期间服务的客户数
    int wait_time1, wait_time2;  // 距离自动柜员机空闲的时间
    long line_wait; // 累计排队时间

    double perHour = 1; // 每小时到达的客户数
    double min_per_cust;
    bool run = true;
    while (run) {
        served = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line_wait = 0;
        min_per_cust = MIN_PER_HR / perHour; // 每个客户之间的平均分钟数

        for (int cycle = 0; cycle < cycleLimit; ++cycle) {
            if (newCustomer(min_per_cust)) { // 如果有新客户到达
                if (line1.queueCount() < line2.queueCount() && !line1.isFull()) {
                    temp.set(cycle); // 设置客户到达时间
                    line1.enqueue(temp); // 将客户加入队列1
                } else {
                    if (!line2.isFull()) {
                        temp.set(cycle);
                        line2.enqueue(temp); // 将客户加入队列2
                    }
                }
            }
            if (wait_time1 <= 0 && !line1.isEmpty()) { // 如果柜员机1空闲且队列1非空
                line1.dequeue(temp); // 处理队列1中的下一个客户
                wait_time1 = temp.ptime(); // 设置处理时间
                line_wait += cycle - temp.when(); // 计算排队时间
                served++;
            }
            if (wait_time2 <= 0 && !line2.isEmpty()) { // 如果柜员机2空闲且队列2非空
                line2.dequeue(temp); // 处理队列2中的下一个客户
                wait_time2 = temp.ptime(); // 设置处理时间
                line_wait += cycle - temp.when(); // 计算排队时间
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--; // 减少柜员机1的处理时间
            if (wait_time2 > 0)
                wait_time2--; // 减少柜员机2的处理时间
        }
        if ((double) line_wait / served > 1) // 如果平均等待时间超过1分钟
            run = false;
        else
            perHour++;
    }
    cout << "Simulation ended. Final rate: " << perHour << " customers per hour.\n"; // 输出模拟结果
    return 0;
}

// 判断是否有新客户到达
bool newCustomer(double x) {
    return (rand() * x / RAND_MAX < 1); // 生成0到1之间的随机数，如果小于1则返回true
}