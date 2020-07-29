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
    std::shared_ptr<B> ptr;
    {
        B* b_ptr = new B(-1, 2);
        ptr.reset(b_ptr);
        std::shared_ptr<A> new_ptr = std::static_pointer_cast<A>(ptr);
        // std::shared_ptr<B> final_b_ptr = std::static_pointer_cast<B>(new_ptr);
        // std::cout << final_b_ptr->a << " " << final_b_ptr->b << std::endl;
    }
    //ptr still retains reference to the object. The object is not destroyed.
    std::cout << ptr.use_count() << std::endl;
    return 0;
}