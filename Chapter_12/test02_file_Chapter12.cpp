#include "test02_head_Chapter12.h"

String::String() {
    m_str = new char[1];
    m_str[0] = '\0';
    m_len = 0;
}

String::String(const char *a_ch) {
    m_len = strlen(a_ch);
    m_str = new char[m_len + 1];
    strcpy(m_str, a_ch);
}

String::String(const String &a_st) {
    m_len = strlen(a_st.m_str);
    m_str = new char[m_len + 1];
    strcpy(m_str, a_st.m_str);
}

String::~String() {
    delete[] m_str;
}

String &String::operator=(const String &a_st) {
    if (this == &a_st)
        return *this;
    delete[] m_str;
    m_len = strlen(a_st.m_str);
    m_str = new char[m_len + 1];
    strcpy(m_str, a_st.m_str);
    return *this;
}

String &String::operator=(const char *a_ch) {
    delete[] m_str;
    m_len = strlen(a_ch);
    m_str = new char[m_len + 1];
    strcpy(m_str, a_ch);
    return *this;
}

istream &operator>>(istream &a_is, String &a_st) {
    char temp[String::CINLIMIT];
    a_is.get(temp, String::CINLIMIT);
    if (a_is)
        a_st = temp;
    while (a_is && a_is.get() != '\n');
    return a_is;
}

bool operator==(const String &a_st1, const String &a_st2) {
    return (strcmp(a_st1.m_str, a_st2.m_str) == 0);
}


ostream &operator<<(ostream &a_os, const String &a_st) {
    a_os << a_st.m_str;
    return a_os;
}

String operator+(const char *a_ch, const String &a_st) {
    String temp;
    temp.m_len = strlen(a_ch) + a_st.m_len;
    temp.m_str = new char[temp.m_len + 1];
    strcpy(temp.m_str, a_ch);
    strcat(temp.m_str, a_st.m_str);
    return temp;
}

String String::operator+(const String &a_st) const {
    String temp;
    temp.m_len = m_len + a_st.m_len;
    temp.m_str = new char[temp.m_len + 1];
    strcpy(temp.m_str, m_str);
    strcat(temp.m_str, a_st.m_str);
    return temp;
}

void String::stringLow() {
    for (int i = 0; i < m_len; ++i) {
        m_str[i] = tolower(m_str[i]);
    }
}

void String::stringUp() {
    for (int i = 0; i < m_len; ++i) {
        m_str[i] = toupper(m_str[i]);
    }
}

int String::has(const char a_n) const {
    int count = 0;
    for (int i = 0; i < m_len; ++i) {
        if (m_str[i] == a_n)
            count++;
    }
    return count;
}