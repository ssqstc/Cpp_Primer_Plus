/*
知识点总结:
1. **结构体与向量**：使用结构体 `Review` 存储书名和评分，并通过 `vector` 容器动态管理多个书籍信息。
2. **迭代器的使用**：使用迭代器遍历 `vector` 容器，演示 `erase`、`insert` 和 `swap` 等操作。
3. **I/O 操作**：通过 `cin` 和 `getline` 输入书名与评分，处理输入流中的换行符。

注意点:
1. **向量操作**：`erase` 操作后，容器的大小和元素索引会发生变化，需注意避免超出范围。
2. **I/O 操作**：输入错误可能导致 `cin` 进入错误状态，需及时清理输入流。
*/

#include <iostream>   // 标准输入输出流库
#include <string>     // 标准字符串库
#include <vector>     // 标准向量库
using namespace std;

// 结构体定义，存储书籍信息
struct Review {
    string title;   // 书名
    int rating;     // 评分
};

// 函数声明
bool fillReview(Review& r);            // 填充书籍信息
void showReview(const Review& r);      // 显示书籍信息

int main() {
    vector<Review> books;  // 存储书籍信息的向量
    Review temp;
    while (fillReview(temp)) {
        books.push_back(temp);  // 将书籍信息添加到向量中
    }

    int num = books.size();  // 获取书籍数量
    if (num > 0) {
        cout << "You entered the following: " << endl;
        // 使用索引遍历并显示书籍信息
        for (int i = 0; i < num; ++i) {
            showReview(books[i]);
        }

        cout << "----------------Dividing----------------" << endl;

        // 使用迭代器遍历并显示书籍信息
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++) {
            showReview(*pr);
        }

        // 备份当前的书籍列表
        vector<Review> oldlist(books);

        if (num > 3) {
            // 删除索引 1 到 2 之间的元素
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After erasing: " << endl;
            for (pr = books.begin(); pr != books.end(); pr++) {
                showReview(*pr);
            }

            // 插入之前删除的第 2 个元素到新的列表开头
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "After inserting: " << endl;
            for (pr = books.begin(); pr != books.end(); pr++) {
                showReview(*pr);
            }
        }

        // 交换当前列表与备份列表
        books.swap(oldlist);
        cout << "After swapping: " << endl;
        for (pr = books.begin(); pr != books.end(); pr++) {
            showReview(*pr);
        }
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