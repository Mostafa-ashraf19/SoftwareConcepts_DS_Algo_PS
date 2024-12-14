#include <bits/stdc++.h>
using namespace std;

template <class T>
class StackLL // LIFO
{
private:
    struct node
    {
        T value;
        node *next;
    };

    node *sTop;
    int Ssize;

public:
    StackLL() : sTop{nullptr}, Ssize{0} {}
    ~StackLL() {}
    void push(const T &val)
    {
        if (sTop == nullptr)
        {
            sTop = new node{val, nullptr};
        }
        else
        {
            node *temp = new node{val, nullptr};
            temp->next = sTop;
            sTop = temp;
        }
        ++Ssize;
    }

    void pop()
    {
        if (sTop)
        {
            node *temp = sTop;
            sTop = sTop->next;
            --Ssize;
            delete temp;
        }
    }

    T top() const
    {
        if (sTop)
            return sTop->value;
        throw runtime_error("Stack is empty");
    }

    bool isEmpty() const
    {
        return sTop == nullptr;
    }

    bool isFull()
    {
        return true;
    }

    int size()
    {
        return Ssize;
    }

    void traverse(const std::function<void(T)> &f)
    {
        for (node *temp = sTop; temp; temp = temp->next)
        {
            f(temp->value);
        }
    }

    void clear()
    {
        while (sTop)
        {
            pop();
        }
    }
};

int main(int argc, char **argv)
{
    StackLL<char> s;

    std::function<void(int)> f = [](int ele)
    {
        std::cout << ele << " ";
    };
    s.push('A');
    s.push('a');
    s.push('B');

    s.clear();

    try
    {
        std::cout << s.top() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // s.traverse(f);

    return 0;
}
