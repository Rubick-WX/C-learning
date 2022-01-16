#include<iostream>
#include<iomanip>

using namespace std;



struct point{
    int x;
    int y;
};



int obey(point a,point b){ //
    if(a.x>=b.x&&a.y>=b.y)
        return 1;
    else
        return 0;
}

void swap(int &a,int &b){
    int temp;
    temp=a;
    a = b;
    b = temp;
}

int main(){
    point p[10];    //点的位置信息
    int ab[10][10]; //点与点之间的支配关系
    int num;    //点的个数
    int count[10]; //点的支配情况
    

    int count_da=0; //极大值点排序开始

    cout << "输入个数：";
    cin >> num;
    cout << endl;
    cout << "输入坐标：";
    for (int i = 0;i<num;i++){
        cin >> p[i].x >> p[i].y;
    }
    cout << endl;
    
        
        //自己比自己是极大点，即自己支配自己
    for (int i = 0; i < num; i++)
        ab[i][i] = 1;
    
    //跟别人比，如果是a支配b，那么b必不支配a；
    //但是a不支配b，b可能支配a，也可能不支配a
    
    for (int i = 0;i<num;i++){
        int flag=0; //累计p[i]被支配次数，要是极大值，只能被自己支配
        for (int j = 0;j<num;j++){
            //if(ab[i][j]==-1){
                ab[i][j] = obey(p[j], p[i]);    //是不是极大值点，不是看你支配多少点，而是看你背部被别人支配
            //    if(ab[i][j]==1)
            //        ab[j][i] = 0;
                flag += ab[i][j];
            //}
            //else{
            //    flag += ab[i][j];
            //    continue;
            
                
        }
        //ab[i][num] = flag;
        //如果
        
        if(flag==1){    //说明只被自己支配，是极大值点
            count[count_da]=i;  //按顺序记录极大值点
            count_da++;
        }
            
    }
    //按x轴从小到大排列
    for (int i = 0;i<count_da-1;i++){
        for (int j = 0;j<count_da-i-1;j++){
            if(p[count[j]].x>p[count[j+1]].x)
                swap(count[j], count[j + 1]);
        }
    }
        //输出所有极大点
        for (int i = 0; i < count_da; i++)
        {
            cout << '(' << p[count[i]].x << ',' << p[count[i]].y << ')';
            if(i<count_da-1)
                cout << ",";
        }

        return 0;
    }

