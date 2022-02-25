#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码

class pInt{
    char *s;

    public:
        friend istream &operator>>(istream &a, pInt &b);

    //构造与析构

    //符号重载
};

istream & operator>>(istream &a,pInt &b){

    return a;
}

int main(){
    pInt a, b;
    char o;
    cin >> a >> o >> b;


    return 0;
}