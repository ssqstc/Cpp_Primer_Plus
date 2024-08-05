#include "test06_head_Chapter12.h"

const int MIN_PER_HR = 60;

bool newCustomer(double x);

int main() {
    srand(time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs), line2(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cycleLimit = MIN_PER_HR * hours;

    Item temp;
    long served;    // 模拟期间服务
    int wait_time1, wait_time2;  // 距离自动柜员机免费的时间
    long line_wait; // 累计排队时间

    double perHour = 1;
    double min_per_cust;
    bool run = true;
    while (run) {
        served = 0;
        wait_time1 = 0;
        wait_time2 = 0;
        line_wait = 0;
        min_per_cust = MIN_PER_HR / perHour;

        for (int cycle = 0; cycle < cycleLimit; ++cycle) {
            if (newCustomer(min_per_cust)) {
                if (line1.queueCount() < line2.queueCount() && !line1.isFull()) {
                    temp.set(cycle);
                    line1.enqueue(temp);
                } else {
                    if (!line2.isFull()) {
                        temp.set(cycle);
                        line2.enqueue(temp);
                    }
                }
            }
            if (wait_time1 <= 0 && !line1.isEmpty()) {
                line1.dequeue(temp);
                wait_time1 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time2 <= 0 && !line2.isEmpty()) {
                line2.dequeue(temp);
                wait_time2 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            if (wait_time2 > 0)
                wait_time2--;
        }
        if ((double) line_wait / served > 1)
            run = false;
        else
            perHour++;
    }
    cout << "Simulation ended. Final rate: " << perHour << " customers per hour.\n";
    return 0;
}

bool newCustomer(double x) {
    return (rand() * x / RAND_MAX < 1);
}