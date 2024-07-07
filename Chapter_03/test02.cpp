#include "iostream"
using namespace std;

// 主函数，用于计算并显示身体质量指数（BMI）
int main()
{
    // 定义常量，用于英尺到英寸的转换
    const int FOOT_TO_INCH = 12;
    // 定义常量，用于英寸到米的转换
    const float INCH_TO_METER = 0.0254;
    // 定义常量，用于磅到千克的转换
    const float POUND_TO_KILOGRAM = 2.2;
    
    // 定义变量，用于存储用户输入的身高（英尺和英寸）和体重（磅）
    float  height_foot, height_inch, weight_pound;

    // 请求用户输入身高（英尺）
    cout << "身高多少英尺_" ;
    cin >> height_foot;
    // 请求用户输入身高（英寸）
    cout << "多少英寸_";
    cin >> height_inch;
    // 请求用户输入体重（磅）
    cout << "体重多少磅_";
    cin >> weight_pound;

    // 计算身高（米），先将英尺和英寸转换为英寸，再转换为米
    double meter = (height_foot * FOOT_TO_INCH + height_inch) * INCH_TO_METER;
    // 计算体重（千克），将磅转换为千克
    double kilogram = weight_pound /  POUND_TO_KILOGRAM;
    // 计算BMI，即体重（千克）除以身高（米）的平方
    double bmi = kilogram / (meter * meter);
    // 显示计算得到的BMI值
    cout << "你的BMI是：" << bmi;
    return 0;
}
