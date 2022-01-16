#include <iostream>
using namespace std;
class A {
public:
    char val3;
    int val;
    int val2;
    
    // 在此处补充你的代码
    A(int n = 0) { 
        val = n;
        val2 = n;
        val3 = 'N';
    }

    A &GetObj()
    {
        return *this;
}
};
int main(){
    A a;
    A *p = &a;
    cout << a.val <<a.val2<<a.val3<< endl;
    a = 1;
    //我发现当类有公有成员参数时，可以在主函数内用类的对象直接=...。
    //如果成员变量是int和char，如果对象a=int b，那么a的所有int变量被赋值b，char不变；
    //如果对象a=char 'c'，那么a所有int变量被赋值字符c的ASCII值，char被赋值'c'。
    cout << a.val <<a.val2<<a.val3<< endl;
    return 0;
}


