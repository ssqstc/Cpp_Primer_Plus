    // 自动 (代码块中)
    // 静态 外部链接 (不在任何函数内)
    // 静态 内部链接 (不在任何函数内 使用关键字static)
    // 静态 无连接 (代码块中 使用关键字static)

    // using声明时 声明的名称可见 未声明的不可见 若名称已存在 则不能导入相同的名称
    // using编译时 命名空间内全部名称均可见 若名称已存在 则局部名称将隐藏名称空间名

//#include <iostream>
//int main(){
//    double x;
//    std::cout << "Enter value:";
//        while (!(std::cin >> x)){
//            std::cout << "Bad input. Please enter a number: ";
//            std::cin.clear();
//            while (std::cin.get() != '\n'){
//                continue;
//            }
//        }
//        std::cout << "Value = " << x << std::endl;
//    return 0;
//}

//#include <iostream>
//int main(){
//    using std::cout;
//    using std::cin;
//    using std::endl;
//    double x;
//    cout << "Enter value: ";
//    while (!(cin >> x)){
//        cout << "Bad input. Please enter a number: ";
//        cin.clear();
//        while (cin.get() != '\n'){
//            continue;
//        }
//        cout << "Value = " << x << endl;
//        return 0;
//    }
//}

//    分别定义average()函数 参数为int和double 均用static修饰

//    10
//    4
//    0
//    Other: 10, 1
//    another():10, -4

//    1
//    4, 1, 2
//    2
//    2
//    4, 1, 2
//    2
