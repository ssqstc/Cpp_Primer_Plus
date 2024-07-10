#include "iostream"
using namespace std;

int main(){
    // 提供函数定义
    // 提供函数原型
    // 调用函数

    // void igor();
    // float tofu(int);
    // double mpg(double, double);
    // long summation(long [], long);
    // double doctor(const char * );
    // void ofcourse(boss);
    // char *plot(map *);

//    void arr_to_int(int arr[], int len, int value);{
//        for (int i = 0; i < len; ++i) {
//            arr{i} = value;
//        }
//    }

//    void arr_to_int2(int *first, int *last, int value){
//        for (int *i = first; i != last ; ++i) {
//            *i = value;
//        }
//    }

//    double max(const double arr[], double len){
//        double max_number = arr[0];
//        for (int i = 1; i < len; ++i) {
//            if (arr[i] > max_number){
//                max_number = arr[i];
//            }
//        }
//        return max_number;
//    }

    // 值传递 传递的是副本

    // char数组   char str[] = "hello world";
    // 字符串常量    "hello world";
    // 字符指针     char *p = "hello world";

//    int replace(char *str, char c1, char c2){
//        int count = 0;
//        while (*str){
//            if (*str == c1){
//                *str = c2;
//                ++count;
//            }
//            ++str;
//        }
//        return count;
//    }

    // 取值字符串地址的首元素'p'
    // 字符串地址[2]号下标即3号元素字母'c'

    // 按常规变量进程值传递
    // 使用指针传递地址 &glitz
    // 值传递安全低效  指针传递高效(const)

//    int judge(int (*pf)(const char));

//    void show(applicant app){
//        cout << "name = " << app.name << endl;
//        for (int i = 0; i < 3; ++i) {
//            cout << "credit_ratings = " << app.credit_ratings[i] << endl;
//        }
//    }
//    void show2(const applicant *app){
//        cout << "name = " << app->name << endl;
//        for (int i = 0; i < 3; ++i) {
//            cout << "credit_ratings = " << app->credit_ratings[i] << endl;
//        }
//    }

//    typedef void (*p_f1)(applicant *a);
//    p_f1 p1 = f1;
//
//    typedef const char *(*p_f2)(const applicant *a1, const applicant *a2);
//    p_f2 p2 = f2;
//
//    p_f1 ap[5];
//    p_f2 (*pa)[10];

    return 0;
}