#include<iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	if (a == 3 || a == 1 || a == 5)
		cout << "OK，没问题！";
	else if (a > 0 || a < 8)
		cout << "我觉得不行。";
	else
		cout << "你这日子就不对劲。";

	return 0;
}

/*参考答案
#include <iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a == 1 || a == 3 || a == 5)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}
//这道题比较简单啦，和A+B是一个级别的，看懂应该没什么问题。
*/