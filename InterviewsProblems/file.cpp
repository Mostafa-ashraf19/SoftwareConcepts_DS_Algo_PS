#include <bits/stdc++.h>
using namespace std;

class Base
{
private:
    /* data */
public:
    Base(/* args */) {
        std::cout << "Base1\n";
    }
    ~Base() {
        std::cout << "~Base1\n";
    }
};

class Base2
{
private:
    /* data */
public:
    Base2(/* args */) {
        std::cout << "Base2\n";
    }
    ~Base2() {
        std::cout << "~Base2\n";
    }
};

class Derived : public Base, public Base2
{
private:
    /* data */
public:
    Derived(/* args */) {
        std::cout << "Derived\n";
    }
    ~Derived() {
        std::cout << "~Derived\n";
    }
};

int main() {


    Derived d;


    int x, y, z;

    x = 5;
    y = ++x * x--;
    z = ++y + --y;

    std::cout << x << y << z << '\n';

    return 0;
}