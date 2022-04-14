
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

/////////////////////////类区///////////////////////
class MyString:public string {
    string s;

public:
    MyString(string ss){
        s.assign(ss);
    }

    MyString(){}

    MyString(char ss){
        s[0] = ss;
    }

    MyString(const char* ss){
        for (int i = 0;ss[i]!='\0';i++)
            s.push_back(ss[i]);
            //结尾不要压入\0，不然\0会占用一个位置，后续打印的时候遇到\0就会停止打印。
    }

    
    char& operator[](int i)
    {
        return this->s[i];
    }

   

    MyString operator=(char ss){
        this->s.clear();
        this->s.push_back(ss);
        return *this;
    }
    MyString operator=(MyString ss){

        this->s.assign(ss.s);
        return *this;
    }
    MyString operator+(MyString ss){
        MyString p(*this);
        p.s.append(ss.s);
        return p;
    }
    MyString operator+(const char *ss){
        this->s.append(ss);
        return *this;
    }
    MyString operator()(int i,int j){
        return this->s.substr(i, j);
    }

    void operator+=(const char * p){
        this->s.append(p);
    }

    

    friend ostream& operator<<(ostream &,MyString ss);
    friend MyString operator+(const char *p, MyString pp);
    friend bool operator>(MyString a, MyString b);
    friend bool operator<(MyString a, MyString b);
    friend bool operator==(MyString a, MyString b);
};

///////////////////////定义函数区////////////////////
ostream& operator<<(ostream &cout, MyString ss){
        cout << ss.s;
        return cout;
    }

MyString operator+(const char* p,MyString pp){
    MyString ss(p);
    ss.s.append(pp.s);
    return ss;
}

    bool operator>(MyString a,MyString b){
        for (int i = 0;a[i]!=b[i];i++){
            if(a[i]>b[i])
                return true;
            else
                return false;
        }
    }

    bool operator<(MyString a,MyString b){
        for (int i = 0;a[i]!=b[i];i++){
            if(a[i]<b[i])
                return true;
            else
                return false;
        }
    }

    bool operator==(MyString a,MyString b){
        for (int i = 0;a[i]!=b[i];i++){
            if(a[i]==b[i])
                return true;
            else
                return false;
        }
    }

////////////////////////主函数区/////////////////////
int CompareString( const void * e1, const void * e2) {
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( *s1 < *s2 ) return -1;
    else if( *s1 == *s2 ) return 0;
    else if(*s1>*s2)return 1;
}

int main() {
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3; s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1; s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString), CompareString);
    for( int i = 0;i < 4;++i )
        cout << SArray[i] << endl;
    //输出s1从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //输出s1从下标为5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
