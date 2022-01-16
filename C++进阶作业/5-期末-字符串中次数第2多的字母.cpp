#include<iostream>
#include<iomanip>

using namespace std;

struct abc{

    char az[4];  //a+A
    int count=0;    //0
};

int main(){
    abc s[26];
    char a[500]="ab&dcAab&c9defgb";

    for (int i=0;i<26;i++){
        s[i].az[0] = (char)(i+65);
        s[i].az[1] = '+';
        s[i].az[2] = (char)(i+97);
    }
    cout << "输入字符串：" << endl;
    //cin >> a;

    for (int i = 0;a[i]!='\0';i++){
        if((int)a[i]>=65&&(int)a[i]<=90)    //大写
            s[(int)a[i]-65].count++;
        else if((int)a[i]>=97&&(int)a[i]<=122)  //小写
            s[(int)a[i]-97].count++;

    }

    //找出第一多的数。
    int max_count1=0;
    for (int i = 0; i < 26; i++)
    {
        if(s[i].count>max_count1)
            max_count1 = s[i].count;
    }
    //找出第二多的数。
    int max_count2=0;
    for (int i=0;i<26;i++){
        if(s[i].count<max_count1&&s[i].count>max_count2)
            max_count2 = s[i].count;
    }

    //找出第一个第二多的数
    
    for (int i = 0;a[i]!='\0';i++){
        if((int)a[i]>=65&&(int)a[i]<=90){
            if(s[(int)a[i]-65].count==max_count2){
            cout << s[i].az <<":"<< max_count2<< endl;
            break;
        }
        }    //大写
        else if((int)a[i]>=97&&(int)a[i]<=122){
            if(s[(int)a[i]-97].count==max_count2){
            cout << s[i].az <<":"<< max_count2<< endl;
            break;
            }
        }  //小写
            
        
    }
    

        //第二出现次数多有多个，比如abc
        //从头开始遍历，第一个出现a/b/c就输出谁。
        return 0;
}