#include<iostream>
using namespace std;

void swap(int a, int x, int y) {
	int t = x;
	x = y;
	y = t;
}

void main() {
	int *a;
	int A;
	int left=0, right=4;
	a = (int*)malloc(sizeof(int) * 5);
	cin >> A;
	for (int i = 0; i < 5; i++)
		cin >> *(a + i);
	while (1) {
		while (*(a+left) >= A && left <= right)
			left++;
		while (*(a+right) < A && left < right)
			right--;
		if (left < right)
			swap(a[left], a[right]);
		else break;
	}
	int s = 0;
	for (int i = left; i < 5; i++)
		s += a[i];
	cout << s;
	free(a);
}