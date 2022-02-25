#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2
{
    int size_hang;
    int size_lie;
    int *p;
    int dimension;
    int hang, lie;

public:
    Array2(int size_h = 0, int size_l = 0) : hang(0), lie(0),dimension(0),size_hang(size_h),size_lie(size_l)
    {
        p = new int[size_hang * size_lie];
    }
    ~Array2() { delete[] p; }

    Array2 &operator[](int i);

    // int operator()(int);
    Array2 &operator=(int);
    Array2 &operator=(const Array2 &);
    int operator()(int, int);
    friend ostream &operator<<(ostream &a,Array2 &b);
};

ostream& operator<<(ostream&a,Array2 &b){
    cout << *(b.p + b.size_lie * b.hang + b.lie);
    b.dimension = 0;
    return a;
}



Array2 &Array2::operator[](int i)
{
    //每用一次[]，则维度+1

    dimension++;

    if (dimension == 1)
        lie = i;
    else if (dimension == 2)
    {
        hang = lie;
        lie = i;
    
    }else
        cout << "你输入维度有问题啊！" << endl;
    //用了两次[]后，则dimension==2，注意此时Array2类对象的使用情况
    //现在看来有两种使用[][]的情况：
    //1.a[][]=：用来赋值
    //2.cout<<a[][]：用来输出
    //每次用完[][]后记得把dimension=0，否则后续再次[]会出错。
    return *this;
}

Array2 &Array2::operator=(int i)
{
    *(p + size_lie * hang + lie) = i;
    dimension = 0;
    return *this;
}

Array2 &Array2::operator=(const Array2 &i)
{
    if (p == i.p)
        return *this;
    if (i.p)
    {
        if (p)
            delete[] p;
        p = new int[i.size_hang * i.size_lie];
        size_hang = i.size_hang;
        size_lie = i.size_lie;
        for (int j = 0; j < i.size_hang * i.size_lie; j++)
            *(p + j) = *(i.p + j);
    }
    else
        p = NULL;

    return *this;
}

int Array2::operator()(int h, int l)
{
    return *(p + size_lie * h + l);
}

int main()
{
    Array2 a(3, 4);

    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;


    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}