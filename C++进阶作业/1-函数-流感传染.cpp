#include<iostream>
using namespace std;
int main(){
    char room[100][100] = {'#'};
    int flag[100][100] = {0};
    int n;
    int num=0;
    cout << "输入房间尺寸：";
    cout << endl;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> room[i][j];
            if (room[i][j]=='@'){
                num++;
                flag[i][j]++;
            }
        }
    }

    //四条边清零
    int i = 0;
    while(i<=n+1){
        room[0][i] = '#';
        room[i][0] = '#';
        room[n+1][i]= '#';
        room[i][n+1]= '#';
        i++;
    }

    cout << endl;
    cout << num << endl;
    //.健康人
    //#空房间
    //@新病人
    //$老病人
    int m;
    cout << "输入过去天数：";
    cout << endl;
    cin >> m;

    //开始扫描
    int time = 2;
    while(time<=m){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if(flag[i][j]==1){  
                        //flag=1说明是还没有感染过别人的新感染者
                        //flag>1说明是之前已经感染过人的旧感染者
                        

                    if(room[i+1][j]=='.'){  
                        room[i+1][j] = '@';
                        num++;
                    }

                    if(room[i-1][j]=='.'){  
                        room[i-1][j] = '@';
                            num++;
                        }

                        if(room[i][j+1]=='.'){  
                            room[i][j+1] = '@';
                            num++;
                        }

                        if(room[i][j-1]=='.'){  
                            room[i][j-1] = '@';
                            num++;
                        }
                   

                    }
                
            }
        }
        //每天及时清算
        //新感染标记成新一天的感染者，旧感染已经不会参与后一天的感染。
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if(room[i][j]=='@')
                    flag[i][j]++;
            }
        }

        //无需管边缘地带，因为是空房间，根本不会变化。
        time++;
    }
    cout << "过了" << m << "天，得流感人数为：" << num << endl;

    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=n+1;j++){
            cout << room[i][j];
        }
        cout << endl;
    }
}