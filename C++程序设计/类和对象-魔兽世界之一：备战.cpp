#include <iostream>
using namespace std;

class headquarter{
    

public:
    string kind[5];
    int warriors_count[5] = {0, 0, 0, 0, 0};
    //dragon_count=0,ninja_count=0,iceman_count=0,lion_count=0,wolf_count=0;
    int all_count=0;
    int warriors_hp[5];
    double hp_cell;
    int finish=0;

    headquarter(double M):hp_cell(M),all_count(0){}
    
};

/*
class dragon{

    double hp;
    double atk;
};

class ninja{

    double hp;
    double atk;
};

class iceman{

    double hp;
    double atk;
};

class lion{

    double hp;
    double atk;
};

class wolf{

    double hp;
    double atk;
};
*/
void add(char (&a)[4],int i){
    int n = atoi(a);
    n += i;
    a[0] = (int)(n / 100+'0');
    a[1] = (int)((n % 100) / 10+'0');
    a[2] = (int)(n % 10+'0');
}

int main() {
    int num_case;

    headquarter red(0), blue(0);
    char time[4] = "000";





    cout<< "输入case个数：";
    cin >> num_case;
    cout << endl;

    for (int i=0;i<num_case;i++){
        double hp_cell;
        double hp[5];

        cout << "输入司令部生命元：";
        cin >> hp_cell;
        cout << endl;
        red.hp_cell = hp_cell;
        blue.hp_cell = hp_cell;

        cout << "输入dragon、ninja、iceman、lion、wolf的初始生命值：";
        for (int j = 0;j<5;j++){
            cin >> hp[j];
        }

        cout << "Case:1" << endl;

        //指挥部的生产序列没有规律，是硬性规定，所以直接用以下来规定
        //要做的就是按一个生产序列012345来规定好战士的血量和名字，让其可以根据序列号i顺序输出。
        red.warriors_hp[0] = hp[2];
        red.warriors_hp[1] = hp[3];
        red.warriors_hp[2] = hp[4];
        red.warriors_hp[3] = hp[1];
        red.warriors_hp[4] = hp[0];
        red.kind[0] = "iceman";
        red.kind[1] = "lion";
        red.kind[2] = "wolf";
        red.kind[3] = "ninja";
        red.kind[4] = "dragon";

        blue.warriors_hp[0] = hp[3];
        blue.warriors_hp[1] = hp[0];
        blue.warriors_hp[2] = hp[1];
        blue.warriors_hp[3] = hp[2];
        blue.warriors_hp[4] = hp[4];
        blue.kind[0] = "lion";
        blue.kind[1] = "dragon";
        blue.kind[2] = "ninja";
        blue.kind[3] = "iceman";
        blue.kind[4] = "wolf";

        
        for (int i = 0;i<=5;i++){
            if(i==5)
                i = 0;
            

            if(red.hp_cell>red.warriors_hp[i]){
                red.hp_cell -= red.warriors_hp[i];
                red.all_count++;
                red.warriors_count[i]++;
                cout << time << " red " << red.kind[i] << " " << red.all_count << " with strength " << red.warriors_hp[i] << "," << red.warriors_count[i] << " " << red.kind[i] << " in red headquarter" << endl;
            }else{
                if(red.finish==0){
                    cout << time << " red headquarter stops making warriors"<<endl;
                    red.finish = 1;
                }
            }

            if(blue.hp_cell>blue.warriors_hp[i]){
                blue.hp_cell -= blue.warriors_hp[i];
                blue.all_count++;
                blue.warriors_count[i]++;
                cout << time << " blue " << blue.kind[i] << " " << blue.all_count << " with strength " << blue.warriors_hp[i] << "," << blue.warriors_count[i] << " " << blue.kind[i] << " in blue headquarter" << endl;
            }else{
                if(blue.finish==0){
                    cout << time << " blue headquarter stops making warriors"<<endl;
                    blue.finish = 1;
                }
            }

            if(red.finish==1&&blue.finish==1)
                break;
            else
                add(time,1);
        }
        
    }
       

            return 0;
}