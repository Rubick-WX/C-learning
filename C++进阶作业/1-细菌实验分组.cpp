#include<iostream>
#include<iomanip>
using namespace std;

void swap(int &a,int &b){
    int p;
    p = a;
    a = b;
    b = p;
}

int main(){
    int n;
    int id[10]={0};
    int start[10]={0};
    int end[10]={0};
    float change[10]={0};
    int A[10]={0};
    cout << "输入培养皿个数：" << endl;
    cin >> n;
    cout << "输入编号、初始个数、结束个数" << endl;
    for (int i=0;i<n;i++){
        cin >> id[i] >> start[i] >> end[i];
        change[i] = end[i]/start[i];    //变化率
        A[i] = i+1 ;  //下标编号
    }

    //排序
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if(change[j]<change[j+1]){
                swap(change[j],change[j+1]);
                swap(A[j],A[j+1]);
            }
        }
    }
    int maxchange = change[0]-change[1];
    int maxchange_i = 0;
    for (int i=0;i<n-1;i++){
        if((change[i]-change[i+1])>maxchange){
            maxchange = change[i] - change[i + 1];
            maxchange_i = i;
        }
    }

    cout << "A种培养皿数量为：" << maxchange_i + 1 <<"   "<< "编号为：";
    for (int i=0;i<=maxchange_i;i++)
        cout << setw(5) << A[i];
    cout << endl;
    cout << "B种培养皿数量为：" << n-maxchange_i - 1 <<"   "<< "编号为：";
    for (int i=maxchange_i+1;i<n;i++)
        cout << setw(5) << A[i];
    cout << endl;
    return 0;
}