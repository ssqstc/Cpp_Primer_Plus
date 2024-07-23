#include "iostream"
using namespace std;

/*
 * 知识点：
 * 1. 结构体：定义和使用结构体。
 * 2. 函数参数传递：按值传递和按指针传递结构体。
 * 3. 指针操作：通过指针修改结构体成员。
 *
 * 注意点：
 * 1. 结构体的成员访问：使用点运算符访问结构体成员，使用箭头运算符通过指针访问结构体成员。
 * 2. 函数传递：按值传递不会修改原结构体，按指针传递会修改原结构体。
 * 3. 数据有效性：确保计算体积的函数接收到的结构体指针是有效的。
 */

struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void box_function_a(box b);
void box_function_b(box *b);

int main(){
    box b = {"ssqstc",66,77,88,99};  // 初始化结构体变量 b
    box_function_a(b);  // 按值传递，输出结构体成员
    box_function_b(&b);  // 按指针传递，计算体积
    box_function_a(b);  // 再次按值传递，输出结构体成员

    return 0;
}

void box_function_a(box b){  // 按值传递结构体
    // 输出结构体成员
    cout << "maker = " << b.maker << " ,height = " << b.height
         << " ,width = " << b.width << " ,length = " << b.length
         << " ,volume = " << b.volume << endl;
}

void box_function_b(box *b){  // 按指针传递结构体
    // 通过指针修改结构体成员
    b->volume = b->height * b->width * b->length;
}
