#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_QUEUE_SIZE = 6;

// Circular Queue
class Queue
{
private:
    int _front, _rear, size;
    int item[MAX_QUEUE_SIZE];

public:
    Queue(/* args */) : _front{0}, _rear{-1}, size{0} {}
    ~Queue() {}

    inline void enQueue(const int &ele)
    {
        if(isFull()) {
            throw runtime_error("Queue is full!\n");
        }
        item[(((_rear+1) == MAX_QUEUE_SIZE)? 0 : ++_rear % MAX_QUEUE_SIZE)] = ele;
        ++size;
    }
    inline void deQueue()
    {
        if(isEmpty())
            throw runtime_error("Queue is Empty!\n");

        _front == MAX_QUEUE_SIZE? 0 : ++_front;
        --size;
    }
    inline int front()
    {
        return item[_front];
    }
    inline int rear()
    {
        return item[_rear];
    }
    void traverseQueue(const std::function<void(int)> &f)
    {
        for (int i = _front; i >= _rear; ++i)
        {
            f(item[i]);
        }
    }
    inline bool isEmpty() const
    {
        return !size;
    }
    inline bool isFull() const
    {
        return size == MAX_QUEUE_SIZE;
    }
    inline int size() const
    {
        return size;
    }
    void clear()
    {
        _front = 0;
        _rear = -1;
        size = 0;
    }
};

void print(int ele)
{
    std::cout << ele << '\n';
}

int main(int argc, char **argv)
{

    Queue s;

    for (size_t i = 0; i < argc; i++)
    {
        cout << argv[i] << "\n";
    }
    // std::cout << "\n";

    std::function<void(int)> f = [](int ele)
    {
        std::cout << ele << '\n';
    };

    s.enQueue(1);
    s.enQueue(4);
    s.enQueue(7);
    s.enQueue(8);
    s.enQueue(9);

    s.traverseQueue(f);

    return 0;
}
