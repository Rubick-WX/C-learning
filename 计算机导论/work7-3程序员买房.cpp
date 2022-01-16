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
		int t = 1;//第一年房价200万
		while (N * t < s) {
			if (N < s * k / 100.0) {//当工资跟不上房价涨幅
				can = 0;
				break;
			}
			s *= (100.0 + k) / 100.0;
			cout << s << "   ";
			t++;
		}
		if (can)
			cout << "感谢党和国家，我只要" << t << "年不吃不喝就买得起房了" << endl;
		else
			cout << "别挣扎了，一辈子也买不起了，小伙子   "<<t << endl;
	}
}