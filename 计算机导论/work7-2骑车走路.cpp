#include<iostream>
using namespace std;
void choose(int a) {
	float t1,t2;
	t1 = a / 3.0 + 27 + 23;
	t2 = a / 1.2;
	if (t1 > t2)
		cout << "walk   "<<t1<<"   "<<t2<<endl;
	else if (t1 < t2)
		cout << "bike   " << t1 << "   " << t2 <<endl;
	else
		cout << "all   " << t1 << "   " << t2 <<endl;
}

void main() {
	int n,a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		choose(a);
	}
}