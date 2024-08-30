#include <iostream>
#include <queue>
using namespace std;

/*
 * 知识点总结：
 * 1. **队列 (queue)**：使用`std::queue`来模拟银行排队系统，队列遵循先进先出的原则。
 * 2. **面向对象编程**：`Customer`类封装了客户的到达时间和处理时间。
 * 3. **随机数生成**：通过`rand()`函数生成客户的随机处理时间，并判断是否有新客户到来。
 * 4. **模拟循环**：通过循环模拟银行的工作时间，计算客户的到达、服务以及排队的情况。

 * 注意点：
 * 1. **随机数种子**：`srand(time(0))`用于初始化随机数种子，确保每次运行程序产生不同的随机结果。
 * 2. **整数除法与精度**：在计算客户之间的平均到达时间时，注意整数除法的精度问题。
 * 3. **条件判断**：判断新客户到来的概率、队列是否已满，以及自动柜员机是否空闲等条件，影响程序的流程。
 */

class Customer {
private:
    long m_arrive;  // 客户到达时间
    int m_processTime;  // 客户处理时间
public:
    Customer() { m_arrive = m_processTime = 0; }  // 构造函数，初始化到达时间和处理时间
    void set(long a_when);  // 设置客户到达时间和处理时间
    long when() const { return m_arrive; }  // 返回客户到达时间
    int ptime() const { return m_processTime; }  // 返回客户处理时间
};

void Customer::set(long a_when) {
    m_arrive = a_when;
    m_processTime = rand() % 3 + 1;  // 随机生成1到3分钟的处理时间
}

typedef Customer Item;  // 将Customer类定义为Item类型
const int MIN_PER_HR = 60;  // 每小时的分钟数

// 判断是否有新客户到来
bool newcustomer(double x) {
    return (rand() * x / RAND_MAX < 1);
}

int main() {
    srand(time(0));  // 初始化随机数种子

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";  // 输入队列的最大尺寸
    int max_size;
    cin >> max_size;
    queue<Item> qu;  // 创建队列对象

    cout << "Enter the number of simulation hours: ";  // 输入模拟小时数
    int hours;
    cin >> hours;
    long cycleLimit = MIN_PER_HR * hours;  // 计算循环次数

    cout << "Enter the average number of customers per hour: ";  // 输入每小时的平均客户数
    double perHour;
    cin >> perHour;
    double min_per_cust = MIN_PER_HR / perHour;  // 计算平均每个客户之间的时间间隔

    Item temp;  // 临时客户对象
    long turnAways = 0;  // 因队列已满而被排除的客户数
    long customers = 0;  // 加入队列的客户数
    long served = 0;  // 模拟期间服务的客户数
    long sum_line = 0;  // 累积线长度
    int wait_time = 0;  // 距离自动柜员机免费的时间
    long line_wait = 0;  // 累计排队时间

    // 模拟银行的工作流程
    for (int cycle = 0; cycle < cycleLimit; ++cycle) {
        if (newcustomer(min_per_cust)) {  // 检查是否有新客户
            if (qu.size() >= max_size) {  // 如果队列已满
                turnAways++;
            } else {
                customers++;
                temp.set(cycle);
                qu.push(temp);
            }
        }
        if (wait_time <= 0 && !qu.empty()) {  // 如果自动柜员机空闲且有客户等待
            temp = qu.front();
            qu.pop();
            wait_time = temp.ptime();  // 设置处理时间
            line_wait += cycle - temp.when();  // 累计排队时间
            served++;
        }
        if (wait_time > 0)  // 递减等待时间
            wait_time--;
        sum_line += qu.size();  // 记录队列长度
    }

    // 输出模拟结果
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnAways: " << turnAways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cycleLimit << endl;
        cout << " average wait time: " << (double) line_wait / served << " minutes\n";
    } else {
        cout << "No customers!\n";
    }
    cout << "Done!\n";

    return 0;
}