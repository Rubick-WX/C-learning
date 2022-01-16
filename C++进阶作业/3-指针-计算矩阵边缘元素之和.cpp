#include<iostream>
#include <iomanip>
using namespace std;

int main(){
    int a[10][100][100];
    int sum[10]={0};
    int (*p)[100][100];
    int page = 2;
    int m=3,n=3;
    
    for (int i = 0;i<page;i++){
        for (int j = 0;j<m;j++){
            for (int k=0;k<n;k++){
                
                    *(*(*(a + i) + j) + k)=i+1;
                
            }
        }
    }

    
    p = a;
    //

    //cout << *p[1];
    /*cout << "总共几组数据？" << endl;
    cin >> k;
    cout << endl;
    cout << "请输入矩阵尺寸：" << endl;
    cin >> m>>n;
    cout << endl;
    cout << "输入数据吧：" << endl;*/
    
    for (int i = 0;i<page;i++){
        for (int j = 0;j<m;j++){
            for (int k=0;k<n;k++){
                if(j==0||j==m-1){
                    sum[i] += *(*(*(p + i) + j) + k);
                }else if(k==0||k==n-1){
                    sum[i]+=*(*(*(p + i) + j) + k);
                }
            }
        }
    }

    cout << setw(4)<<sum[0]<<setw(4)<<sum[1];

    return 0;
}