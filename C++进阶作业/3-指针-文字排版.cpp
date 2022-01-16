#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    char a[40];
    char *b=new char[81];
    int num;
    cout << "输入单词个数：";
    cin >> num;
    cin.get();
    cout << endl;

    int k=0;
    cout << "输入单词吧：";
    for (int i = 1,len=80;i<=num;i++){
        cin.getline(a, 40, ' ');
        int j;

        for (j = 0;a[j]!='\0';j++){} 
        j--;//单词长度
        //先预测放不放得下没有空格的单词，放得下，则后加空格，
        //再加无后空格的单词，放不下，则要换行，删除之前后加的空格，换行。
        if(len-(j+1)>1){    
            //装下纯单词还有至少2格剩余，
            //加一个空格（看看下一个单词装不装得下）
            for (int i=0;a[i]!='\0';i++){
                *(b+k)=a[i];//输入单词到b
                k++;//记录b录入单词后的位置。
            }
            *(b+k) = ' ';
            k++;
            len -= j + 2;
        }else if(len-(j+1)>=0)
        //可以装下现在的单词，但之后后只有0或者1个位置，
        //那铁定要换行了，装下单词直接换行
        //注意，当单词放入后刚好挤满80个长度时，结尾由于没有\0会出现乱码，所以设置b长度为81
        //由于我们专门设置了长度变量len，所以b的长度设置长于80都可以
        {
            for (int i=0;a[i]!='\0';i++){
                b[k]=a[i];//输入单词到b
                k++;//记录b录入单词后的位置。
            }
            cout << b << endl;
            //要清除b中内容，初始化b
            memset(b, '\0', 81);
            k = 0;
            len = 80;
        }else{
            //直接连现在单词都放不下，把之前加的空格去掉；
            //换行；
            //写入单词。
            *(b + k - 1) = '\0';
            cout << b << endl;
            memset(b, '\0', 81);
            k = 0;
            len = 80;
            for (int i=0;a[i]!='\0';i++){
                b[k]=a[i];//输入单词到b
                k++;//记录b录入单词后的位置。
            }
            *(b+k) = ' ';
            k++;
            len -= j + 2;
        }
    }


    return 0;
}
