#include <bits/stdc++.h>
using namespace std;

class A
{
protected:
    virtual void print();
};

class B
{
};

int main(int argc, char **argv)
{

    std::cout << "Size of Class(A) Empty class(with Virtual functions): " << sizeof(A) << '\n';
    std::cout << "Size of Class(B) Empty class(without Virtual functions): " << sizeof(B) << '\n';

    int arr[4] = {9, 5, 66, 77};
    int arr2[3] = {63, 252, 166};
    // doubly linked list
    std::list<int> l;
    l.push_back(2);
    l.push_front(1);
    // l.pop_back();
    // l.pop_front();
    auto x = l.front();
    auto y = l.back();

    // remove every (value) exits in list
    // l.remove(value)

    // remove range or index based on iterator.
    // l.erase()

    l.insert(l.begin(), arr, arr + 4);

    l.assign(arr2, arr2 + 3);

    // l.merge()

    copy(l.begin(), l.end(), std::ostream_iterator<int>(cout, " "));

    std::cout << std::endl;
    return 0;
}