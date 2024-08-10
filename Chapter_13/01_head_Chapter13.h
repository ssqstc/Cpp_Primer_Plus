#ifndef __01_HEAD_CHAPTER13_H__
#define __01_HEAD_CHAPTER13_H__

#include "string"
#include "iostream"
using namespace std;

// TableTennisPlayer类
class TableTennisPlayer {
private:
    string m_firstName; // 名
    string m_lastName; // 姓
    bool m_hasTable; // 是否有桌子
public:
    TableTennisPlayer(const string& fn = "none", const string& ln = "none", bool ht = false); // 构造函数
    void name() const; // 输出名字
    bool hasTable() const { return m_hasTable; } // 是否有桌子
    void ResetTable(bool v) { m_hasTable = v;} // 重置桌子状态
};

// RatedPlayer类，继承自TableTennisPlayer类
class RatedPlayer : public TableTennisPlayer {
private:
    unsigned int m_rating; // 评分
public:
    RatedPlayer(unsigned int r = 0, const string &fn = "none", const string &ln = "none", bool ht = false); // 构造函数
    RatedPlayer(unsigned int r, const TableTennisPlayer &tp); // 使用TableTennisPlayer对象创建RatedPlayer对象
    unsigned int rating() const { return m_rating; } // 获取评分
    void resetRating(unsigned int r) { m_rating = r; } // 重置评分
};

#endif //__01_HEAD_CHAPTER13_H__