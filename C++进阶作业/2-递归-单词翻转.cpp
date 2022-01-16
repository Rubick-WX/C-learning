#include<iostream>
using namespace std;

int reverse(char c[],int i){
    int num;
    if(c[i]!=' '&&c[i]!='\0'){
            num=reverse(c, i + 1);
            cout << c[i];
        }
    else
        return i;
    return num;
}

/*
开始一直想让一个函数既可以递归倒着输出，
又可以以空格为间隔顺序输出“倒着输出”的单词，
太难了，因为每一个函数包括递归部分又包括顺序输出部分，
我需要在递归时不触发顺序输出部分，那么就需要设置
状态量flag来记录当前函数运行状态：即在递归中不能出发顺序部分
太复杂了
*/

int main(){
    char s[100]="ni ma si le...";
    int num=0;

    while(s[num]!='\0'){
        num=reverse(s,num);
        cout << ' ';
        num++;
    }
    
}