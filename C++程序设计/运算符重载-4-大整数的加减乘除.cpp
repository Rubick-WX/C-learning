#include<iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码

class pInt
{
    char *c;
    int *n;

public:
    friend istream &operator>>(istream &a, pInt &b);

    //构造与析构
    pInt()
    {
        c = new char[100];
        n = new int[100];
    }
    ~pInt()
    {
        delete[] c;
        delete[] n;
    }
    //符号重载
};

istream &operator>>(istream &a, pInt &b)
{
    cin>>b.c;

    return a;
}
istream &operator>>(istream &a, char b)
{

    return a;
}

int main()
{
    pInt a, b;
    char o;
    cin >> a >> o >> b;
    switch(o){
    case '+':;
    case '-':;
    case '*':;
    case '/':;
    
    }
    return 0;
}