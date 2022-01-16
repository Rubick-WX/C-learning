#include<iostream>
#include <string.h>
using namespace std;

//这道题你可以理解递归为政府一级一级给下面布置任务完成，但每一层级都会中饱私囊，优先完成自己的需要，
//只有完成本层级的需求后，才会返回值给上一层
//当下层都满足不了需要的时候，必然返回给上层是“NO”！
//这一题，就是最左边男人找女人，遇到新的男人就拜托新男人帮自己去找，
//新男人会去找，但找到女人优先满足自己，并且回复上一层男人：“从我找到的女人往后找吧，之前的我都找过了，没有！”
//



int match(char s[],int i,int before){
    int begin=0;
    int last=0;

    if(s[i]!='\0'){
                    
                    //是(，继续往后找）。
                    if(s[i]=='('){  
                                    begin = 1;
                                    last = match(s, i + 1, begin);
                                    if(last<0){
                                        s[i] = '$';
                                        return last;        //当最后一阶左都找不到右，那么上一阶的左更找不到右，返回-1让他自己撸去吧。
                                    }
                                    //return last + 1;

                                    //是），如果有前置，则返回last值=1；反之，则错误，换成问号？
                    }else if(s[i]==')'){
                                    if(before==0){
                                        s[i] = '?';
                                        return match(s,i+1,0);
                                    }
                                    else
                                        return i;
                    }
                    else{
                                    //不管有没有开头，都只能向前走
                                    return match(s, i + 1, before);
                    }
                    return match(s, last + 1, before);


    }else{
        if(before==1)
            return -1;
    }
/*
    switch(s[i]){
        case '(':
            begin = 1;
            last=match(s,i+1);
        case ')':return 1;
        case '\0':
            return 0;
    }*/
}

int main(){
    char s[100] = ")(rttyy())sss)(";
    char a[100];
    strcpy(a,s);
    match(s, 0, 0);
    int i = 0;
    cout << a << endl;
    while(s[i]!='\0'){
        if(s[i]=='?')
            cout << '?';
        else if(s[i]=='$')
            cout << '$';
        else
            cout << " ";
        i++;
    }
    cout << endl;
    cout << s << endl;
    return 0;
}
