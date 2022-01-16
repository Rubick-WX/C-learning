#include<iostream>
#include<iomanip>

using namespace std;

struct DNA{
    char a[255];
    char b[255];
};

int main(){
    int num=5;
    DNA s[10]={"ATATGGATGGTGTTTGGCTCTG","","TCTCCGGTTGATT","","ATATCTTGCGCTCTTGATTCGCATATTCT","","GCGTTTCGTTGCAA","","TTAACGCACAACCTAGACTT",""};

    int i = 1;
    while(i<=5){
        for (int j=0;s[i-1].a[j]!='\0';j++){
            if(s[i-1].a[j]=='A')
                s[i - 1].b[j] = 'T';
            if(s[i-1].a[j]=='T')
                s[i - 1].b[j] = 'A';
            if(s[i-1].a[j]=='G')
                s[i - 1].b[j] = 'C';
            if(s[i-1].a[j]=='C')
                s[i - 1].b[j] = 'G';
        }
        cout << s[i - 1].b << endl;
        i++;
    }


}