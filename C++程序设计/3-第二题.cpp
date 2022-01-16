#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) {
        
    }
    Sample(const Sample &n);
    // 这里涉及的知识点是复制构造函数，涉及到Sample类的对象被当做参数调用时，
    
};
Sample::Sample(const Sample &n):v(n.v+5){}

int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}