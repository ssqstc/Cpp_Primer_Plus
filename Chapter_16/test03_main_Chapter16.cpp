#include <iostream>
#include <string>
#include <cctype>   // 包含tolower函数的头文件
#include <ctime>    // 包含time函数的头文件
#include <cstdlib>  // 包含rand和srand函数的头文件
#include <fstream>  // 包含文件流操作的头文件
#include <vector>   // 包含vector容器的头文件

using namespace std;

/*
 * 知识点总结：
 * 1. 文件输入操作：`ifstream`用于从文件中读取数据，通过检查`is_open()`来确保文件成功打开。
 * 2. 字符处理：`tolower`函数将字符转换为小写，以统一处理用户输入。
 * 3. 随机数生成：使用`srand(time(0))`初始化随机数种子，`rand()`生成随机数。
 * 4. 容器操作：`vector`用于动态存储文件中的单词列表，适合处理可变大小的数据集。
 * 5. 字符串处理：通过`find`方法查找字符位置，并使用循环更新猜测字符串中的匹配字符。

 * 注意点：
 * 1. 文件打开失败处理：使用`is_open()`检查文件是否成功打开，如果失败则退出程序。
 * 2. 边界条件处理：在猜测单词的过程中，需要处理用户重复猜测字符的情况，以避免无效输入。
 * 3. 字符大小写一致性：在比较和存储用户输入时，确保所有字符为小写，以避免不必要的误匹配。
 */

int main() {
    srand(time(0)); // 使用当前时间作为随机数种子

    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play); // 将输入转换为小写

    ifstream fin;
    fin.open("test03_main_Chapter16.txt"); // 打开文件
    if (!fin.is_open()) { // 检查文件是否成功打开
        cout << "Open error!" << endl;
        exit(EXIT_FAILURE); // 如果打开失败，退出程序
    }

    vector<string> wordList; // 存储单词列表的容器
    string temp;
    while (fin >> temp) { // 逐行读取文件中的单词
        wordList.push_back(temp); // 将单词添加到容器中
    }

    while (play == 'y') { // 当用户选择继续游戏时
        string target = wordList[rand() % wordList.size()]; // 随机选择一个单词
        int length = target.length(); // 获取目标单词的长度
        string attempt(length, '-'); // 初始化猜测字符串，用'-'表示未猜中的字符
        string badChars; // 存储错误猜测的字符
        int guesses = 6; // 允许的错误猜测次数

        cout << "Guess my secret word, it has " << length << " letters, and you guess one letter at a time. You get " << guesses << " wrong guesses." << endl;
        cout << attempt << endl;

        while (guesses > 0 && attempt != target) { // 在剩余猜测次数内且未猜中全部单词时
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            letter = tolower(letter); // 将输入字符转换为小写

            if (badChars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
                cout << "You have already guessed that, try again." << endl;
                continue;
            }

            int loc = target.find(letter); // 查找输入字符在目标单词中的位置
            if (loc == string::npos) { // 如果未找到字符
                cout << "Oh, bad guess!" << endl;
                guesses--; // 减少剩余猜测次数
                badChars += letter; // 将错误猜测的字符添加到列表中
            } else {
                cout << "Good guess!" << endl;
                do {
                    attempt[loc] = letter; // 更新猜测字符串中的正确字符
                    loc = target.find(letter, loc + 1); // 继续查找下一个匹配字符
                } while (loc != string::npos);
            }

            cout << "Your word: " << attempt << endl; // 显示当前猜测状态

            if (attempt != target) { // 如果尚未猜中全部单词
                if (!badChars.empty()) { // 显示错误猜测的字符
                    cout << "Bad choices: " << badChars << endl;
                }
                cout << guesses << " bad guesses left!" << endl; // 显示剩余猜测次数
            }
        }

        if (guesses > 0 || attempt == target) { // 如果猜中或未用完所有猜测次数
            cout << "That is right!" << endl;
        } else {
            cout << "Sorry, the word is " << target << ". Will you play another time? <y/n> ";
            cin >> play;
            play = tolower(play); // 再次询问是否继续游戏
        }
    }

    return 0;
}