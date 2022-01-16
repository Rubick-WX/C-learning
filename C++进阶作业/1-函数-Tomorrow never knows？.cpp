#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

/*
void fen(char *date,char *year,char *month,char *day){
    for (int i=0;i<4;i++){
        year[i] = date[i];
    }
    for (int i = 0;i<2;i++)
    month[i]=
}
*/

bool run(int year){
    bool flag=0;
    flag = ((year%4==0)&&(year%100!=0)||(year%400==0));
    return flag;
}

int main(){
    char date[]="xxxx-xx-xx";
    int year;
    int month;
    int day;
    stringstream ss1,ss2,ss3;
    char date2[3][10]; //={'\0'};

    cout<<"输入日期："<<endl;


    cin.getline(date2[0], 10, '-');

    //cin.clear();
    cin.getline(date2[1], 10, '-');

    //cin.clear();
    cin.getline(date2[2], 10, '\n');

 /*
    cin.get(arr,size);语句如果读取到空行的话会设置一个failbit，
    接下来的输入就会全部被忽略，用cin.clear();就可以解决。
    反而是输入10-18个字符的情况下是能够停住的，
    因为第二个cin.get(x,size);没有读到空行。
*/


    //字符串变整数
    //不能用同一个ss，不然会出现乱码现象
    ss1 << date2[0];
    ss1 >> year;
    cout <<date2[0]<<"="<< year << endl;

    ss2 << date2[1];
    ss2 >> month;
    cout <<date2[1]<<"="<< month << endl;

    ss3 << date2[2];
    ss3 >> day;
    cout <<date2[2]<<"="<< day << endl;

    if(run(year))
        cout << "该年是闰年" << endl;
    else
        cout<<"该年是平年" << endl;
    //判断日期是否正常，是否日子超过31、30、29、28
    //判断月份是否超过12
    bool flag = 0;
    if(month==2){   //2月份
        if(run(year)==1){
            if(day<0||day>29)
                flag=1;
        }
        else{
            if(day<0||day>28)
                flag=1;
        }
    }
    else if(month==4||month==6||month==9||month==11){   //30日月
        if(day<0||day>30)
            flag=1;
    }
    else{   //31日月
        if(day<0||day>31)
            flag=1;
    }
    if(month>12)
        flag = 1;

    //超过范围，则说日期超过范围
    if(flag==1)
        cout << "日期超过范围了" << endl;

    //日期在月份最后一天，则月份++，日子变为1
    //不在月份最后一天，日期++即可
    //月份到了13月则跨年，年++，月份=1
    if(month==2){
        if(run(year)){
            if(day==29){
                month++;
                day = 1;
            }
            else
                day++;
        }
        else{
            if(day==28){
                month++;
                day = 1;
            }
            else
                day++;
        }
    }
    else if(month==4||month==6||month==9||month==11){
        if(day==30){
            month++;
            day = 1;
        }
    }
    else{
        if(day==31){
            month++;
            day = 1;
        }
    }

    if(month>12){
        year++;
        month = 1;
    }
    cout << flag << endl;
    cout << "第二天日期为：" << year << "-"<< setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day << endl;
    //输出带0的日期。

    return 0;
}