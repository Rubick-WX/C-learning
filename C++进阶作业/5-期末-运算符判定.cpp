#include<iostream>
#include<iomanip>

using namespace std;

string compute(int a,int b,int c){
    
    if(a+b==c)
        return "+";
    else if(a-b==c)
        return "+";
    else if(a/b==c)
        return "+";
    else if(a*b==c)
        return "+";
    else if(a%b==c)
        return "+";
    else
        return "error";
}

int main(){
    int a, b, c;
    cout << "两个操作数和结果数：";
    cin >> a >>b>>c;
    //cin.get();
    //cout<<endl;

    cout << compute(a, b, c) << endl;
    

    return 0;
}