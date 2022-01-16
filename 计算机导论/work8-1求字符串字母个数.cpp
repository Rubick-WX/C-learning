//输入一行字符串（字符串中可能有空格，请用cin.getline(s,counts)
//方法把一行字符串输入到字符数组s中，其中counts是s的最大长度，
//这道题里面可以直接写80。），字符串长度小于80个字符。
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