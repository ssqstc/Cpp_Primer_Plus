#include "test03_head_Chapter12.h"

const int STKS = 4;
int main() {
    Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Mono", 130, 3.25),
            Stock("Fleep", 60, 6.5)
    };
    cout << "Stock holding:" << endl;
    for (int i = 0; i < STKS; ++i) {
        cout << stocks[i];
        cout << endl;
    }

    const Stock *top = &stocks[0];
    for (int i = 1; i < STKS; ++i) {
        top = &top->topVal(stocks[i]);
    }
    cout << "Most valuable holding: " << endl;
    cout << *top;

    return 0;
}