#include <bits/stdc++.h>
using namespace std;

class Base
{
private:
    /* data */
public:

int x;
    // Base(/* args */);
    // ~Base();
    // void print()
    virtual void print()
    {
        std::cout << "Hi from Base\n";
    }
};

// Base::Base(/* args */)
// {
// }

// Base::~Base()
// {
// }

class Child : public Base
{
private:
    /* data */
public:
int y;
    void print()
    {
        std::cout << "Hi from Child\n";
    }
    // Child(/* args */);
    // ~Child();
};

// Child::Child(/* args */)
// {
// }

// Child::~Child()
// {
// }

int main(int argc, char **argv)
{

    Base* b = new Child();
    // b->print();
    // b.print();
    dynamic_cast<Child*>(b)->y = 4;

    b->print();

    b->x = 45;
    std::cout << b->x <<  "  " << static_cast<Child*>(b)->y << '\n';
    // static_cast<Child*>(b)->print();

    return 0;
}