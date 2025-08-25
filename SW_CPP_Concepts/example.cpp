// s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c){
//             return !std::isalnum(c);
//              }), s.end());
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numOfConsecutiveChars(string s)
{
    int count = 0, i = 0;

    while (i < s.length() - 1)
    {
        if (s[i] == s[i + 1])
        {
            ++count;
            ++i;
        }
        ++i;
    }
    return count;
}

int getDiffAnagram(string a, string b)
{

    std::vector<int> freq(26, 0);

    if (a.size() != b.size())
        return -1;
    int count = 0;
    for (const auto &c : a)
    {
        ++freq[c - 'a'];
    }
    for (const auto &c : b)
    {
        --freq[c - 'a'];
        if (freq[c - 'a'] < 0)
        {
            ++count;
        }
    }
    return count;
}

bool isPalindrome(string s)
{

    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c)
                           { return !std::isalnum(c); }),
            s.end());

    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c)
                   { return tolower(c); });

    int l = 0, r = s.length() - 1;
    for (int i = 0; i < s.length() / 2; ++i)
    {
        if (s[l++] != s[r--])
        {
            return false;
        }
    }
    return true;
}

#include <iostream>
using namespace std;

template <typename T>
T maxxx(T x, T y)
{
    return (x > y) ? x : y;
}

int maxProfit(vector<int> &prices)
{
    int i = 0;
    int j = prices.size() - 1;
    int maxProfit = 0;
    while (i <= j)
    {
        int buy = prices[i];
        int sell = prices[j];
        // profit = sell - buy;
        if (sell - buy < 0)
        {
            ++i;
        }
        else
        {
            if (sell - buy > maxProfit)
            {
                maxProfit = sell - buy;
            }
            else
            {
                --j;
            }
        }
    }
    return maxProfit;
}

inline bool isNotAlpha(const char &c)
{
    return c == '{' || c == '(' || c == '[' || c == '}' || c == ')' || c == ']';
}

bool isValid(string s)
{

    std::stack<char> stk;
    std::map<char, char> par = {
        {'}', '{'},
        {')', '('},
        {']', '['}};
    int i = 0;
    for (const auto &c : s)
    {
        if (isNotAlpha(c))
        {
            stk.push(c);
        }

        if (c == '}' || c == ')' || c == ']')
        {
            if (stk.size() <= 1)
                return false;

            if (!stk.empty())
            {
                stk.pop();
                if (stk.top() == par[c])
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return stk.empty();
}

void func(const double &v)
{
    cout << v;
}

void func(double &&v)
{
    cout << v;
}

template <typename T>
void func(const T &v)
{
    cout << "const T&" << v;
}

template <typename T>
void func(T &&v)
{
    cout << "T&&" << v << '\n';
}

class Excpection : public std::exception
{
public:
    using std::exception::exception;

    Excpection()
    {
        throw(0);
    }
};

class Excpection_1 : public Excpection
{
};
class Excpection_2 : public Excpection_1
{
};

std::atomic flag(false);
int *globaldata = nullptr;

void worker(int tid)
{
    if (!flag.exchange(true))
    {
        globaldata = new int(tid);
    }
    else
    {
        while (globaldata == nullptr)
        {
        }
        int *localData = globaldata;
        std::cout << "T " << *localData << '\n';
    }
}

// class Base
// {
// public:
//     Base() { std::cout << "Base Constructor\n"; }
//     virtual ~Base() { std::cout << "Base Destructor\n"; }
// };

// class Derived : public Base
// {
// public:
//     Derived() { std::cout << "Derived Constructor\n"; }
//     ~Derived() { std::cout << "Derived Destructor\n"; }

//     // No explicit destructor
// };

class Base
{
public:
    Base() { std::cout << "Base Constructor\n"; }
    ~Base() { std::cout << "Base Destructor\n"; }
    void show() {
        std::cout << "D Show\n";
    }
};

class Derived : public Base
{
public:
    int x;

    Derived() { std::cout << "Derived Constructor\n";
        x = 10;
    }
    void show() {
        std::cout << "D Show\n";
    }
    ~Derived() { std::cout << "Derived Destructor\n"; }

};

void fun(int& v) {
    v = 3;
}

int main()
{
    short a = 6;
    fun(a);
    std::cout << a; 
    // Base *pb, b;
    // Derived d;

    // pb = &d;

    // pb->show();
    // std::cout << pb->x;



    // Derived obj;
    // Base * p = new Derived();
    // delete p;
    // std::thread t1(worker, 1);
    // std::thread t2(worker, 2);
    // std::thread t3(worker, 3);

    // t1.join();
    // t2.join();
    // t3.join();
    int *ptr = new int[3];

    delete [] ptr;
    // std::cout << "PTR= " << *ptr << '\n';
    // delete ptr;
    // delete ptr;

    // int *ptr2 = new int(10);
    // std::cout << "ptr2= " << *ptr2 << '\n';
    // delete ptr2;
    // ptr2 = nullptr;
    // delete ptr2;

    // wild pointer
    //  = new int(10);
    // delete ptr; // ptr is now dangling
    // ptr = nullptr;
    // *ptr = 20;  // Undefined behavior

    // std::all_of()

    // try
    // {
    //     Excpection_2 ex;
    // }
    // catch (const Excpection_1 &e)
    // {
    //     std::cerr << "HI Excpection_1\n";
    // }
    // catch (const Excpection_2 &a)
    // {
    //     std::cerr << "HI Excpection_2\n";
    // } catch(...) {
    //     std::cerr << "HI ...\n";

    // }

    // func(42);

    // std::cout << isValid("([{}])") << '\n';

    // int num = 8;
    // int len = log2(num);
    // constexpr int bitsRep = 8;
    // std::cout << bitset<bitsRep>(num).to_string() << '\n';
    // std::cout << bitset<bitsRep>(num).to_string().substr(bitsRep - len - 1) << '\n';

    // cout << maxxx(3, '7') << std::endl;
    // cout << max(3.0, 7.0) << std::endl;
    // cout << max(3, 7.0) << std::endl;
    return 0;
}

// int main(int argc , char* argv[]) {
//     // string s = "21Was it a car or a cat I saw?12";

//     // auto endIt = std::remove_if(s.begin(), s.end(), [](unsigned char c){
//     //                 return (!std::isalnum(c)) || (c > '0' && c < '9');
//     //             });

//     // s.erase(endIt, s.end());
//     int *x = nullptr;
//     delete x;
//     delete x;

//     int* ptr = new int(5);
//     std::cout << *ptr << '\n';

//     delete ptr;
//     // delete ptr;// dangling pointer
//     // std::cout << *ptr << '\n'; // dangling pointer

//     ptr = nullptr;
//     ptr = nullptr;

//     // const char* s = argv[1];
//     // int * a = new int;

//     // std::cout << numOfConsecutiveChars(s) << '\n';

//     return 0;
// }

/*

#include<iostream>
using namespace std;
int main ()
{
       int cin;
       cin >> cin;
       cout << "cin" << cin;
       return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int add(int x) {
//     return ++x;
// }
// int x = 3;

// // class empty{};

// class A {
//     public:

//     virtual void print() final {
//         cout << "Hi A\n";
//     }
// };

// class B : public A {
//     public:
//     void print() {
//         cout << "Hi B\n";
//     }
// };

// int main() {
//     // A* a;
//     // char* ptr = "Hello";
//     // char* ptr2[] = {"Hi", "ok", "bye"};

//     // int x= 10;

//     // cout << sizeof(empty) << '\n';
//     return 0;
// }


*/
