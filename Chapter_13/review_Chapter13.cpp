//继承了所有的数据成员及大部分成员函数 但受控制权限限制

//构造函数 析构函数 赋值运算符 友元函数

//仍可以单个赋值 但不能连锁赋值
//进行值传递

//先调用基类构造函数、再调用派升构造函数  先调用派生析构函数、再调用基类析构函数

//需要 每个类都必须有自己的构造函数 如果为空 则自动生成默认构造函数

//派生类方法 基类方法将被隐藏 仅当派生类没有重新定义或者使用基类作用域运算符时 才会调用基类方法 然而应当将所有需重定义的函数声明为虚函数

//当派生类构造函数开辟new空间时

//可以
//可以,但强烈不建议. 只有通过显式类型转换才可以将基类对象的地址赋给派生类指针(向下转换),而这样使用指针不安全.

//可以 使用基类赋值运算符来实现 此时派生类中新增数据成员并不会传递给基类对象
//仅当派生类定义类转换运算符(即包含将基类引用作为唯一参数的构造函数)或使用基类为参数的赋值运算符时,相反的赋值才是有可能的.

//基类的引用和指针可以指向任何派生来的对象

//按值传递对象将调用复制构造函数,由于形参是基类对象,因此将调用基类的复制构造函数,复制构造函数以基类引用为参数,改引用可以指向作为参数传递的派生对象,最终结果是生成一个新的基类对象,其成员对应于派生对象的基类部分.

//按值传递将生成临时拷贝对象,即调用构造函数,然后析构函数 按引用传递传递的是对象本身

//调用指针类型的方法
//调用指针指向对象类型的方法

//基类私有成员派生类不可直接访问,需通过公有函数访问
//不能修改虚函数特征标 重新定义将隐藏基类方法