//����һ���ַ������ַ����п����пո�����cin.getline(s,counts)
//������һ���ַ������뵽�ַ�����s�У�����counts��s����󳤶ȣ�
//������������ֱ��д80�������ַ�������С��80���ַ���
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	char list[100];
	cin.getline(list,100);
	int a=0, e=0, i=0, o=0, u = 0;
	for (int i = 0; list[i] != '\0'; i++) {
		switch (list[i]) {
		case 'a':
			a++;
			break;
		case 'e':
			e++;
			break;
		case 'i':
			i++;
			break;
		case 'o':
			o++;
			break;
		case 'u':
			u++;
			break;
		}
	}
	cout << setw(5) << a << setw(5)<< e << setw(5)<< i << setw(5)<< o << setw(5)<<u << endl;
	return 0;
}