#include <bits/stdc++.h>
using namespace std;

enum METHED_TYPE
{
    METHOD_1 = 1,
    METHOD_2 = 2,
    METHOD_3 = 3,
    METHOD_4 = 4
};

struct Node
{
    int value;
    Node *next;
};

class singlyLinkedList
{
private:

    Node *head, *tail;
    int _size;
    Node* recursiveReverse(Node* node);
public:
    singlyLinkedList();
    ~singlyLinkedList();
    void push_front(const int &ele);
    void push_back(const int &ele);
    void insert(const int &index, const int &value);
    void pop_front();
    void pop_back();
    void remove(const int &index);
    void reverse();
    bool search(const int &value);

    inline int size() const;
    void traverse(const std::function<void(int)> &f);
    inline bool isEmpty() const;
    inline bool isFull() const;
    void clear();

    void recursiveReverse();
    int get_nth_back(int n, const METHED_TYPE &m);
    void delete_node_with_key(const int &val);
    void swap_pairs();
    void delete_even_positions();
    void insert_sorted(const int &value);
};

void singlyLinkedList::delete_node_with_key(const int& val) {
    
}

void singlyLinkedList::swap_pairs() {

}

void singlyLinkedList::delete_even_positions() {

}

void singlyLinkedList::insert_sorted(const int& value) {

}

int singlyLinkedList::get_nth_back(int pos, const METHED_TYPE &m = METHOD_1)
{
    if (!head || size() == 0)
        throw -1;

    switch (m)
    {
    case METHOD_1:
    {

        int trgtPos = size() - pos;
        Node *temp = head;
        for (int i = 0; i < trgtPos; ++i)
            temp = temp->next;
        return temp->value;
    }
    case METHOD_2:
    {
        Node *slow = head, *fast = head;
        for (int i = 0; i < pos; i++)
        {
            fast = fast->next;
        }
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->value;
    }
    default:
        throw -1;
    }
}

singlyLinkedList::singlyLinkedList() : head{nullptr}, tail{nullptr}, _size{0} {}
singlyLinkedList::~singlyLinkedList()
{
    clear();
}

void singlyLinkedList::push_front(const int &ele)
{
    Node *newNode = new Node{ele, nullptr};
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    ++_size;
}
void singlyLinkedList::push_back(const int &ele)
{
    Node *newNode = new Node{ele, nullptr};

    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    ++_size;
}
void singlyLinkedList::insert(const int &index, const int &value)
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
        Node *newNode = new Node{value, nullptr};
        newNode->next = slow->next;
        slow->next = newNode;
    }
    ++_size;
}

void singlyLinkedList::pop_front()
{
    if (isEmpty())
        return;
    Node *temp = head;
    head = head->next;

    if (head = nullptr)
        tail = nullptr;

    --_size;
    delete temp;
}

void singlyLinkedList::pop_back()
{
    remove(_size - 1);
}

void singlyLinkedList::remove(const int &index)
{

    if (isEmpty())
        return;
    if (index == 0)
    {
        pop_front();
        --_size;
        return;
    }

    Node *slow = nullptr;
    Node *fast = head;

    int count = index;
    while (count--)
    {
        slow = fast;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    if (index == _size - 1)
        tail = slow;

    delete fast;
    --_size;
}

Node* singlyLinkedList::recursiveReverse(Node* node) {
    if(node && node->next) {
        Node* rem = recursiveReverse(node->next);
        rem->next = node;
        node->next = nullptr;
    }
    return node;
}

void singlyLinkedList::recursiveReverse() {
    recursiveReverse(head);
    swap(head, tail);
}

void singlyLinkedList::reverse()
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *nextNode = nullptr;

    tail = head;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

// bool singlyLinkedList::search(int value)
// {

// Node *node = head;
// while (node)
// {
//     if (node->value == value)
//         return true;
//     node = node->next;
// }
// return false;
// }

bool singlyLinkedList::search(const int &value)
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
int singlyLinkedList::size() const
{
    return _size;
}
void singlyLinkedList::traverse(const std::function<void(int)> &f)
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
bool singlyLinkedList::isEmpty() const
{
    return !_size;
}
bool singlyLinkedList::isFull() const
{
    return true;
}
void singlyLinkedList::clear()
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
        std::cout << ele << ' ';
    };

    singlyLinkedList sll;

    sll.push_back(1);
    sll.push_front(3);
    sll.push_front(15);
    sll.push_back(17);

    sll.push_back(20);
    sll.push_front(16);

    sll.remove(5);

    sll.push_back(90);
    sll.push_front(160);

    sll.insert(4, 30);

    std::cout << sll.size() << "\n";
    sll.traverse(f);
    sll.reverse();
    std::cout << "\n";
    sll.traverse(f);

    sll.push_back(966);
    sll.push_front(2000);

    std::cout << "\n";
    sll.traverse(f);
    std::cout << "\n";
    std::cout << sll.size() << '\n';
    std::cout << "val is= " << sll.get_nth_back(8, METHOD_1) << '\n';

    sll.recursiveReverse();
    sll.traverse(f);
    std::cout << "\n";

    // std::cout << sll.search(160) << "\n";
    // std::cout << sll.search(20) << "\n";

    return 0;
}