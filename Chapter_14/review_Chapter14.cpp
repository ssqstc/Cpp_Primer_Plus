//公有
//私有
//公有
//私有
//公有,私有

//#include <cstring>
//#include <iostream>
//class Frabjous {
//private:
//    char fab[20];
//public:
//    Frabjous(const char* s = "C++") { strncpy(fab, s, sizeof (fab) - 1); fab[sizeof (fab) - 1] = '\0'; }
//    virtual void tell() { std::cout << fab; }
//};
//
//class Gloam {
//private:
//    int glip;
//    Frabjous fb;
//public:
//    Gloam(int g = 0, const char* s = "C++");
//    Gloam(int g, const Frabjous& f);
//    void tell();
//};
//
//Gloam::Gloam(int g, const char* s) : fb(s) {
//    glip = g;
//}
//Gloam::Gloam(int g, const Frabjous& f) {
//    glip = g;
//    fb = f;
//}
//void Gloam::tell() {
//    fb.tell();
//    std::cout << "glip = " << glip;
//}

//#include <cstring>
//#include <iostream>
//class Frabjous {
//private:
//    char fab[20];
//public:
//    Frabjous(const char* s = "C++") { strncpy(fab, s, sizeof (fab) - 1); fab[sizeof (fab) - 1] = '\0'; }
//    virtual void tell() { std::cout << fab; }
//};
//
//class Gloam : private Frabjous {
//private:
//    int glip;
//public:
//    Gloam(int g = 0, const char* s = "C++");
//    Gloam(int g, const Frabjous& f);
//    void tell();
//};
//
//Gloam::Gloam(int g, const char* s) : Frabjous(s) {
//    glip = g;
//}
//Gloam::Gloam(int g, const Frabjous& f) : Frabjous(f) {
//    glip = g;
//}
//void Gloam::tell() {
//    Frabjous::tell();
//    std::cout << "glip = " << glip;
//}

//#include <iostream>
//template <typename Type>
//class Stack {
//private:
//    enum { MAX = 10 };
//    Type items[MAX];
//    int top;
//public:
//    Stack();
//    bool isEmpty();
//    bool isFull();
//    bool push(const Type& item);
//    bool pop(Type& item);
//};
//
//class Worker {
//private:
//    std::string fullname;
//    long id;
//protected:
//    virtual void data() const;
//    virtual void get();
//public:
//    Worker() : fullname("no one"), id(0L) {}
//    Worker(const std::string& s, long n) : fullname(s), id(n) {}
//    virtual ~Worker() = 0;
//    virtual void set() = 0;
//    virtual void show() const = 0;
//};
//
//class Stack<Worker*> {
//private:
//    enum { MAX = 10 };
//    Worker* items[MAX];
//    int top;
//public:
//    Stack();
//    bool isEmpty();
//    bool isFull();
//    bool push(const Worker* & item);
//    bool pop(Worker* & item);
//};

//ArrayTP<string, 10> str;
//Stack< Array<double, 10> > stack_double;
//Array< Stack<Worker*>, 10 > stack_worker_p;
//
//ArrayTP<int, 10>
//ArrayTP<double, 10>
//ArrayTP<int, 5>
//ArrayTP< ArrayTP<int, 5>, 10 >

//如果两条继承路线有相同的祖先,则类中包含组成成员的两个拷贝.设置虚基类可以解决此问题.