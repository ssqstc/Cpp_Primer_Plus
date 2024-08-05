#include "test05_head_Chapter12.h"

const int MIN_PER_HR = 60;

bool newCustomer(double x);

int main() {
    srand(time(0));

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cycleLimit = MIN_PER_HR * hours;

    Item temp;
    long served;    // 模拟期间服务
    int wait_time;  // 距离自动柜员机免费的时间
    long line_wait; // 累计排队时间

    double perHour = 1;
    double min_per_cust;
    bool run = true;
    while (run) {
        served = 0;
        wait_time = 0;
        line_wait = 0;
        min_per_cust = MIN_PER_HR / perHour;

        for (int cycle = 0; cycle < cycleLimit; ++cycle) {
            if (newCustomer(min_per_cust)) {
                if (!line.isFull()) {
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