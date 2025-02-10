#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &out, stack<T> s)
{
    while (!s.empty())
    {
        out << s.top() << ' ';
        s.pop();
    }
    return out;
}

int main(int argc, char **argv)
{

    stack<int> s;
    s.push(6);
    s.push(1);
    s.push(3);
    s.push(5);
    s.push(9);

    stack<int> s2;
    s2.push(60);
    s2.push(11);
    s2.push(33);
    s2.push(55);
    s2.push(95);

    s.swap(s2);

    s.emplace(122);

    std::cout << s << '\n'
              << s2;

    std::cout << std::endl;
    return 0;
}