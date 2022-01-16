#include<iostream>
#include <iomanip>
using namespace std;
int main() {
	int n;
	int a[100];
	int n1=0, n2=0, n3=0, n4=0;
	while (true) {
		cin >> n;
		//for(int i=0;i<n;i++)
			//cin >> a[i];
		int num = n;
		while (n--) {
			cin >> a[n];
		}
		while (true) {
			for (int i = 0; i < num; i++) {
				if (a[i] >= 0 && a[i] < 19)
					n1++;
				else if (a[i] > 18 && a[i] < 36)
					n2++;
				else if (a[i] > 35 && a[i] < 61)
					n3++;
				else if (a[i] > 60)
					n4++;
				else
					cout << "年龄数据错误" << endl;
			}
			cout << "18以下：" << fixed << setprecision(2)<< (double)n1/num*100 << "%"<<endl;
			cout << "19-35：" << fixed << setprecision(2) <<(double)n2 / num*100 << "%"<<endl;
			cout << "36-60：" << fixed << setprecision(2) <<(double)n3 / num*100 << "%" << endl;
			cout << "60以上：" << fixed << setprecision(2) <<(double)n4 / num*100 << "%" << endl;
			break;
		}
	}
	return 0;
}