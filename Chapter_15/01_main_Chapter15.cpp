// 知识点总结:
// 1. 本程序展示了友元类的使用，`Remote` 类作为 `Tv` 类的友元，可以直接访问 `Tv` 的私有成员。
// 2. `enum` 枚举用于定义 `Tv` 类中的状态、音量、频道等常量，便于控制和管理。
// 3. 类中包含多个控制电视操作的方法，如 `volUp`、`chanUp` 等，用于修改电视的状态。
// 4. 通过 `Tv` 类的友元 `Remote` 类，演示了如何使用外部类来控制 `Tv` 的状态。

// 注意点:
// 1. 在设计友元类时，注意友元关系的双向性，友元类可以访问所有私有和保护成员。
// 2. `enum` 枚举值要小心使用，确保值的范围合理，避免无效操作。
// 3. 设计中注意类的职责划分，`Tv` 负责保存状态和执行操作，而 `Remote` 负责控制 `Tv`。
// 4. `volUp` 和 `volDown` 函数需要检查当前音量是否超出范围，并根据情况返回是否成功。

#include "01_head_Chapter15.h"

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