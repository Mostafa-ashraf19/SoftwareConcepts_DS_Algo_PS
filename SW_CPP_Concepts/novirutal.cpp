#include <iostream>
#include <string>

using namespace std;

class A
{
private:
    /* data */
public:
    A() {
        cout << "A\n";
    }
    void  display() {
        cout << "Hi A\n";
    }
    ~A() {}
};

class B : public A
{
private:
    /* data */
public:
    B() {
        cout << "B\n";
    }
    void display() {
        cout << "Hi B\n";
    }
    ~B() {}
};




int main() {

    A* a = new B();
    a->display();
    
    // float x = 3.2;
    // double y = 3.2;

    // if(x==y) {
    //     cout << "Hi\n";
    // } else {
    //     cout << "OKKK\n";
    // }

    return 0;
}