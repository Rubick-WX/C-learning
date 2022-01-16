#include<iostream>
using namespace std;

int main(){
    double all_cost=0;
    double A_cost=0;
    double B_cost=0;
    double C_cost=0;
    int id;
    int num;
    char one_kind;
    double cost;
    double one_cost[4]={0};
    int i = 1;
    while(i<=3){
        cout << "输入id和发票数：" << endl;
        cin >> id >> num;
        int j = 1;
        cout << "输入票种类和金额：" << endl;
        while(j<=num){
            cin >> one_kind >> cost;
            if(one_kind=='A'){
                A_cost += cost;
                one_cost[j] += cost;
            }
            if(one_kind=='B'){
                B_cost += cost;
                one_cost[j] += cost;
            }
            if(one_kind=='C'){
                C_cost += cost;
                one_cost[j] += cost;
            }  
             
            j++;
        }
        i++;
    }
    all_cost = A_cost + C_cost + B_cost;
    cout << "一号的金额为：" << one_cost[1] << endl;
    cout << "二号的金额为：" << one_cost[2] << endl;
    cout << "三号的金额为：" << one_cost[3] << endl;
    cout << "A票金额为：" << A_cost << endl;
    cout << "B票金额为：" << B_cost << endl;
    cout << "C票金额为：" << C_cost << endl;
    cout << "总金额为：" << all_cost << endl;
    return 0;
}