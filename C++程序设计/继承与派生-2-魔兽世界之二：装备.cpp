#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

/////////////////////////基类区///////////////////////
class soilder{
    int hp;

    public:

};

class HQ{
    double HP;
    string CrusadeIndex[5];


public:
    HQ(string *s,int hpIndex){
        for (int i = 0;i<5;i++){
            CrusadeIndex[i] = *(s + i);
        }
    }

    void crusade(string a){
        switch(a){
            case"dragon":HP-=
        }
    }
};

///////////////////////定义函数区////////////////////



////////////////////////主函数区/////////////////////
int main(){
    



    return 0;
}

