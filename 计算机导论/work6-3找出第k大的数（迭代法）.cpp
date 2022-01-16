#include<iostream>
using namespace std;

float pickclass(float a[],int k,int left,int right) {
    float now = a[left];
    int L = left, R = right;//搜寻边界
    while (1) {
        while (now<=a[left]&&left<=right) //left遇到小数停下
            left++;
        while (now > a[right]&&right>left)//right遇到大数停下
            right--;
        if (left < right)
            swap(a[left], a[right]);
        else break;
    }
    //>now的数：大数；<now的数：小数
    //最后left总会指到小数处，左边的数都是大数。
    //情况一：left先动，right一直在R处不动。right没判定是大数还是小数，left可能一路跑到L+1处停下，那么right本身就在大数处
    //情况二：left移动到小数，left左边是大数；right移动到大数，右边是小数。交换后left是大数，right是小数。
    //情况三：上一次交换，right在小数。left新一轮开始动，left不可能通过right，因为right在小数上，left会在right处停下。而right==left则right不可能动。

    swap(a[L], a[left-1]);//这下left-1指向的是now值了。结果为（<now,=now(left-1),>now）

    if (left - 1 - L >= k)//大于数个数大于等于k，继续在左边找
        return pickclass(a, k, L, left - 2);
    else if (left - 1 - L < k - 1)//大于数个数小于k，,已经找出left-1-L+1个大于数了,要再右边找
        return pickclass(a, k - (left - 1 - L + 1), left, R);
    else
        return now;
}

void swap(float a, float b) {
    float t = b;
    b = a;
    a = t;
}







void main() {
    float a[10] = {10,9,8,7,6,5,4,3,2,1};
    int k;
    int left=0, right=9;
    cin >> k;
    cout << pickclass(a, k, left, right) << endl;

}












/*

float find(float a[], int k, int left, int right)
{
    float e = a[left];
    int l = left, r = right;

    while (1)
    {
        while (a[left] >= e && left <= right) left++;
        while (a[right]<e && right>left) right--;
        if (right > left)
            swap(a + left, a + right);
        else break;//停止时，简举下几种情况：第一种，下标为left的数比e小 且右侧有数；第二种，left直接到滚到最后超出最后的值为right+1
        //第一次交换left和right交换后，会继续往后跑，直到right<=left，才会跳出循环。
        //最终结果就是：（e-比e大的数-right-left-比e小的数）
    }

   swap(a + l, a + left - 1);//为什么减一参考else break哪里的注释
    if ((left - 1 - l) >= k)//交换后 e所在位置为left-1,减去第一个数所在位置l即为比e大的数的个数，这里不要等同于数学计算里的加减
    //也可以这样想得出left-1-l的原因，比e旁边的数下标为left-2，减去第一个数的下标l,但还要加一，因为l本身也要算进去。然后就是 left-2-l+1，最后化简就是left-1-l
    //讲道理，left-1-l=比e大的数个数，但是要求第k大，则要求比其大的个数为k-1
        find(a, k, l, left - 2);    //如果大于个数>=k，则继续从左边取
    else if ((left - 1 - l) < k - 1)    //如果大于个数<k，则从右边取
        find(a, k - left + l, left, r);//k-left+1是这个式子得来的 k-(left-1-l)-1，left-1-l是比e大的个数，1是e本身，例：你原本是第三，减去一个比第二大的个数1，再减去第二，不就是 3-1-1=1？
    else return e;
}
*/