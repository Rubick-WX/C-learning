#include<iostream>
#include<iomanip>

using namespace std;

struct patient{
    int id;
    double condition;
};

//遇到小-大，换位，适用于降序排列。
void swap(patient *a,patient *b){
    patient *temp;
    temp = b;
    b = a;
    a = temp;
}

int main(){
    patient a[50]={
    6, 6.5,
    5 ,8.0,
    4,3.5,
    9,8.5,
    11,7.0,
    43,9.5,
    3,5.0,
    103,6.0,
    112,4.0,
    118 ,9.0};

    double threshold=7.55;
    int num=10;

    int left = 0, right = num - 1;
    while(1){
        while(a[left].condition>=threshold&&left<=right)
            left++;
        while(a[right].condition<threshold&&left<right)
            right--;
        if(left<right)
            swap(a[left], a[right]);
        else
            break;
    }

    if(left==0)
        cout << "你莫不是消遣洒家？" << endl;

    for (int i=0;i<left-1;i++){
        for (int j=0;j<left-1-i;j++){
            if(a[j].condition<a[j+1].condition)
                swap(a[j], a[j + 1]);
        }
    }

    for (int i = 0;i<left;i++)
        cout << setw(3)<< a[i].id << " " <<setw(3)<< a[i].condition << endl;
    
    return 0;
}