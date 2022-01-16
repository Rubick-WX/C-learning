#include<iostream>
using namespace std;
int main() {
	char a[50];
	while (cin >> a) {
		int max = 0;
		int i = 0;
		while (a[i] != ' ') {
			i++;
		}
		if (i > max)
			max = i;
		//cout << max<<endl;
		cout << a[i];
	}
}