#include "iostream"
using namespace std;

struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void box_function_a(box b);
void box_function_b(box *b);
int main(){

    box b = {"ssqstc",66,77,88,99};
    box_function_a(b);
    box_function_b(&b);

    box_function_a(b);

    return 0;
}
void box_function_a(box b){
    cout << "maker = " << b.maker << " ,height = " << b.height << " ,width = "
    << b.width << " ,length = " << b.length << " ,volume = " << b.volume << endl;
}
void box_function_b(box *b){
    b->volume = b->height * b->width * b->length;
}
