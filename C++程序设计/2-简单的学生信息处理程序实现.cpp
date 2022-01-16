#include<stdio.h>
#include<iostream>
#include<string.h>

//
using namespace std;


class student{
    char name[10],id[10];
    int age;
    int grade[4];
    
    public :
        student(char a[10], int b, char c[10], int d[4]);
        
};
student::student(char a[10],int b, char c[10],int d[4]){
        strcpy_s(name,a);
        age = b;
        strcpy_s(id,c);
        
        int all_grade = 0;
        for (int i=0;i<4;i++){
            grade[i] = d[i];
            all_grade += grade[i];
        }
        cout << name << ',' << age << ',' << id << ',' << all_grade / 4<<endl;
    }

int main(){
    char info[7][10]={"wx","26","1151","60","70","80","90"};//姓名、年龄、学号、四年成绩
    int grade[4]={60,70,80,90};

/*
    for (int i = 0; i < 7;i++){
        cin.get(info[i], 10, ',');
        if(i>=3){
            grade[i - 3] = atoi(*(info+i));
        }
    }
*/
    
    student one(*info,atoi(*(info+1)),*(info+2),grade);
    return 0;
}