#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main() {
	int k,a[100];
	int n1=0,n5=0,n10=0;
	int m=0;
	//����k�������������
	srand((int)time(NULL));
	cout << "���������ָ�����" << endl;
	cin >> k;
	cout << "���ɵ�����Ϊ��" << endl;
	//��ʼ������Ϊ0����
	for (int i = 0; i < 100; i++) {
		a[i]=0;
	}
	//��k�����ָ�ֵ
	for (int i = 0; i < k; i++) {
		a[i] = rand() % 10+1;		//rand()%���+start��Ҫ��start<end��
		cout << a[i] << "   ";
	}
	cout << endl;


	while ((bool)a[m]) {
/*		switch (a[m]) {
		case 1:
			n1++;
			cout << a[m]<<endl;
			break;
		case 5:
			n5++;
			cout << a[m] << endl;
			break;
		case 10:
			n10++;
			cout << a[m] << endl;
			break;
		default:
			cout << "������Ҫ��"<<endl;
		}
		m++;
		*/
		if (a[m] == 1) {
			n1++;
		}
		else if (a[m] == 5) {
			n5++;
		}
		else if (a[m] == 10) {
			n10++;
		}
		m++;
	}
	
	cout << "1���ֵĴ�����" << n1 << endl;
	cout << "5���ֵĴ�����" << n5 << endl;
	cout << "10���ֵĴ�����" << n10 << endl;









	return 0;
}

/*�ο���
#include <iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	int n1=0, n5=0, n10=0;
	for (int i=0;i<k;i++){
		int n;
		cin>>n;
		if (n == 1) n1++;
		else if (n == 5) n5++;
		else if (n == 10) n10++;
	}
	cout<<n1<<endl;
	cout<<n5<<endl;
	cout<<n10<<endl;
	return 0;
}
*/