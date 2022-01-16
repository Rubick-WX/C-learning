//由于变长度数组vector没学会，需要学习再开看看



#include<iostream>
#include<vector>
using namespace std;
/*
//输入长度n，输出长度n-1
int* delate(int choose,int chang,int ABCD[]){
    int ABC[4]={0};
    //初始化缩短数组
    for (int i=0;i<chang;i++){
        ABC[i] = ABCD[i];
    }
    //如果所选下标超出范围就不对（其实不要也行）
    if(choose>=chang||choose<0){
        cout << "选的什么几把数？！"<< endl;
        return 0;
    }

    if(choose==chang-1)
        return ABC;
    else{
        for (int i=choose;i<chang-1;i++){
            ABC[choose] = ABC[choose + 1];
        }  
        return ABC;
    }
}
*/
int main(){
    string name[]={"鄱阳湖：","洞庭湖：","太湖：","洪泽湖："};
    int a, b, c, d; //a鄱阳湖 b洞庭湖 c太湖 d洪泽湖
    for (int i=0;i<4;i++){
        a = i+1;
        for (int j=0;j<4;j++){
            if(j==i)
                continue;
            b = j+1;
            for (int m=0;m<4;m++){
                if(m==i||m==j)
                    continue;
                c = m+1;
                for (int n=0;n<4;n++){
                    if(n==m||n==j||n==i)
                        continue;
                    d = n+1;
                    int flag = 0;
                    if ((b == 1) && (d == 4) && (a == 3))
                        flag++;
                    if ((d == 1) && (b == 1) && (a == 2) && (c == 3))
                        flag++;
                    if ((d == 4) && (b == 3))
                        flag++;
                    if ((a == 1) && (c == 4) && (d == 2) && (b == 3))
                        flag++;
                    if (flag == 1)
                    {
                        cout << name[0] << a << endl;
                        cout << name[1] << b << endl;
                        cout << name[2] << c << endl;
                        cout << name[3] << d << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
/*
        //每次小循环都会破坏原有的结构，需要初始化上一级别的初始数组。
        for (int i = 0; i < 4; i++)
        {
            a = ABCD[i];
            int *ABC = delate(i, 4, ABCD);
            for (int j = 0, b = ABC[j]; j < 3; j++)
            {
                b = ABC[j];
                int *AB = delate(j, 3, ABC);
                for (int k = 0; k < 2; k++)
                {
                    c = AB[k];
                    int *A = delate(k, 2, AB);
                    d = A[0];
                    //每次名次分配完毕，逻辑判断——开始！！！！
                    int flag = 0;
                    if ((b == 1) && (d == 4) && (a == 3))
                        flag++;
                    if ((d == 1) && (b == 1) && (a == 2) && (c == 3))
                        flag++;
                    if ((d == 4) && (b == 3))
                        flag++;
                    if ((a == 1) && (c == 4) && (d == 2) && (b == 3))
                        flag++;
                    if (flag == 1)
                    {
                        cout << "鄱阳湖：" << a << endl;
                        cout << "洞庭湖：" << b << endl;
                        cout << "太湖：" << c << endl;
                        cout << "洪泽湖：" << d << endl;
                        return 0;
                    }
                    else
                        continue;
                }
                continue;
            }
            continue;
        }
*/
}