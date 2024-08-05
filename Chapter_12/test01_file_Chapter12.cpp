#include "test01_head_Chapter12.h"

Cow::Cow() {
    m_name[0] = '\0';
    m_hobby = nullptr;
    m_weight = 0.0;
}

Cow::Cow(const char *a_name, const char *a_hobby, double a_weight) {
    strncpy(m_name, a_name, 20);
    if (strlen(a_name) >= 20)
        m_name[19] = '\0';
    m_hobby = new char [strlen(a_hobby) + 1];
    strcpy(m_hobby, a_hobby);
    m_weight = a_weight;
}

Cow::Cow(const Cow &a_cow) {
    strcpy(m_name, a_cow.m_name);
    m_hobby = new char [strlen(a_cow.m_hobby) + 1];
    strcpy(m_hobby, a_cow.m_hobby);
    m_weight = a_cow.m_weight;
}

Cow::~Cow() {
    delete[] m_hobby;
}

Cow &Cow::operator=(const Cow &a_cow) {
    if (&a_cow == this) {
        return *this;
    }
    delete[] m_hobby;
    strcpy(m_name, a_cow.m_name);
    m_hobby = new char [strlen(a_cow.m_hobby) + 1];
    strcpy(m_hobby, a_cow.m_hobby);
    m_weight = a_cow.m_weight;
    return *this;
}

void Cow::showCow() const {
    cout << "name = " << m_name << ", hobby = " << m_hobby << ", weight = " << m_weight << endl;
}