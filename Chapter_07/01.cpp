#include "iostream"
using namespace std;
// 函数复习

void simple();
int main()
{
  cout << "main() will call the simple() function:" << endl;
  simple();
  return 0;
}
void simple()
{
  cout << "I'm but a simple function." << endl;
}