#include<iostream>
#include<iomanip>

using namespace std;



//back代表回去方向，+1左，-1右，+2上，-2下
//思路：
//终止条件，走到T上
//运行条件：如果四周有非墙壁单位，就走。
//每次走到无路可走就返回0，若是走到终点，就返回1.
//一个go在某一个方向走通了，会返回1，这时要及时继续返回值打断其他方向的遍历
//只有某一个方向没走通才需要遍历其他方向。
int go(char (*map)[100],int x,int y,int back){
    static int count=0;
    if(map[x][y]!='T'){
        //右
        if(map[x][y+1]=='.'||map[x][y+1]=='T'){
            if(back!=1){ //向右是往回走
                if(go(map, x, y+1, -1)){
                    cout << "向右走一步" << endl;
                    count++;
                    return count;
                }
            }
        }

        //左
        if(map[x][y-1]=='.'||map[x][y-1]=='T'){
            if(back!=-1){
                if(go(map, x, y-1, 1)){
                    cout << "向左走一步" << endl;
                    count++;
                    return count;
                }
            }
        }

        //上
        if(map[x-1][y]=='.'||map[x-1][y]=='T'){
            if(back!=2){
                if(go(map, x-1, y, -2)){
                    cout << "向上走一步" << endl;
                    count++;
                    return count;
                }
            }
        }

        //下
        if(map[x+1][y]=='.'||map[x+1][y]=='T'){
            if(back!=-2){
                if(go(map, x+1, y, 2)){
                    cout << "向下走一步" << endl;
                    count++;
                    return count;
                }
            }
        }

        return 0;
    }
    else{
        cout << "出来了！" << endl;
        return 1;
    }
    //上下左右都走不通
   
}






int main(){
    char map[100][100]={'\0'};
    int hang, lie;
    int x_start, y_start;
    int step[100][100] = {-1};

    cout << "输入行数：";
    cin >> hang;
    cout << endl;
    cout << "输入列数：";
    cin >> lie;
    cout << endl;

    cout << "输入迷宫地形：";
    for (int i = 1;i<=hang;i++){
        for (int j = 1;j<=lie;j++){
            cin >> map[i][j];
            if(map[i][j]=='.'||map[i][j]=='S'||map[i][j]=='T')
                step[i][j] = 0;
            if(map[i][j]=='S'){
                x_start = i;
                y_start = j;
            }
        }
    }
    //迷宫四周是墙壁
    for (int i = 0;i<=hang+1;i++){
        map[i][0] = '#';
        map[i][lie + 1] = '#';
    }
    for (int i = 1;i<=lie;i++){
        map[0][i] = '#';
        map[hang + 1][i] = '#';
    }

    cout<<"步数为："<<go(map, x_start, y_start, 0)<<endl;
    return 0;
}