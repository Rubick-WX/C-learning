#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int a[1000];

	for (int i = 0; i < 1000; i++)
	{
		a[i] = rand()%2000;
	}

	for (int j = 1; j <= 1000; j++)		//�ӵ�һ������ʼ�����
	{
		for (int i = 0; i < 1000 - j; i++)	//�ȵ���i����
		{
			if (a[i] > a[i + 1])
			{
				int t = a[i + 1];
				a[i + 1] = a[i];
				a[i] = t;
			}
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		cout << a[i]<<	"��"<<i<<"������"<< endl;
	}

	return 0;
}