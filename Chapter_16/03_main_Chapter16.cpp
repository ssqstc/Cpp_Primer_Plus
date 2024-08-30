/*
知识点总结:
1. **随机数生成**：使用 `srand(time(0))` 初始化随机数生成器，并通过 `rand()` 生成随机索引以选择随机单词。
2. **字符串处理**：使用字符串函数如 `find()` 和 `length()`，对字符串的查找和长度操作进行处理。
3. **循环控制**：通过 `while` 循环控制游戏的逻辑，包括猜测、检查是否已经猜过的字母、处理错误猜测等。
4. **字符处理**：使用 `tolower()` 将用户输入的字符转化为小写，确保用户输入不区分大小写。

注意点:
1. **用户输入处理**：要验证用户的输入，并处理用户可能重复猜测的字符。
2. **边界条件**：确保在循环中正确处理猜测次数和猜测的单词是否与目标单词匹配。
3. **字符串查找**：使用 `find()` 函数查找字母在字符串中的位置，确保能够正确更新猜测的状态。
*/

#include <iostream>  // 标准输入输出流库
#include <string>    // 标准字符串库
#include <cctype>    // 字符处理库，包含 tolower()
#include <ctime>     // 时间库，包含 time() 函数
#include <cstdlib>   // C标准库，包含 srand() 和 rand()

using namespace std;

const int NUM = 26;  // 定义单词列表的大小
const string wordlist[NUM] = {"apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage", "health", "insult",
                              "jackal", "keeper", "loaner", "manage", "nonce", "onset", "plaid", "quilt", "remote",
                              "stolid", "train", "useful", "valid", "whence", "xenon", "yearn", "zippy"};

int main() {
    srand(time(0));  // 初始化随机数生成器
    char play;  // 存储用户是否继续玩的选择
    cout << "Will you play a word game? <y/n> ";  // 提示用户是否愿意玩游戏
    cin >> play;  // 接受用户输入
    play = tolower(play);  // 将用户输入转为小写

    while (play == 'y') {  // 如果用户选择玩游戏
        string target = wordlist[rand() % NUM];  // 随机选择一个单词作为目标单词
        int length = target.length();  // 获取目标单词的长度
        string attempt(length, '-');  // 初始化用户猜测的字符串，长度与目标单词相同，并用 '-' 填充
        string badChars;  // 用于存储用户猜错的字符
        int guesses = 6;  // 允许用户猜错的次数

        // 游戏开始提示信息
        cout << "Guess my secret word, it has " << length << " length letter, and you guess one letter at a time. You get " << guesses << " wrong guesses" << endl;
        cout << attempt << endl;  // 显示初始猜测状态

        while (guesses > 0 && attempt != target) {  // 在用户猜错次数未耗尽且未猜对整个单词的情况下循环
            char letter;  // 存储用户当前猜测的字母
            cout << "Guess a letter: ";  // 提示用户输入一个字母
            cin >> letter;  // 读取用户输入的字母

            // 检查用户是否已经猜过此字母
            if (badChars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
                cout << "You have already guessed that, try again." << endl;  // 如果用户已猜过，提示重新输入
                continue;  // 跳过本次循环
            }

            int loc = target.find(letter);  // 查找字母在目标单词中的位置
            if (loc == string::npos) {  // 如果字母不在目标单词中
                cout << "Oh, bad guess!" << endl;
                guesses--;  // 减少剩余的猜测次数
                badChars += letter;  // 将此字母添加到错误字符列表中
            } else {  // 如果字母在目标单词中
                cout << "Good guess!" << endl;
                do {
                    attempt[loc] = letter;  // 将猜对的字母放入猜测字符串中的正确位置
                    loc = target.find(letter, loc + 1);  // 查找字母在目标单词中下一个出现的位置
                } while (loc != string::npos);  // 直到找不到该字母为止
            }

            // 显示当前猜测状态
            cout << "Your word: " << attempt << endl;

            // 如果猜测尚未完成，显示剩余的猜测次数和错误字符
            if (attempt != target) {
                if (badChars.length() > 0) {
                    cout << "Bad choices: " << badChars << endl;  // 显示已猜错的字符
                }
                cout << guesses << " bad guesses left!" << endl;  // 显示剩余的猜错次数
            }
        }

        // 判断游戏结果
        if (guesses > 0 || attempt == target) {
            cout << "That is right!" << endl;  // 猜对单词时的提示
        } else {
            cout << "Sorry, the word is " << target << ", will you play another time? <y/n>";  // 猜错时显示目标单词，并询问是否重新开始游戏
            cin >> play;  // 接受用户输入
            play = tolower(play);  // 将用户输入转为小写
        }
    }

    return 0;  // 程序结束
}