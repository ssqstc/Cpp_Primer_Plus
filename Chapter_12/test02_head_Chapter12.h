#ifndef __TEST02_HEAD_CHAPTER12_H__
#define __TEST02_HEAD_CHAPTER12_H__

#include "iostream"
#include "cstring"
#include "cctype"
using namespace std;

class String {
private:
    static int const CINLIMIT = 60;
    char *m_str;
    int m_len;
public:
    String();
    String(const char *a_ch);
    String(const String &a_st);
    ~String();

    void stringLow();
    void stringUp();
    int has(const char a_n) const;

    String &operator=(const String &a_st);
    String &operator=(const char *a_ch);
    String operator+(const String &a_st) const;

    friend istream &operator>>(istream &a_is, String &a_st);
    friend ostream &operator<<(ostream &a_os, const String &a_st);
    friend String operator+(const char *a_ch, const String &a_st);
    friend bool operator==(const String &a_st1, const String &a_st2);

};


#endif //__TEST02_HEAD_CHAPTER12_H__
