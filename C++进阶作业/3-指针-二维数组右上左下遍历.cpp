#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int array[100][100]={{1 ,2 ,4 ,7},{3 ,5 ,8 ,10},{6 ,9 ,11,12}};
    int x=3, y=4;

    int *p[100];

    /*for (int k = 1;k<=x+y-1;k++)
        int i=, j;
        while()
        *(p + i) + len - i;*/

    for (int i = 0;i<x+y-1;i++){
        int m = i;
        int n= 0;
        if(m>=y-1){
            n += m - (y - 1);
        }
        
        while(n<x&&i-n>=0){
            cout << array[n][i-n]<<endl;
            n++;
        }
    }

        return 0;
}