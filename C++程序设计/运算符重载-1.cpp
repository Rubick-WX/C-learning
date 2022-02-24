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
    Complex operator=(char *);
    Complex(double real = 0, double imag = 0) : r(real), i(imag) {}
};

Complex Complex::operator=(char *ptr)
{
    
    double r, i;
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
    double real = (double)atof(preal);
    double imag = (double)atof(pimag);
    delete[] preal;
    delete[] pimag;

    return Complex(real,imag);
}

int main()
{
    Complex a;
    a = "3+4i";
    a.Print();
    
    a = "5+6i";
    a.Print();
    return 0;
}