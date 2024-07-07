#include <iostream>
using namespace std;
const int HOUR_TO_DAY = 24;
const int MINUTE_TO_HOUR = 60;
const int SECOND_TO_MINUTE = 60;

int main()
{
    long second, second_first;
    int day, hour, minute;
    cout << "Enter the number of seconds:";
    cin >> second;
    second_first = second;

    day = second / (HOUR_TO_DAY * MINUTE_TO_HOUR * SECOND_TO_MINUTE);
    second = second % (HOUR_TO_DAY * MINUTE_TO_HOUR * SECOND_TO_MINUTE);

    hour = second / (MINUTE_TO_HOUR * SECOND_TO_MINUTE);
    second = second % (MINUTE_TO_HOUR * SECOND_TO_MINUTE);

    minute = second / SECOND_TO_MINUTE;
    second = second % SECOND_TO_MINUTE;

    cout << second_first << " seconds = " << day << " days, " << hour << " hours, "
        << minute << " minutes, " << second << " seconds";

    return 0;
}