#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int a[22][22] = {0};
    int m, n;
    cout << "输入行和列数：";
    cin >> m >> n;
    cout << endl;
    cout << "输入地块高度：" << endl;
    for (int i = 1;i<=m;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    cout << "山顶排序：" << endl;
    for (int i = 1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if(a[i][j]>=a[i+1][j]&&a[i][j]>=a[i-1][j]&&a[i][j]>=a[i][j+1]&&a[i][j]>=a[i][j-1])
                cout << i - 1 << " " << j - 1 << endl;
        }
    }
        return 0;
}