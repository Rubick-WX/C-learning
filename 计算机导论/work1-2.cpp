#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

int main(){

	int a[10];//= {1,15,63,73,51,37,51,18,90,100};

//����10���������
for (int i=0;i<10;i++) {
	a[i] = rand()%100;
}

//������ǰ��ż���ں��ٷֱ�����
for (int j=1;j<=10;j++) {
	for (int i=0;i<10-j;i++) {
		//�����ż-���򽻻�
		if (a[i] % 2 == 0 && a[i + 1] % 2 != 0) {
			int t = a[i + 1];
			a[i + 1] = a[i];
			a[i] = t;
			continue;
		}
		//�������-ż������
		if (a[i] % 2 != 0 && a[i + 1] % 2 == 0)
			continue;

		//������������żż�ͱȽϴ�С
		if (a[i] > a[i + 1]) {
			int t = a[i + 1];
			a[i + 1] = a[i];
			a[i] = t;
		}
	}
}

for (int i = 0; i < 10; i++)
{
	cout  << "��" << i+1 << "������:" << a[i] <<endl;
}
	return 0;
}