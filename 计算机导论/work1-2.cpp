#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

int main(){

	int a[10];//= {1,15,63,73,51,37,51,18,90,100};

//导入10个随机整数
for (int i=0;i<10;i++) {
	a[i] = rand()%100;
}

//奇数在前，偶数在后，再分别排序
for (int j=1;j<=10;j++) {
	for (int i=0;i<10-j;i++) {
		//如果是偶-奇则交换
		if (a[i] % 2 == 0 && a[i + 1] % 2 != 0) {
			int t = a[i + 1];
			a[i + 1] = a[i];
			a[i] = t;
			continue;
		}
		//如果是奇-偶就跳过
		if (a[i] % 2 != 0 && a[i + 1] % 2 == 0)
			continue;

		//如果是奇奇或者偶偶就比较大小
		if (a[i] > a[i + 1]) {
			int t = a[i + 1];
			a[i + 1] = a[i];
			a[i] = t;
		}
	}
}

for (int i = 0; i < 10; i++)
{
	cout  << "第" << i+1 << "个数字:" << a[i] <<endl;
}
	return 0;
}