/*
 * 头文件：06_head_Chapter09.h
 * 知识点总结：
 * - 头文件保护符：使用预处理指令防止头文件重复包含。
 * - 外部变量声明：使用extern关键字声明外部变量。
 * - 函数声明：在头文件中声明函数。
 *
 * 注意点：
 * - 头文件保护符的正确使用。
 * - extern关键字的正确使用。
 */

#ifndef __06_HEAD_CHAPTER09_H__
#define __06_HEAD_CHAPTER09_H__

#include <iostream>

extern double warming; // 声明一个外部变量

void update(double dt);
void local();

#endif //__06_HEAD_CHAPTER09_H__