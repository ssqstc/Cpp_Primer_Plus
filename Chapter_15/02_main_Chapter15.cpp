// 知识点总结:
// 1. 该代码展示了友元函数的使用：通过声明 `Remote` 类的成员函数为 `Tv` 类的友元，允许 `Remote` 类的函数访问 `Tv` 类的私有成员。
// 2. 类中使用了多个 `enum` 枚举来定义常量，控制电视的状态、音量、频道和输入模式的值。
// 3. `inline` 内联函数用于提高代码执行效率，特别是在函数体较短时，减少函数调用的开销。
// 4. `Tv` 类中的控制函数用于调整音量、频道以及输入模式等，而 `Remote` 类则通过调用这些函数来控制电视。

// 注意点:
// 1. 友元函数的使用需要谨慎，因为它打破了类的封装性，直接访问私有成员。
// 2. 枚举的取值范围需要在程序中小心控制，确保使用时不会超出定义的范围。
// 3. `inline` 函数尽量用于小型函数，以避免代码膨胀问题。
// 4. 在设计类时，注意将不同功能合理划分到不同类中，并通过友元关系、成员函数或友元函数进行必要的访问和控制。

#include "02_head_Chapter15.h"

int main() {
    // 创建一个 Tv 对象并显示其初始设置
    Tv panda;
    cout << "Initial settings for Panda TV: " << endl;
    panda.showSettings();

    // 打开或关闭电视并显示设置
    panda.onOff();
    panda.showSettings();
    cout << "----------------Dividing----------------" << endl;

    // 增加音量、切换频道并显示设置
    panda.volUp();
    panda.chanUp();
    panda.showSettings();
    cout << "----------------Dividing----------------" << endl;

    // 创建一个 Remote 对象并通过遥控器设置频道和音量
    Remote re;
    re.setChannel(panda, 66);
    re.volUp(panda);
    re.volUp(panda);
    panda.showSettings();
    cout << "----------------Dividing----------------" << endl;

    // 通过遥控器打开或关闭电视并显示设置
    re.onOff(panda);
    panda.showSettings();
    return 0;
}