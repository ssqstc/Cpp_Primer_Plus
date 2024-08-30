#include <iostream>   // 标准输入输出流库
#include <string>     // 标准字符串库
#include <vector>     // 标准向量库
#include <algorithm>  // 标准算法库，包含 for_each, sort, shuffle
#include <memory>     // 智能指针库，包含 shared_ptr
using namespace std;

/*
 * 知识点总结：
 * 1. **智能指针**：使用`shared_ptr`管理动态分配的对象，自动处理内存管理，防止内存泄漏。
 * 2. **容器与算法**：结合`vector`容器与标准库算法，实现对书籍列表的各种排序方式。
 * 3. **运算符重载**：通过重载`operator<`实现书籍对象按标题和评分排序。
 * 4. **lambda函数**：可以用`lambda`函数简化一些比较和排序逻辑，使代码更加简洁易读。

 * 注意点：
 * 1. **输入数据的有效性**：确保输入的数据格式正确，特别是处理用户输入时避免无效输入导致的错误。
 * 2. **智能指针的使用**：使用`shared_ptr`管理动态分配的内存，可以避免手动释放内存的麻烦，但要注意循环引用问题。
 * 3. **排序稳定性**：不同排序方式的实现方法可能会影响最终的排序结果，特别是多个相同字段值的对象。

 */

struct Review {
    string title;  // 书籍标题
    int rating;    // 书籍评分
    double price;  // 书籍价格
};

// 填充书籍信息
bool fillReview(Review& r);
// 显示书籍信息
void showReview(const shared_ptr<Review>& r);
// 比较两个书籍的评分
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
// 比较两个书籍的价格
bool cheaperThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);

int main() {
    vector<shared_ptr<Review>> books;  // 用于存储书籍的`shared_ptr`对象容器
    Review temp;

    // 通过用户输入填充书籍信息
    while (fillReview(temp)) {
        shared_ptr<Review> pd(new Review(temp));  // 动态创建`Review`对象并用`shared_ptr`管理
        books.push_back(pd);  // 将书籍信息添加到容器中
    }

    int num = books.size();  // 获取书籍数量
    if (num > 0) {
        cout << "Choose the way you want to sort the books \n";
        cout << "1: original order\t\t2: alphabet order \n";
        cout << "3: rating up order\t\t4: rating down order \n";
        cout << "5: price up order\t\t6: price down order \n";

        int choice;
        while (cin >> choice) {
            switch (choice) {
                case 1:
                    for_each(books.begin(), books.end(), showReview);
                    break;
                case 2:
                    sort(books.begin(), books.end());
                    for_each(books.begin(), books.end(), showReview);
                    break;
                case 3:
                    sort(books.begin(), books.end(), worseThan);
                    for_each(books.begin(), books.end(), showReview);
                    break;
                case 4:
                    sort(books.begin(), books.end(), worseThan);
                    reverse(books.begin(), books.end());
                    for_each(books.begin(), books.end(), showReview);
                    break;
                case 5:
                    sort(books.begin(), books.end(), cheaperThan);
                    for_each(books.begin(), books.end(), showReview);
                    break;
                case 6:
                    sort(books.begin(), books.end(), cheaperThan);
                    reverse(books.begin(), books.end());
                    for_each(books.begin(), books.end(), showReview);
                    break;
                default:
                    cout << "Done!\n";
                    return 0;
            }
        }
    }
    return 0;
}

// 从用户输入中填充书籍信息
bool fillReview(Review& r) {
    cout << "Enter book title, (enter quit to quit):";
    getline(cin, r.title);
    if (r.title == "quit") {
        return false;
    }
    cout << "Enter book rating: ";
    cin >> r.rating;
    cout << "Enter book price: ";
    cin >> r.price;

    if (!cin) {  // 检查输入是否有效
        return false;
    }
    while (cin.get() != '\n');  // 清除输入缓冲区
    return true;
}

// 显示书籍信息
void showReview(const shared_ptr<Review>& r) {
    cout << r->rating << "\t" << r->title << '\t' << r->price << endl;
}

// 运算符重载，按标题排序，如果标题相同则按评分排序
bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
    if (r1->title < r2->title) {
        return true;
    } else if (r1->title == r2->title && r1->rating < r2->rating) {
        return true;
    } else {
        return false;
    }
}

// 比较两个书籍的评分
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
    return r1->rating < r2->rating;
}

// 比较两个书籍的价格
bool cheaperThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
    return r1->price < r2->price;
}