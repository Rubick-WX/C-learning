#include<iostream>
using namespace std;

void jiaogu(int n){
    if(n==1)
        cout << "End" << endl;
        else if (n%2)
        {
            cout << n << "*3+1=";
            n=n * 3 + 1;
            cout << n << endl;
            jiaogu(n);
        }
        else{
            cout << n << "/2=";
            n /= 2;
            cout << n << endl;
            jiaogu(n);
        }
        
}

int main(){
    int n;
    cin >> n;
    jiaogu(n);
}
