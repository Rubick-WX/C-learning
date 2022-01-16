#include<iostream>
using namespace std;
int main(){
    int x[]={-2,-1,7,3,0,8};

    for(int i=0;i<6;i++){
        if(x[i]==i){
            cout<<"答案是："<<i<<endl;
            return 0;
        }
    }
    cout<<"N"<<endl;
    return 0;
}