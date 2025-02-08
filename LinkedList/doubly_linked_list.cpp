#include <bits/stdc++.h>
using namespace std;

class doublyLinkedList
{
private:
    struct Node
    {
        int value;
        Node *next;
        Node *prev;
    };

    Node *head, *tail;
    int _size;

public:
    doublyLinkedList();
    ~doublyLinkedList();
    void push_front(const int &ele);
    void push_back(const int &ele);
    void insert(const int &index, const int &value);
    void pop_front();
    void pop_back();
    void remove(const int &index);

    bool search(const int &value);

    inline int size() const;
    void traverse(const std::function<void(int)> &f);
    inline bool isEmpty() const;
    inline bool isFull() const;
    void clear();
};

doublyLinkedList::doublyLinkedList() : head{nullptr}, tail{nullptr}, _size{0} {}
doublyLinkedList::~doublyLinkedList()
{
    clear();
}

void doublyLinkedList::push_front(const int &ele)
{
    Node *newNode = new Node{ele, nullptr, nullptr};
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    ++_size;
}
void doublyLinkedList::push_back(const int &ele)
{
    Node *newNode = new Node{ele, nullptr};

    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    ++_size;
}
void doublyLinkedList::insert(const int &index, const int &value)
{
    if (index == 0)
        push_front(value);
    else if (index == _size - 1)
        push_back(value);
    else
    {
        int count = index;
        Node *slow = nullptr;
        Node *fast = head;

        while (count--)
        {
            slow = fast;
            fast = fast->next;
        }
        Node *newNode = new Node{value, fast, slow};
        slow->next = newNode;
        fast->prev = newNode;
    }
    ++_size;
}

void doublyLinkedList::pop_front()
{
    if (isEmpty())
        return;
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    temp->prev = nullptr;

    if (head = nullptr)
        tail = nullptr;

    --_size;
    delete temp;
}
void doublyLinkedList::pop_back()
{
    remove(_size - 1);
}

void doublyLinkedList::remove(const int &index)
{
    throw runtime_error("WIP Method");
    // if (isEmpty())
    //     return;
    // if (index == 0)
    // {
    //     pop_front();
    //     --_size;
    //     return;
    // }

    // Node *slow = nullptr;
    // Node *fast = head;

    // int count = index;
    // while (count--)
    // {
    //     slow = fast;
    //     fast = fast->next;
    // }

    // slow->next = slow->next->next;
    // if (index == _size - 1)
    //     tail = slow;

    // delete fast;
    // --_size;
}

bool doublyLinkedList::search(const int &value)
{
    Node *node = head;
    while (node)
    {
        if (node->value == value)
            return true;
        node = node->next;
    }
    return false;
}
int doublyLinkedList::size() const
{
    return _size;
}
void doublyLinkedList::traverse(const std::function<void(int)> &f)
{
    if (isEmpty())
        return;

    Node *n = head;
    while (n)
    {
        f(n->value);
        n = n->next;
    }
}
bool doublyLinkedList::isEmpty() const
{
    return !_size;
}
bool doublyLinkedList::isFull() const
{
    return true;
}
void doublyLinkedList::clear()
{
    while (head)
    {
        Node *node = head;
        head = head->next;
        delete node;
        --_size;
    }
    if (!head)
        tail = nullptr;
}

int main(int argc, char **argv)
{

    std::function<void(int)> f = [](int ele)
    {
        std::cout << ele << '\n';
    };

    doublyLinkedList sll;
    // debugger;
    sll.push_front(1);
    sll.push_front(3);
    sll.push_front(15);
    sll.push_front(17);

    sll.push_front(20);
    sll.push_front(16);

    // sll.remove(5);

    sll.push_front(90);
    sll.push_front(160);

    // sll.insert(4,30);

    // std::cout << sll.size() << "\n";
    // sll.traverse(f);
    // sll.reverse();
    // std::cout << "\n";
    // sll.traverse(f);

    sll.push_front(966);
    sll.push_front(2000);

    std::cout << "\n";
    sll.traverse(f);
    std::cout << "\n";

    // std::cout << sll.search(160) << "\n";
    // std::cout << sll.search(20) << "\n";

    return 0;
}