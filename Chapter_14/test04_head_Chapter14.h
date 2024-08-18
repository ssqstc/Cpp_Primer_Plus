#ifndef TEST04_HEAD_CHAPTER14_H
#define TEST04_HEAD_CHAPTER14_H

#include <iostream>
#include <string>
using namespace std;

// Person 类表示一个人，有名字属性，作为基类
class Person {
private:
    string firstName;  // 名字
    string lastName;   // 姓氏
protected:
    virtual void get(); // 获取名字和姓氏
    virtual void data() const { cout << "Person name: " << firstName << ' ' << lastName << endl; } // 显示名字和姓氏
public:
    Person() : firstName("null"), lastName("null") {}
    Person(const string& str1, const string& str2) : firstName(str1), lastName(str2) {}
    virtual ~Person() {}
    virtual void set() { get(); }  // 设置名字和姓氏
    virtual void show() const { data(); }  // 显示名字和姓氏
};

// 获取用户输入的名字和姓氏
void Person::get() {
    cout << "Enter your firstname: ";
    getline(cin, firstName);
    cout << "Enter your lastname: ";
    getline(cin, lastName);
}

// Gunslinger 类表示枪手，继承自Person类
class Gunslinger : virtual public Person {
private:
    double time;  // 出枪时间
    int notch;    // 枪托的刻痕数量
protected:
    void get() override;  // 获取枪手属性
    void data() const override { cout << "notch: " << notch << ", time: " << time << endl; }  // 显示枪手属性
public:
    Gunslinger() : Person(), time(0.0), notch(0) {}
    Gunslinger(const string& str1, const string& str2, double t, int n) : Person(str1, str2), time(t), notch(n) {}
    double Draw() const { return time; }  // 返回出枪时间
    void set() override { Person::get(); get(); }  // 设置枪手属性
    void show() const override { Person::data(); data(); }  // 显示枪手属性
};

// 获取用户输入的出枪时间和刻痕数量
void Gunslinger::get() {
    cout << "Enter the draw time: ";
    cin >> time;
    cout << "Enter pistol notch: ";
    cin >> notch;
}

// Card 类表示一张扑克牌，有花色和点数属性
class Card {
private:
    const string COLOR[4] = {"spades", "hearts", "plum", "block"};  // 四种花色
    string color;  // 当前牌的花色
    int num;       // 当前牌的点数
public:
    Card() : color(COLOR[rand() % 4]), num(rand() % 13 + 1) {}  // 构造函数，随机生成牌的花色和点数
    void show() const { cout << color << ' ' << num << endl; }  // 显示牌的花色和点数
};

// PokerPlayer 类表示扑克牌玩家，继承自Person类
class PokerPlayer : virtual public Person {
private:
    Card card;  // 一张扑克牌
protected:
    void get() override {}  // 不需要额外获取属性
    void data() const override { card.show(); }  // 显示牌的信息
public:
    PokerPlayer() : Person(), card() {}
    PokerPlayer(const string& str1, const string& str2) : Person(str1, str2), card() {}
    Card Draw() const { return card; }  // 返回牌的信息
    void set() override { Person::get(); get(); }  // 设置玩家属性
    void show() const override { Person::data(); data(); }  // 显示玩家属性
};

// BadDude 类表示坏蛋，继承自Gunslinger和PokerPlayer类
class BadDude : public Gunslinger, public PokerPlayer {
protected:
    void get() override {}  // 不需要额外获取属性
    void data() const override {}  // 没有额外需要显示的信息
public:
    BadDude() : Person(), Gunslinger(), PokerPlayer() {}
    BadDude(const string& str1, const string& str2, double t, int n) : Person(str1, str2), Gunslinger(str1, str2, t, n), PokerPlayer(str1, str2) {}
    void gDraw() const { Gunslinger::Draw(); }  // 调用Gunslinger的Draw函数
    void cDraw() const { PokerPlayer::Draw(); }  // 调用PokerPlayer的Draw函数
    void set() override { Person::get(); Gunslinger::get(); PokerPlayer::get(); }  // 设置BadDude的属性
    void show() const override { Person::data(); Gunslinger::data(); PokerPlayer::data(); }  // 显示BadDude的属性
};

#endif //TEST04_HEAD_CHAPTER14_H