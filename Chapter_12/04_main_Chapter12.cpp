#include "04_head_Chapter12.h"

/*
知识点总结:
1. **队列（Queue）实现**: 使用链表实现队列，包括节点（Node）的定义、队列的基本操作（如enqueue和dequeue）。
2. **客户类（Customer）**: 用于模拟银行客户，包括到达时间和处理时间。
3. **随机数生成**: 用于模拟客户到达时间和处理时间的随机性。
4. **模拟（Simulation）**: 通过循环和条件判断模拟自动柜员机服务客户的过程。

注意点:
1. **内存管理**: 确保队列中的节点在析构函数中被正确删除，避免内存泄漏。
2. **随机数的使用**: 随机数生成器的种子使用 `srand(time(0))` 初始化，确保每次运行结果不同。
3. **边界条件处理**: 确保队列的边界条件（如队列满或空）被正确处理。
4. **统计和输出格式**: 确保输出的统计结果格式正确，特别是浮点数的输出精度。
*/

const int MIN_PER_HR = 60;  // 每小时的分钟数

bool newcustomer(double x);

int main() {
    srand(time(0));  // 初始化随机数种子

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";  // 输入队列的最大尺寸
    int qs;
    cin >> qs;
    Queue line(qs);  // 创建队列对象

    cout << "Enter the number of simulation hours: ";  // 输入模拟小时数
    int hours;
    cin >> hours;
    long cycleLimit = MIN_PER_HR * hours;  // 计算循环次数

    cout << "Enter the average number of customers per hour: ";  // 输入每小时的平均客户数
    double perHour;
    cin >> perHour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perHour;  // 计算平均每个客户之间的时间间隔

    Item temp;  // 临时客户对象
    long turnAways = 0;  // 因队列已满而被排除的客户数
    long customers = 0;  // 加入队列的客户数
    long served = 0;  // 模拟期间服务的客户数
    long sum_line = 0;  // 累积线长度
    int wait_time = 0;  // 距离自动柜员机免费的时间
    long line_wait = 0;  // 累计排队时间

    for (int cycle = 0; cycle < cycleLimit; ++cycle) {
        if (newcustomer(min_per_cust)) {
            if (line.isFull())
                turnAways++;
            else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if (wait_time <= 0 && !line.isEmpty()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.queueCount();
    }

    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnAways: " << turnAways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cycleLimit << endl;
        cout << " average wait time: " << (double) line_wait / served << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

// 判断是否有新客户到来
bool newcustomer(double x) {
    return (rand() * x / RAND_MAX < 1);
}