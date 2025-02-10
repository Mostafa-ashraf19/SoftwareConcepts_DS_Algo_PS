#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &out, queue<T> q)
{
    while (!q.empty())
    {
        out << q.front() << ' ';
        q.pop();
    }
    return out;
}

int main(int argc, char **argv)
{
    queue<int> q;

    int &&x = 3;

    q.push(std::move(x)); // one const ref L-value , and other by move R-value ref.
    q.push(123);

    std::cout << q.back() << '\n';
    std::cout << q;

    std::cout << '\n';
    return 0;
}