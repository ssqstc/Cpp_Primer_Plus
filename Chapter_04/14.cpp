#include "iostream"
using namespace std;

int main()
{
    double *p3 = new double [3];
     *p3 = 0.2;
     p3[1] = 0.5;
     p3[2] = 0.8;
     cout << p3[0] << "\t" << p3[1] << "\t" << p3[2] << "\t" << endl;   // 0.2	0.5	0.8
     // ++p3;
     cout << p3[0] << "\t" << p3[1] << "\t" << p3[2] << "\t" << endl;    // 0.5	0.8	0

     --p3;
     delete [] p3;

    return 0;
}