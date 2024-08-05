#ifndef __TEST01_HEAD_CHAPTER12_H__
#define __TEST01_HEAD_CHAPTER12_H__

#include "cstring"
#include "iostream"
using namespace std;

class Cow {
private:
    char m_name[20];
    char *m_hobby;
    double m_weight;
public:
    Cow();
    Cow(const char *a_name, const char *a_hobby, double a_weight);
    Cow(const Cow &a_cow);
    ~Cow();
    Cow & operator=(const Cow &a_cow);
    void showCow() const;
};

#endif //__TEST01_HEAD_CHAPTER12_H__
