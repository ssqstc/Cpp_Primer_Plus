/*
知识点总结:
1. **友元类和友元函数**：`Remote` 类是 `Tv` 类的友元，因此 `Remote` 可以访问 `Tv` 的私有成员。
2. **枚举类型的使用**：通过枚举类型定义一组常量，使代码更具可读性和可维护性。
3. **对象交互**：展示了如何通过对象引用或指针在多个类之间进行交互操作。
4. **类的构造函数**：展示了如何使用带默认参数的构造函数来初始化对象。

注意点:
1. **友元的使用**：友元打破了封装性，因此在设计时应谨慎使用，避免过度依赖友元。
2. **枚举值的顺序**：确保枚举值的逻辑顺序合理，避免改变枚举值顺序导致不可预见的错误。
3. **构造函数的参数默认值**：确保默认参数值符合预期的初始状态。
*/

#include "test01_head_Chapter15.h"

int main() {
    Tv panda;  // 创建 Tv 对象 panda，默认状态为关闭
    cout << "Initial settings for Panda TV: " << endl;
    panda.showSettings();  // 显示 panda 的初始设置

    panda.onOff();  // 开启电视
    panda.showSettings();  // 显示电视开启后的设置
    cout << "----------------Dividing----------------" << endl;

    panda.volUp();  // 增加音量
    panda.chanUp();  // 增加频道
    panda.showSettings();  // 显示当前设置
    cout << "----------------Dividing----------------" << endl;

    Remote re;  // 创建 Remote 对象 re
    re.setChannel(panda, 66);  // 将 panda 的频道设置为 66
    re.volUp(panda);  // 增加 panda 的音量
    re.volUp(panda);  // 再次增加音量
    panda.showSettings();  // 显示当前设置
    cout << "----------------Dividing----------------" << endl;

    re.showCondition();  // 显示遥控器的当前模式
    panda.setCondition(re);  // 设置遥控器模式，前提是电视处于开机状态
    re.showCondition();  // 显示改变后的模式

    cout << "----------------Dividing----------------" << endl;
    re.onOff(panda);  // 使用遥控器关闭电视
    panda.showSettings();  // 显示关闭后的设置
    return 0;  // 返回 0 表示程序正常结束
}