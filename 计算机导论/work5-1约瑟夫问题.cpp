#include<iostream>
using namespace std;
int main() {
	int n,m,a[300];
    while (true) {
        cin >> n >> m;
        int num = n;	//记录剩余猴子个数
        for (int i = 0; i < n + 1; i++)//猴子编号
            a[i] = i;
        int current = 0;
        while (true) {
            while (num > 1) {	//当剩一只猴，停止运行
                //数m只猴，如果计数i超过范围，指到数组第一位。每数一只猴，i加1.
                for (int count = 0; count < m;) {
                    count++;
                    current++;
                    if (current > num) {
                        current = 1;
                    }
                }
                //可能出现第m个值刚好超过剩余猴子个数t，停止执行判断i在数组外
                //但i刚好指到数组外，没有回归数组第一个值

                for (int k = current; k < num; k++)
                    a[k] = a[k + 1];

                num--;//数完m个，剔除一只猴

                if (current > num) {
                    current = 1;
                }
                if (num > 1)
                    current--;
            }
            cout << a[current]<<endl;
            break;
        }
    }
    return 0;
}



/*
#include<iostream>
using namespace std;

//一共最多有300只猴子
int succedent[300]; //这个数组用于保存一个猴子后一位是谁，
      //比如“next[5]的值是7”就是说5号猴子的下一位是7号猴子，6号猴子已经在之前退出了。
int precedent[300];//这个数组用于保存一个猴子前一位是谁，用法和上面的类似。

int main() {
  int n, m;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    for (int i = 0; i < n - 1; i++) {
      succedent[i] = i + 1;
      precedent[i + 1] = i;
    }
    succedent[n - 1] = 0;
    precedent[0] = n - 1;

    int current = 0;
    while (true) {
      //如果一共要报m次号，那么取m-1次succedent之后就是需要退出的那只猴子
      for (int count = 0; count < m-1; count++)
        current = succedent[current];

      int pre = precedent[current];
      int suc = succedent[current];
      //让current号猴子退出很简单，就是把前一位的“下一位”指向current的下一位，
      //下一位的“前一位”指向current的前一位就好了
      succedent[pre] = suc;
      precedent[suc] = pre;
      if (pre == suc) {
        //如果只剩下两个了，那么每个人的前位和后位就是同一个了。
        //current是退出的，那么另一个就是剩下的。
        //我们的序号是从0编号的，输出时要加一
        cout << pre+1 << endl;
        break;
      }
     current = suc;//去除了一只猴，current自然调到剔除猴后面那只了。
    }
  }
  return 0;
}
*/