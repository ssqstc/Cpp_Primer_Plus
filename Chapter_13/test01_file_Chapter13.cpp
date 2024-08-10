#include "test01_head_Chapter13.h"

// Cd类的默认构造函数
Cd::Cd() {
    m_performers[0] = '\0'; // 初始化字符串为空
    m_label[0] = '\0';
    m_selections = 0;
    m_playtime = 0.0;
}

// Cd类的参数构造函数
Cd::Cd(char *s1, char *s2, int n, double x) {
    strncpy(m_performers, s1, 50); // 复制表演者信息
    if (strlen(s1) >= 50)
        m_performers[49] = '\0'; // 保证字符串以null结尾
    else
        m_performers[strlen(s1)] = '\0';
    strncpy(m_label, s2, 20); // 复制标签信息
    if (strlen(s2) >= 20)
        m_label[19] = '\0'; // 保证字符串以null结尾
    else
        m_label[strlen(s2)] = '\0';
    m_selections = n; // 复制选择数量
    m_playtime = x; // 复制播放时间
}

// Cd类的report函数，用于输出对象信息
void Cd::report() const {
    cout << "performers: " << m_performers << endl; // 输出表演者信息
    cout << "label: " << m_label << endl; // 输出标签信息
    cout << "selections: " << m_selections << endl; // 输出选择数量
    cout << "playtime: " << m_playtime << endl; // 输出播放时间
}

// Classic类的默认构造函数
Classic::Classic() : Cd() { m_str[0] = '\0'; } // 调用基类的默认构造函数，并初始化特有的字符串

// Classic类的参数构造函数
Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : Cd(s2, s3, n, x) {
    strncpy(m_str, s1, 50); // 复制特有的字符串信息
    if (strlen(s1) >= 50)
        m_str[19] = '\0'; // 保证字符串以null结尾
    else
        m_str[strlen(s1)] = '\0';
}

// Classic类的report函数，覆盖基类的report函数
void Classic::report() const {
    cout << "str: " << m_str << endl; // 输出特有的字符串信息
    Cd::report(); // 调用基类的report函数输出其余信息
}