#include<iostream>
using namespace std;

void main() {
	int s;
	while (1) {
		cin >> s;
		int a;
		if (!s)
			break;
		else {
			a = s / 100;
			cout << "100�飺" << a << endl;
			s = s - a * 100;

			a = s / 50;
			cout << "50�飺" << a << endl;
			s = s - a * 50;

			a = s / 20;
			cout << "20�飺" << a << endl;
			s = s - a * 20;

			a = s / 10;
			cout << "10�飺" << a << endl;
			s = s - a * 10;

			a = s / 5;
			cout << "5�飺" << a << endl;
			s = s - a * 5;
			cout << "1�飺" << s << endl;
		}
	}
}