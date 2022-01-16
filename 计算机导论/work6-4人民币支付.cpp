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
			cout << "100¿é£º" << a << endl;
			s = s - a * 100;

			a = s / 50;
			cout << "50¿é£º" << a << endl;
			s = s - a * 50;

			a = s / 20;
			cout << "20¿é£º" << a << endl;
			s = s - a * 20;

			a = s / 10;
			cout << "10¿é£º" << a << endl;
			s = s - a * 10;

			a = s / 5;
			cout << "5¿é£º" << a << endl;
			s = s - a * 5;
			cout << "1¿é£º" << s << endl;
		}
	}
}