#include<iostream>
using namespace std;
int main() {
	int N;
	cout << "���10���ϵ�����";
	cin >> N;

	
	for (int n = 10; n <= N;n++) {
		int m = 0;
		int s = n;
		while (s / 10) {
			m += s % 10;
			s /= 10;
		}
		m += s;
		if (n % m == 0)
			cout << n << "  ";
	}
	return 0;
}