#include<iostream>
using namespace std;
void main() {
	int N;
	float k;
	while (1) {
		cin >> N >> k;
		float s;
		bool can=1;
		s = 200.0;
		int t = 1;//��һ�귿��200��
		while (N * t < s) {
			if (N < s * k / 100.0) {//�����ʸ����Ϸ����Ƿ�
				can = 0;
				break;
			}
			s *= (100.0 + k) / 100.0;
			cout << s << "   ";
			t++;
		}
		if (can)
			cout << "��л���͹��ң���ֻҪ" << t << "�겻�Բ��Ⱦ��������" << endl;
		else
			cout << "�������ˣ�һ����Ҳ�����ˣ�С����   "<<t << endl;
	}
}