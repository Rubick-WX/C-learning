//A-Z 65-90
//a-z 97-122


#include<iostream>
using namespace std;

int main() {
	char a[50], b[50];
	cin.getline(a, 50);
	cin.getline(b, 50);
	int i = 0;
	for ( i = 0; a[i] != '\0'; i++) {	//û��Ҫ�ں�b�ǲ��ǽ����ַ�����Ϊ����a!=b���Զ�ֹͣ��
		if (a[i] != b[i]) {
			int flag = (int)a[i] - (int)b[i];
			if (((int)a[i] <= 122 || (int)a[i] >= 97) && flag == 32)
				continue;
			if (((int)b[i] <= 122 || (int)b[i] >= 97) && flag == -32)
				continue;
			if (flag > 0){
				cout << '>' << endl;
				return 0;
			}
			else {
				cout << '<' << endl;
				return 0;
			}
		}
	}
	cout << i;
	//�����ַ���a�ĵף������ǽ����ַ������ַ�����ȣ���֮��a[i]=\0=0��Ȼ��b[i]С��
	if (a[i] == b[i] )
		cout << '=' << endl;
	else
		cout << '<' << endl;
	return 0;
}