#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int m, k;
    int n[6];
    cout<<"输入数m：";
    cin >> m;
    cout << endl;
    cout << "输入含有k个3：";
    cin >> k;
    cout << endl;

    int flag=0;
    int M = m;
    while (M / 10 != 0){
        if(M%10==3)
            flag++;
        M /= 10;
    }
    if(M==3)
        flag++;

    if(m%19==0&&flag==k)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}