#include "01_head_Chapter13.h"

// TableTennisPlayer类的构造函数
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : m_firstName(fn), m_lastName(ln), m_hasTable(ht) {}

// 输出TableTennisPlayer的名字
void TableTennisPlayer::name() const {
    cout << m_lastName << " " << m_firstName;
}

// RatedPlayer类的构造函数
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennisPlayer(fn, ln, ht) {
    m_rating = r; // 初始化评分
}

// 使用TableTennisPlayer对象创建RatedPlayer对象
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp), m_rating(r) {}