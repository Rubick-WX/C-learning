#include<iostream>
using namespace std;

int block(int a[],int A,int L,int R) {
	int left = L, right = R;

	while (1) {
		while (*(a + left) >= A && left <= right)
			left++;
		while (*(a + right) < A && left < right)
			right--;
		if (left < right)
			swap(a[left], a[right]);
		else break;
	}
	return right;//如果数组里全是0，对0分块，
						//会导致right不动，left一直向右到right，但是不会停下来
						//最终left=right+1=n，超过数组范围。
}

void swap(int a, int x, int y) {
	int t = x;
	x = y;
	y = t;
}

int main() {
	int n, s;
	cin >> n>>s;//要输几个数？两者和的数是什么？
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	for (int i=0; i < n; i++)
		cin >> *(a + i);
	int zero = block(a, 0, 0, n - 1);//给正负数分块：正-负
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout <<zero<< endl;


	if (s > 0) {//分两种种情况，1.两个小于s的正数；2.一个大于s正数+负数。
		int now1 = block(a, s, 0, zero-1);//以s为基点分块，now1指向小于s的数，左边都是大于数，本身和右边都是小于数。
		for (int i = 0; i < n; i++)
			cout << a[i] << "  ";
		cout <<now1<< endl;
		//先找其中一个数在now1右边情况，必是两个小于s的正数相加
			for (int i = now1; i < zero-1 /*&& flag == 0*/; i++) {
				//bool flag = 0;
				for (int j = i + 1; j < zero; j++) {
					if (a[i] + a[j] == s) {
						cout << "yes   "<<a[i]<<"+"<<a[j]<<endl;
						return 0;
					}
				}
			}

			//如果第一个数在now1左边，说明是一个大于s正数加负数
			for (int i = 0; i < now1; i++) {
				for (int j = zero; j < n; j++) {
					if (a[i] + a[j] == s) {
						cout << "yes   " << a[i] << "+" << a[j] << endl;
						return 0;
					}

				}
			}
			cout << "no" << endl;
	}
	else if (s < 0) {
		int now2 = block(a, s, zero, n - 1);//以s为基点分块，now1指向小于s的数，左边都是大于数，本身和右边都是小于数。
		for (int i = 0; i < n; i++)
			cout << a[i] << "  ";
		cout <<now2<< endl;
		for (int i = zero; i < now2-1 /*&& flag == 0*/; i++) {
			//bool flag = 0;
			for (int j = i + 1; j < now2; j++) {
				if (a[i] + a[j] == s) {
					cout << "yes   " << a[i] << "+" << a[j] << endl;
					return 0;
				}
			}
		}

		for (int i = now2; i < n; i++) {
			for (int j = 0; j < zero; j++) {
				if (a[i] + a[j] == s) {
					cout << "yes   " << a[i] << "+" << a[j] << endl;
					return 0;
				}
			}
		}
		cout << "no" << endl;
	}
	else
	{
		for (int i = 0; i < zero; i++) {
			for (int j = zero; j < n; j++) {
				if (a[i] + a[j] == s) {
					cout << "yes   " << a[i] << "+" << a[j] << endl;
					return 0;
				}
			}
		}
		cout << "no" << endl;
	}
	return 0;
}