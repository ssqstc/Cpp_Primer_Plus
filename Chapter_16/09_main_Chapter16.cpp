/*
知识点总结:
1. **结构体与运算符重载**：使用结构体 `Review` 存储书籍的标题和评分，通过重载 `<` 运算符和自定义排序函数 `worseThan` 进行排序。
2. **STL 算法库**：使用 `for_each` 遍历向量、`erase` 删除元素、`insert` 插入元素、`swap` 交换内容、`shuffle` 随机打乱顺序以及 `sort` 进行排序。
3. **随机数生成**：使用 `random_device` 和 `mt19937` 生成用于打乱顺序的随机数。

注意点:
1. **自定义排序**：`operator<` 运算符重载与 `worseThan` 函数需确保排序逻辑一致，避免排序结果不符合预期。
2. **向量操作**：在执行 `erase` 和 `insert` 操作时，需注意索引的准确性，避免越界访问。
*/

#include <iostream>   // 标准输入输出流库
#include <string>     // 标准字符串库
#include <vector>     // 标准向量库
#include <algorithm>  // 标准算法库，包含 for_each, sort, shuffle
#include <random>     // 标准随机数库
using namespace std;

// 结构体定义，存储书籍信息
struct Review {
    string title;   // 书名
    int rating;     // 评分
};

// 函数声明
bool fillReview(Review& r);                    // 填充书籍信息
void showReview(const Review& r);              // 显示书籍信息
bool worseThan(const Review& r1, const Review& r2);  // 自定义排序函数，按评分从低到高排序

int main() {
    random_device rd;  // 随机数生成设备
    mt19937 g(rd());   // 随机数引擎

    vector<Review> books;  // 存储书籍信息的向量
    Review temp;
    while (fillReview(temp)) {
        books.push_back(temp);  // 将书籍信息添加到向量中
    }

    int num = books.size();  // 获取书籍数量
    if (num > 0) {
        cout << "You entered the following: " << endl;
        for_each(books.begin(), books.end(), showReview);  // 遍历并显示书籍信息

        vector<Review> oldlist(books);  // 备份当前的书籍列表

        if (num > 3) {
            // 删除索引 1 到 2 之间的元素
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasing: " << endl;
            for_each(books.begin(), books.end(), showReview);

            // 插入之前删除的第 2 个元素到新的列表开头
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "After inserting: " << endl;
            for_each(books.begin(), books.end(), showReview);
        }

        // 交换当前列表与备份列表
        books.swap(oldlist);
        cout << "After swapping: " << endl;
        for_each(books.begin(), books.end(), showReview);

        // 随机打乱书籍顺序
        cout << "After random shuffle: " << endl;
        shuffle(books.begin(), books.end(), g);
        for_each(books.begin(), books.end(), showReview);

        // 按照书名进行排序
        cout << "After sorting: " << endl;
        sort(books.begin(), books.end());
        for_each(books.begin(), books.end(), showReview);

        // 按照评分进行排序
        cout << "After sorting2: " << endl;
        sort(books.begin(), books.end(), worseThan);
        for_each(books.begin(), books.end(), showReview);

    } else {
        cout << "Done!" << endl;  // 如果没有输入任何书籍，程序结束
    }

    return 0;
}

// 填充书籍信息函数，返回布尔值指示是否继续输入
bool fillReview(Review& r) {
    cout << "Enter book title, (enter quit to quit):";
    getline(cin, r.title);  // 获取书名
    if (r.title == "quit") {
        return false;  // 输入 "quit" 结束输入
    }
    cout << "Enter book rating: ";
    cin >> r.rating;  // 获取评分
    if (!cin) {
        return false;  // 输入错误时结束输入
    }
    while (cin.get() != '\n');  // 清理输入流
    return true;  // 输入成功
}

// 显示书籍信息函数
void showReview(const Review& r) {
    cout << r.rating << "\t" << r.title << endl;  // 输出评分和书名
}

// 重载运算符 '<'，按书名和评分排序
bool operator<(const Review& r1, const Review& r2) {
    if (r1.title < r2.title) {
        return true;
    } else if (r1.title == r2.title && r1.rating < r2.rating) {
        return true;
    } else {
        return false;
    }
}

// 自定义排序函数，按评分从低到高排序
bool worseThan(const Review& r1, const Review& r2) {
    return r1.rating < r2.rating;
}