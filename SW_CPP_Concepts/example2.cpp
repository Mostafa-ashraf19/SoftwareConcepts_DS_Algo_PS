// #include <iostream>
// using namespace std;

// class X 
// {
//     int x;
// public:

// X() {
//     std::cout << "Hellon";
// }
// X(int x) : x{x} {
//     std::cout << "params construcotr\n";
// };

// X(const X& _x) {
//     x = _x.x;
//     std::cout << "Copy Constructor Called \n";
// }

// X(const X&& _x) {
//     x = _x.x;
    
//     std::cout << "Move Constructor Called \n";
// }

// X& operator=(const X& _x) {
//     x = _x.x;
//     std::cout << "Copy Assignment Called \n";

//     return *this;
// }

// int getx() {return x;}
// };

// X func(X xx) {
//     std::cout << "1\n";
//     X x = xx;
//     std::cout << "2\n";

//     return x;
// }

// int main()
// {

//     const int y = 20;
//     // int z = 50;
//     const int& x = y;
//     // x = 30;
//     // x = z;
//     std::cout << x << '\n';

//     // X a = {10};
//     // X b(std::move(a)); // call copy constructor //{60};

//     // // b = a;
//     // // X b(func(a));

//     // // b = a;

//     // // b = func(a); // call copy assignment

//     // cout << a.getx() << " " << b.getx() << '\n';
//     return 0;
// }




// // class Point {
// //     Point() { cout << "Constructor called"; }
// // };

// // int main()
// // {
// //     Point t1;
// //     return 0;
// // }



// #include<iostream>
// using namespace std;

// int *fun()
// {
//     static int* x = new int(10);
//     return x;
// }



// int main()
// {
//     *fun() = 30;
//     cout << *fun();

//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Test
// {
//     static int x;
//     int *ptr;
//     int y;
// };

// class Test2 {
//     static virtual void func() = 0;
// };

// int main()
// {
//     // Test2* t = new Test2();
//     // Test t;
//     // cout << sizeof(t) << "\n";
//     // cout << sizeof(Test *) << '\n';
// }


// #include <iostream>
// class Test
// {
// public:
//     int i;
//     void get();
// };
// void Test::get()
// {
//     std::cout << "Enter the value of i: ";
//     std::cin >> i;
// }
// Test t;  // Global object
// int main()
// {
//     std::cout << &t;
    
//     Test t;  // local object
//     t.get();
    
//     std::cout << "value of i in local t: " <<t.i<< '\n';
//     ::t.get(); // scope global.
    
//     std::cout << "value of i in global t:  " <<::t.i<< '\n';
//     return 0;
// }

// #include<iostream>
// using namespace std;
 
// class Empty {

// ~Empty() {
//     std::cout << "Hello dest\n";

// }
// public:
// Empty() {
//     std::cout << "Hello cons\n";
// }

// };
 
// int main()
// {
//     Empty e;
// //   cout << sizeof(Empty) << '\n';
//   return 0;
// }

// #include <iostream>
// using namespace std;
 
// int i;
 
// class A
// {
// public:
//     ~A()
//     {
//         i=10;
//     }
// };
 
// int foo()
// {
//     i=3;
//     A ob;
//     return i;
// }
 
// int main()
// {
//     cout << foo() << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std; 
// class A
// {
//     int id;
//     static int count;
// public:
//     A() {
//         count++;
//         id = count;
//         cout << "constructor for id " << id << endl;
//     }
//     ~A() {
//         cout << "destructor for id " << id << endl;
//     }
// };
 
// int A::count = 0;
 
// int main() {
//     A a[3];
//     return 0;
// }

// #include<stdlib.h>
// #include<stdio.h>
// #include<iostream>

// using namespace std;

// class Test {
//     int x;
// public:
//     void* operator new(size_t size);
//     void operator delete(void*);
//     Test(int i) {
//         x = i;
//         cout << "Constructor called \n";
//     }
//     ~Test() { cout << "Destructor called \n"; }
// };


// void* Test::operator new(size_t size)
// {
//     void *storage = malloc(size);
//     cout << "new called \n";
//     return storage;
// }

// void Test::operator delete(void *p )
// {
//     cout<<"delete called \n";
//     free(p);
// }

// int main()
// {
//     Test *m = new Test(5);
//     delete m;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Point {
// private:
//   int x, y;
// public:
//   Point() : x(0), y(0) { }
//   Point& operator()(int dx, int dy);
//   void show() {cout << "x = " << x << ", y = " << y; }
// };

// Point& Point::operator()(int dx, int dy)
// {
//     x = dx;
//     y = dy;
//     return *this;
// }

// int main()
// {
//   Point pt;
//   pt(3, 2);
//   pt.show();
//   return 0;
// }

// #include <iostream>
// using namespace std;
// class Test2
// {
//     int y;
// };

// class Test
// {
//     int x;
//     Test2 t2;
// public:
//     operator Test2 ()  { return t2; }
//     operator int () { return x; }
// };

// void fun ( int x) { cout << "fun(int) called"; }
// void fun ( Test2 t ) { cout << "fun(Test 2) called"; }

// int main()
// {
//     Test t;
//     fun(t);
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Test
// {
// private:
//   int x;
// public:
//   Test(int x = 0) { this->x = x; }
//   void change(Test *t) { this = t; }
//   void print() { cout << "x = " << x << endl; }
// };

// int main()
// {
//   Test obj(5);
//   Test *ptr = new Test (10);
//   obj.change(ptr);
//   obj.print();
//   return 0;
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
//     void fun() const  { cout << "fun() const " << endl; }
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

// #include <iostream>
// class Test
// {
// public:
//     static void fun();
// };
//  void Test::fun()   
// {
//     std::cout<<"fun() is staticn";
// }
// int main()
// {
//     Test::fun();   
//     return 0;
// }

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
//    static int get()
//    {  return a.get(); }
// };

// int main(void)
// {
//     B b;
//     cout << b.get();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Test
// {
//     static int x;
// public:
//     Test() { x++; }
//     static int getX() {return x;}
// };

// int Test::x = 0;

// int main()
// {
//     cout << Test::getX() << " ";
//     Test t[5];
//     cout << Test::getX();
// }

// #include <iostream>
// using namespace std;
// class A
// {
// protected:
//     int x;
// public:
//     A() {x = 0;}
//     friend void show();
// };

// class B: public A
// {
// public:
//     friend void show();

//     B() : y (0) {}
// private:
//     int y;
// };

// void show()
// {
//     A a;
//     B b;
//     cout << "The default value of A::x = " << a.x << " ";
//     cout << "The default value of B::y = " << b.y;
// }

// int main() {
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class B;
// class A {
//     int a;
// public:
//     A():a(0) { }
//     void show(A& x, B& y);
// };

// class B {
// private:
//     int b;
// public:
//     B():b(0) { }
//     friend void A::show(A& x, B& y);
// };

// void A::show(A& x, B& y) {
//     x.a = 10;
//     cout << "A::a=" << x.a << " B::b=" << y.b;
// }

// int main() {
//     A a;
//     B b;
//     a.show(a,b);
//     return 0;
// }


// using namespace std;

// class Test {

// public: 

// static const int x;

// };

// const int Test::x = 0;

// int main()
// {
//     Test t;

//     // const char*  p = "12345";
//     // const char **q = &p;
//     // *q = "abcde";
//     // const char *s = ++p;
//     // cout << *s << '\n';
    
//     // p = "XYZWVU";
//     // cout << *++s;
//     return 0;
// }

// #include <stdio.h>
// #include <iostream>

// int main()
// {

//     int *p = new int; 
//     delete p;
//     delete p;

//     // int **x = p;

//    return 0;
// }

// #include<iostream>
// using namespace std;
// int x = 1;
// void fun()
// {
//     int x = 2;
//     {
//         int x = 3;
//         cout << ::x << endl;
//     }
// }
// int main()
// {
//     fun();
//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// class a
// {
// public :
//     ~a()
//     {
//         cout << "destroy";
//     }
// };
// int main()
// {
//    vector <a*> *v1  = new vector<a*>;
//    vector <a> *v2  = new vector<a>;
//    return 0;
// }


// #include <iostream>
// using namespace std;
// int main()
// {
// 	int array[] = { 10, 20, 30 };
// 	cout << -2 [array];
// 	return 0;
// }


// #include<iostream>
// using namespace std;

// class base {
//     int arr[10];
// };

// class b1: virtual public base { };

// class b2: virtual public base { };

// class derived: public b1, public b2 {

//     public:

//     void add(int index, int value) {
//         arr[index] = value;
//     }

//     void get(int index) {
//         return arr[index] ;
//     }
// };

// int main(void)
// {
//   derived d;
// //   d.arr[0] = 10;  
// d.add(0,10);

// d.get(0);
//   cout << sizeof(derived);
//   return 0;
// }


// #include<iostream>
// using namespace std;

// class Base {};

// class Derived: public Base {};

// int main()
// {
//     Base *bp = new Derived;
//     Derived *dp = new Base;
// }


// #include<iostream>
// using namespace std;

// class Base
// {
// public:
//     virtual void show()
//     {
//         cout<<" In Base \n";
//     }
// };

// class Derived: public Base
// {
// public:
//     int x;
//      void show()
//     {
//         cout<<"In Derived \n";
//     }
//     Derived()
//     {
//         x = 10;
//     }
// };

// int main(void)
// {
//     Base *bp, b;
//     Derived d;
//     bp = &d;
//     bp->show();
//     // cout << bp->x;    
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Base
// {
// public:
//     int fun()  { cout << "Base::fun() called"; }
//     int fun(int i)  { cout << "Base::fun(int i) called"; 
//     return 0;}
// };

// class Derived: public Base
// {
// public:
//     int fun() {  cout << "Derived::fun() called"; }
// };

// int main()
// {
//     Derived d;
//     d.fun(5);
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Base {
// public:
//     void fun()          {    cout << "Base::fun() called";     }
//     void fun(int i)     {   cout << "Base::fun(int i) called";  }
// };

// class Derived: public Base  {
// public:
//     void fun()   {     cout << "Derived::fun() called";   }
// };

// int main()  {
//     Derived d;
//     d.Base::fun(5);
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Base
// {
// public :
//     int x, y;
// public:
//     Base(int i, int j){ x = i; y = j; }
// };

// class Derived : public Base
// {
// public:
//     Derived(int i, int j):Base(i, j) {}
//     void print() {cout << x <<" "<< y; }
// };

// int main(void)
// {
//     Derived q(10, 10);
//     q.print();
//     return 0;
// }



// #include<iostream>
// using namespace std;

// class Base
// {
// protected:
//     int a;
// public:
//     Base() {a = 0;}
// };

// class Derived1:  public Base
// {
// public:
//     int c;
// };


// class Derived2:  public Base
// {
// public:
//     int c;
// };

// class DerivedDerived: public Derived1, public Derived2
// {
// public:
//     void show()  {   cout << a;  }
// };

// int main(void)
// {
//     DerivedDerived d;
//     d.show();
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Base1
// {
// public:
//     char c;
// };

// class Base2
// {
// public:
//     int c;
// };

// class Derived: public Base1, public Base2
// {
// public:
//     void show()  { cout << c; }
// };

// int main(void)
// {
//     Derived d;
//     d.show();
//     return 0;
// }


// #include<iostream>
// using namespace std;
// class A
// {
// public:
//      A(){ cout <<"1";}
//      A(const A &obj){ cout <<"2";}
// };

// class B: virtual A
// {
// public:
//     B(){cout <<"3";}
//     B(const B & obj){cout<<"4";}
// };

// class C: virtual A
// {
// public:
//    C(){cout<<"5";}
//    C(const C & obj){cout <<"6";}
// };

// class D:B,C
// {
// public:
//     D(){cout<<"7";}
//     D(const D & obj){cout <<"8";}
// };

// int main()
// {
//    D d1;
//    D d(d1);
// }

// #include<iostream>
// using namespace std;
// class Base
// {
// public:
//     virtual void show() = 0;
// };

// class Derived : public Base { 

//     void show() {
//         std::cout << "Hi\n";
//     }
// };

// int main(void)
// {
//     Derived q;
//     return 0;
// }


// #include<iostream>
// using namespace std;

// class Base
// {
// public:
//     virtual void show() = 0;
// };

// class Derived: public Base
// {
// public:
//     void show() { cout<<"In Derived n"; }
// };

// int main(void)
// {
//     Derived d;
//     Base &br = d;
//     br.show();
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Base
// {
// public:
//     virtual void show() { cout<<" In Base n"; }
// };

// class Derived: public Base
// {
// public:
//     void show() { cout<<"In Derived n"; }
// };

// int main(void)
// {
//     Base *bp = new Derived;
//     bp->Base::show();  // Note the use of scope resolution here
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     virtual void fun();
// };

// class B
// {
// public:
//    void fun();
// };

// int main()
// {
//     int a = sizeof(A), b = sizeof(B);
//     if (a == b) cout << "a == b";
//     else if (a > b) cout << "a > b";
//     else cout << "a < b";
//     return 0;
// }


// #include <iostream>
// using namespace std;
 
// class A
// {
// public:
//     virtual void fun() { cout << "A::fun() "; }
// };
 
// class B: public A
// {
// public:
//    void fun() { cout << "B::fun() "; }
// };
 
// class C: public B
// {
// public:
//    void fun() { cout << "C::fun() "; }
// };
 
// int main()
// {
//     B *bp = new C;
//     bp->fun();
//     return 0;
// }


// #include <iostream>
// using namespace std;

// template <typename T>
// T maxZZ(T x, T y)
// {
//     return (x > y)? x : y;
// }
// int main()
// {
//     cout << maxZZ(3, 7) << std::endl;
//     cout << maxZZ(3.0, 7.0) << std::endl;
//     cout << maxZZ(3, 7.0) << std::endl;
//     return 0;
// }


// #include<iostream>
// #include<stdlib.h>
// using namespace std;

// template<class T, class U>
// class A  {
//     T x;
//     U y;
//     static int count;
// };

// int main()  {
//    A<char, char> a;
//    A<int, int> b;
//    cout << sizeof(a) << endl;
//    cout << sizeof(b) << endl;
//    return 0;
// }


// #include <iostream>
// using namespace std;

// template <class T>
// T max (T &a, T &b)
// {
//     return (a > b)? a : b;
// }

// template <>
// int max <int> (int &a, int &b)
// {
//     cout << "Called ";
//     return (a > b)? a : b;
// }

// int main ()
// {
//     int a = 10, b = 20;
//     cout << max <int> (a, b);
// }


// #include <iostream>
// using namespace std;

// int main()
// {
//     try
//     {
//         try
//         {
//             throw 20;
//         }
//         catch (int n)
//         {
//             cout << "Inner Catchn";
//             throw;
//         }
//     }
//     catch (int x)
//     {
//         cout << "Outer Catchn";
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;

// class Test {
// public:
//    Test() { cout << "Constructing an object of Test " << endl; }
//   ~Test() { cout << "Destructing an object of Test "  << endl; }
// };

// int main() {
//   try {
//     Test t1;
//     throw 10;
//   } catch(int i) {
//     cout << "Caught " << i << endl;
//   }
// }

// #include <iostream>
// using namespace std;

// int fun() throw (int)
// {
//     throw 10;
// }

// int main() {

//   fun();

//   return 0;
// }
 

#include <iostream>
using namespace std;

// Ideally it should have been \"int fun() (int)\"
int fun()
{
    throw 10;
}

int main()
{
    try
    {
        fun();
    }
    catch (int )
    {
        cout << "Caught";
    }
    return 0;
}
