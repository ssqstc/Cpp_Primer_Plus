#include "test04_head_Chapter12.h"

const int MAX = 5;
int main(){
    Stack stack(MAX);
    Item item;

    for (int i = 0; i < MAX; ++i) {
        cout << "Enter a number you want to push to stack: " << endl;
        cin >> item;
        while (cin.get() != '\n');
        stack.push(item);
    }

    Stack stack_new(stack);
    for (int i = 0; i < MAX; ++i) {
        stack_new.pop(item);
        cout << item << " is poped." << endl;
    }

    return 0;
}