#include "iostream"
#include "memory"

class A{
public:
    A(){};
    virtual ~A(){}
};

class B: public A{
public:
    int a;
    int b;
    float c;

    B(int a, int b):a(a), b(b), c(2.1){}
    B(){}
    ~B(){std::cout << "B destroyed " << a << std::endl;}
};


class C: public A{
public:
    static constexpr float e = 0.1;
    int a;
    int b;
    float d;

    C():a(11), b(12), d(3.1){}
};

int main(){
    {
        B* b  = new B();
        delete b;
    }
    // {
    // }
    std::cout << "after context\n";
    return 0;
}