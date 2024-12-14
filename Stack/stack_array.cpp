#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_STACK_SIZE = 100;

class Stack // LIFO
{
private:
    int top;
    int item[MAX_STACK_SIZE];

public:
    Stack(/* args */) : top{-1} {}
    ~Stack() {}

    inline void push(const int &ele)
    {
        item[++top] = ele;
    }
    inline int Top()
    {
        return item[top];
    }
    inline void pop()
    {
        --top;
    }
    void traverseStack(const std::function<void(int)> &f)
    {
        for (int i = top; i >= 0; --i)
        {
            f(item[i]);
        }
    }
    inline bool isEmpty() const
    {
        return top == -1;
    }
    inline int size() const
    {
        return top + 1;
    }
    void clear()
    {
        top = -1;
    }
};

void print(int ele)
{
    std::cout << ele << '\n';
}

int main(int argc, char **argv)
{

    Stack s;

    for (size_t i = 0; i < argc; i++)
    {
        cout << argv[i] << "\n";
    }
    // std::cout << "\n";

    std::function<void(int)> f = [](int ele)
    {
        std::cout << ele << '\n';
    };

    s.push(1);
    s.push(4);
    s.push(7);
    s.push(8);
    s.push(9);

    s.traverseStack(f);

    return 0;
}
