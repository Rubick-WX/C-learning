#include<iostream>
using namespace std;

int nibolan(char s[],int i){
    int last;
    if(s[i]=='(')
        last=nibolan(s,i+1);
    else{
        return i;
    }
    cout << i  << ' ' << last<<endl;
    return nibolan(s,last+1);
}

int main(){
    char s[] = "((()(())())(()))";
    nibolan(s,0);
}