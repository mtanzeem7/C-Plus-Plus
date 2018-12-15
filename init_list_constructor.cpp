#include <iostream>

using namespace std;

class A{
    
    public:
    int a;
    A(int x):a(x){
        std::cout << "a : " << a << std::endl;
    }
};

class B: public A{
    public:
    int b;
    B(int y=9):A(y),b(y){
        cout<<"b : "<<b<<endl;
    }
};

int main(){
    B b;
    
    return 0;
}