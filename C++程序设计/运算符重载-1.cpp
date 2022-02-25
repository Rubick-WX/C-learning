#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
class Complex
{
private:
    double r, i;

public:
    void Print()
    {
        cout << r << "+" << i << "i" << endl;
    }
    // 在此处补充你的代码
    Complex(double real=0.0, double imag=0.0);
    Complex& operator=(const char *);
    
};
Complex::Complex(double real,double imag):r(real),i(imag){}

Complex& Complex::operator=(const char *ptr)
{


    int mid;
    int length = strlen(ptr);

    for (int i = 0; *(ptr + i) != '\0'; i++)
    {
        if (*(ptr + i) == '+')
            mid = i;
    }
    char *preal = new char[mid];
    char *pimag = new char[length - mid - 2];

    for (int i = 0; *(ptr + i) != '+'; i++)
    {
        *(preal + i) = *(ptr + i);
    }

    for (int i = mid + 1; *(ptr + i) != 'i'; i++)
    {
        *(pimag + i - mid - 1) = *(ptr + i);
    }
    r = (double)atof(preal);
    i = (double)atof(pimag);
    delete[] preal;
    delete[] pimag;
    return *this;
}

int main()
{
    Complex a,b;
    b=a = "3+4i";
    
    b.Print();

    a = "5+6i";
    a.Print();
    return 0;
}