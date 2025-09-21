#include <bits/stdc++.h>
using namespace std;


/*
Notes: 

Data members in C++ is inherited in a derived class from base class
Constructor is a member function of a class which initializes objects of a class. In C++,Constructor is automatically called when object(instance of class) create.It is special member function of the class.
Destructor is a member function which destructs or deletes an object.
Virtual methods is a method which is redefined(Over-riden) in derived class.


The [[nodiscard]] attribute is used to indicate that the return value of a function should not be ignored. If the return value is ignored (e.g., by not assigning it to a variable or using it in an expression), the compiler will issue a warning.
[[nodiscard]] return_type function_name(parameters);

Outdated or obsolete functions that need to be replaced with newer alternatives.
[[deprecated("Use newFunction() instead")]] void oldFunction() {
    // Old function code
}

The left-to-right associativity in C++ applies to the following types of operators:

Assignment operators (=, +=, -=, etc.)
Arithmetic operators (+, -, *, /, %)
Relational operators (==, !=, <, >, <=, >=)
Logical operators (&&, ||)
Bitwise operators (&, |, ^, <<, >>)
Comma operator (,)
Conditional (ternary) operator (?:)
Type casting operators
Array element access


How can we restrict dynamic allocation of objects of a class using new?
By making an empty private new and new[] operators

COUT:
cout is an object of ostream class which is a compiler defined class. 
When we do "cout << obj" where obj is an object of our class, the compiler first looks for an operator function in ostream, then it looks for a global function. 
One way to overload insertion operator is to modify ostream class which may not be a good idea. So we make a global method. 
    friend ostream & operator << (ostream &out, const Complex &c);

There are actually two things that happen in the above statement--memory allocation and object construction; 
the new keyword is responsible for both. One step in the process is to call operator new in order to allocate memory; 
the other step is to actually invoke the constructor. Operator new only allows us to change the memory allocation method, but does not do anything with the constructor calling method. 
Keyword new is responsible for calling the constructor, not operator new.



Summary of Key Pointer Concepts in C++:

Wild Pointer: A pointer that is uninitialized and points to an unknown memory location.
Null Pointer: A pointer that points to no valid memory (nullptr).
Dangling Pointer: A pointer that points to memory that has been deallocated.
Void Pointer: A generic pointer that can point to any data type, but must be cast before dereferencing.
Pointer to Pointer: A pointer that stores the address of another pointer.
Pointer Arithmetic: You can perform arithmetic on pointers, useful in arrays and other memory structures.
Smart Pointers: Modern C++ provides smart pointers (e.g., std::unique_ptr, std::shared_ptr) to manage memory automatically and prevent memory leaks.

*/

// class Base
// {
// private:
//     /* data */
// public:

// int x;
//     // Base(/* args */);
//     // ~Base();
//     // void print()
//     virtual void print()
//     {
//         std::cout << "Hi from Base\n";
//     }
// };

// // Base::Base(/* args */)
// // {
// // }

// // Base::~Base()
// // {
// // }

// class Child : public Base
// {
// private:
//     /* data */
// public:
// int y;
//     void print()
//     {
//         std::cout << "Hi from Child\n";
//     }
//     // Child(/* args */);
//     // ~Child();
// };

// Child::Child(/* args */)
// {
// }

// Child::~Child()
// {
// }

// int main(int argc, char **argv)
// {

//     Base* b = new Child();
//     // b->print();
//     // b.print();
//     dynamic_cast<Child*>(b)->y = 4;

//     b->print();

//     b->x = 45;
//     std::cout << b->x <<  "  " << static_cast<Child*>(b)->y << '\n';
//     // static_cast<Child*>(b)->print();

//     return 0;
// }




// #include<iostream>
// using namespace std;

// class Test
// {
// private:
//   int x;
// public:
//   Test() {x = 0;}
//   void destroy()  { delete this; }
//   void print() { cout << "x = " << x; }
// };

// int main()
// {
//   Test obj;
//   obj.destroy();
//   obj.print();
//   return 0;
// }

// #include<iostream>
// using namespace std;
 
// class Test
// {
// protected:
//     int x;
// public:
//     Test (int i):x(i) { }
//     // void fun() const  { cout << "fun() const " << endl; }
//     void fun()        {  cout << "fun() " << endl;     }
// };

// int main()
// {
    //     Test t1 (10);
//     const Test t2 (20);
//     t1.fun();
//     t2.fun();
//     return 0;
// }




// // There is a compiler error because static member a is not defined in B. To fix the error, we need to explicitly define a. The following program works fine.
// #include <iostream>
// using namespace std;

// class A
// {
// private:
//     int x;
// public:
//     A(int _x)  {  x = _x; }
//     int get()  { return x; }
// };

// class B
// {
//     static A a;
// public:
//   static int get()
//   {  return a.get(); }
// };

// // A B::a(0);
// // 
// int main(void)
// {
//     B b;
//     cout << b.get();
//     return 0;
// }



#include <iostream>
using namespace std;
int main()
{
    const char* p = "12345";
    const char **q = &p;
    *q = "abcde";
    const char *s = ++p;
    p = "XYZWVU"; // can't do this *p = "XYZ"
    cout << *++s << "  " << p ;
    return 0;
}




class Point
{
public:
    Point() { cout << "Normal Constructor called\n"; }
    Point(const Point &t) { cout << "Copy constructor called\n"; }

    Point &operator=(const Point &p)
    {
        cout << "Copy Assignment called\n";
        return *this;
    }

    Point(Point &&p)
    {
        cout << "Move constructor called\n";
    }

    Point& operator=(Point && p)
    {
        cout << "Move Assignment called\n";
        return *this;
    }
};

int main()
{
    Point *t1, *t2;
    t1 = new Point();
    t2 = new Point(*t1);
    Point t3 = *t1;
    Point t4;
    t4 = t3;

    Point p3 = std::move(*t2);

    p3 = std::move(*t1);
    return 0;
}

// -----------------------------------

#include<iostream>
using namespace std;

class base {
    public: 
    int arr[10];
};

class b1: public base { };

class b2: public base { };

class derived: public b1, public b2 {};

int main(void)
{
    derived d;
  cout << sizeof(derived) << "   " << sizeof(d);
  
  d.arr[2] = 10; // request for member 'arr' is ambiguous (ERROR!)
  return 0;
}

// -------------------


// If a derived class writes its own method, then all functions of base class with same name become hidden, even if signatures of base class functions are different. In the above question, when fun() is rewritten in Derived, it hides both fun() and fun(int) of base class.
#include<iostream>
using namespace std;

class Base
{
public:
    int fun()  { cout << "Base::fun() called"; }
    int fun(int i)  { cout << "Base::fun(int i) called"; }
};

class Derived: public Base
{
public:
    int fun() {  cout << "Derived::fun() called"; }
};

int main()
{
    Derived d;
    d.fun(5); // error
    // We can access fun(int i) by this
    d.Base::fun(4);
    return 0;
}


// ---------------- 

/*

Object Slicing

Object slicing occurs when a derived class object is assigned to a base class object.

Note that an object of Derived is passed in describe(d), but print of Base is called. The describe function accepts a parameter of Base type. 
This is a typical example of object slicing, when we assign an object of derived class to an object of base type, 
the derived class object is sliced off and all the data members inherited from base class are copied. Object slicing should be avoided as there may be surprising results like above. 
As a side note, object slicing is not possible in Java. In Java, every non-primitive variable is actually a reference.

*/
#include <iostream>
#include<string>
using namespace std;

class Base
{
public:
    virtual string print() const
    {
        return "This is Base class";
    }
};

class Derived : public Base
{
public:
    virtual string print() const
    {
        return "This is Derived class";
    }
};

void describe(Base p)
{
    cout << p.print() << endl;
}

int main()
{
    Base b;
    Derived d;
    describe(b);
    describe(d);
    return 0;
}
