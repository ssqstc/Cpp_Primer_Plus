#include "test01_head_Chapter12.h"

int main() {
    Cow cow1;
    Cow cow2("ssqstc", "dadada", 70);
    Cow cow3(cow2);

    cow1 = cow2;
    cow1.showCow();
    cow2.showCow();
    cow3.showCow();
    return 0;
}