//A-Z 65-90
//a-z 97-122


#include<iostream>
using namespace std;

int main() {
	char a[50], b[50];
	cin.getline(a, 50);
	cin.getline(b, 50);
	int i = 0;
	for ( i = 0; a[i] != '\0'; i++) {	//没必要在乎b是不是结束字符，因为，若a!=b在自动停止，
		if (a[i] != b[i]) {
			int flag = (int)a[i] - (int)b[i];
			if (((int)a[i] <= 122 || (int)a[i] >= 97) && flag == 32)
				continue;
			if (((int)b[i] <= 122 || (int)b[i] >= 97) && flag == -32)
				continue;
			if (flag > 0){
				cout << '>' << endl;
				return 0;
			}
			else {
				cout << '<' << endl;
				return 0;
			}
		}
	}
	cout << i;
	//到达字符串a的底，若都是结束字符，则字符串相等，反之则a[i]=\0=0必然比b[i]小；
	if (a[i] == b[i] )
		cout << '=' << endl;
	else
		cout << '<' << endl;
	return 0;
}