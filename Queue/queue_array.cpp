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
        if (isFull())
        {
            throw runtime_error("Queue is full!\n");
        }
        _rear = (((_rear + 1) == MAX_QUEUE_SIZE) ? 0 : 1 + _rear % MAX_QUEUE_SIZE);
        item[_rear] = ele;
        ++size;
    }
    inline void deQueue()
    {
        if (isEmpty())
            throw runtime_error("Queue is Empty!\n");

        _front = (_front == MAX_QUEUE_SIZE - 1) ? 0 : 1 + _front;
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
        std::cout << _front << "  fff " << _rear << '\n';
        if (isEmpty())
        {
            return;
        }
        if (_front < _rear)
        {
            for (int i = _front; i <= _rear; ++i)
            {
                f(item[i]);
            }
        }
        else if (_front > _rear)
        {
            for (int i = _front; i < MAX_QUEUE_SIZE; ++i)
            {
                f(item[i]);
            }
            for (int i = 0; i <= _rear; ++i)
            {
                f(item[i]);
            }
        }
        else
        {
            f(item[_front]);
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
    inline int getSize() const
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

    Queue q;

    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << "\n";
    }

    std::function<void(int)> f = [](int ele)
    {
        std::cout << ele << '\n';
    };

    q.enQueue(1);
    q.enQueue(4);
    q.enQueue(7);
    q.enQueue(8);
    q.enQueue(9);
    q.enQueue(6);

    // // s.traverseQueue(f);
    // std::cout << q.front() << "\n";
    // std::cout << q.rear() << "\n";

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    // q.deQueue();
    // std::cout << q.front() << "\n";
    // std::cout << q.rear() << "\n";
    // q.enQueue(17);
    // std::cout << q.front() << "\n";
    // std::cout << q.rear() << "\n";
    q.enQueue(99);
    q.enQueue(1654);
    q.enQueue(66);

    // std::cout << q.front() << "\n";
    // std::cout << q.rear() << "\n";
    // std::cout  << "\n";

    q.traverseQueue(f);

    std::cout << "\n";

    return 0;
}
