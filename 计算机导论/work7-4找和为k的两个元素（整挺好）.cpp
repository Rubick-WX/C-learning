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
	return right;//���������ȫ��0����0�ֿ飬
						//�ᵼ��right������leftһֱ���ҵ�right�����ǲ���ͣ����
						//����left=right+1=n���������鷶Χ��
}

void swap(int a, int x, int y) {
	int t = x;
	x = y;
	y = t;
}

int main() {
	int n, s;
	cin >> n>>s;//Ҫ�伸���������ߺ͵�����ʲô��
	int* a;
	a = (int*)malloc(sizeof(int) * n);
	for (int i=0; i < n; i++)
		cin >> *(a + i);
	int zero = block(a, 0, 0, n - 1);//���������ֿ飺��-��
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout <<zero<< endl;


	if (s > 0) {//�������������1.����С��s��������2.һ������s����+������
		int now1 = block(a, s, 0, zero-1);//��sΪ����ֿ飬now1ָ��С��s��������߶��Ǵ�������������ұ߶���С������
		for (int i = 0; i < n; i++)
			cout << a[i] << "  ";
		cout <<now1<< endl;
		//��������һ������now1�ұ��������������С��s���������
			for (int i = now1; i < zero-1 /*&& flag == 0*/; i++) {
				//bool flag = 0;
				for (int j = i + 1; j < zero; j++) {
					if (a[i] + a[j] == s) {
						cout << "yes   "<<a[i]<<"+"<<a[j]<<endl;
						return 0;
					}
				}
			}

			//�����һ������now1��ߣ�˵����һ������s�����Ӹ���
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
		int now2 = block(a, s, zero, n - 1);//��sΪ����ֿ飬now1ָ��С��s��������߶��Ǵ�������������ұ߶���С������
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