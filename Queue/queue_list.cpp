#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue_LinkedList
{
private:
    struct node
    {
        T value;
        node *next;
    };
    int size;
    node *_front, *_rear;

public:
    Queue_LinkedList();
    ~Queue_LinkedList();
    inline void enQueue(const T &ele);
    inline void deQueue();
    inline int front();
    inline int rear();
    void traverseQueue(const std::function<void(T)> &f);
    inline bool isEmpty() const;
    inline bool isFull() const;
    inline int getSize() const;
    void clear();
};

template <class T>
Queue_LinkedList<T>::Queue_LinkedList() : _front{nullptr}, _rear{nullptr}, size{0} {}
template <class T>
Queue_LinkedList<T>::~Queue_LinkedList() {}
template <class T>
void Queue_LinkedList<T>::enQueue(const T &ele)
{
    node *newNode = new node{ele, nullptr};
    if (!isEmpty())
    {
        _rear->next = newNode;
        _rear = newNode;
    }
    else
    {
        _front = _rear = newNode;
    }
    ++size;
    return;
}
template <class T>
void Queue_LinkedList<T>::deQueue()
{
    if (isEmpty())
    {
        return;
    }
    node *delnode = _front;
    _front = _front->next;
    _rear = !_front ? nullptr : _rear;
    --size;

    delete delnode;
}
template <class T>
int Queue_LinkedList<T>::front()
{
    return _front->value;
}
template <class T>
int Queue_LinkedList<T>::rear()
{
    return _rear->value;
}
template <class T>
void Queue_LinkedList<T>::traverseQueue(const std::function<void(T)> &f)
{
    node *temp = _front;
    while (temp != nullptr)
    {
        f(temp->value);
        temp = temp->next;
    }
}
template <class T>
bool Queue_LinkedList<T>::isEmpty() const
{
    return !size;
}
template <class T>
bool Queue_LinkedList<T>::isFull() const
{
    return true;
}
template <class T>
int Queue_LinkedList<T>::getSize() const
{
    return size;
}
template <class T>
void Queue_LinkedList<T>::clear()
{
    while (_front != nullptr)
    {
        node *temp = _front;
        _front = _front->next;
        --size;
        delete temp;
    }
}

int main()
{
    Queue_LinkedList<int> q;

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

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();

    q.enQueue(99);
    q.enQueue(1654);
    q.enQueue(66);

    q.clear();
    q.traverseQueue(f);

    return 0;
}