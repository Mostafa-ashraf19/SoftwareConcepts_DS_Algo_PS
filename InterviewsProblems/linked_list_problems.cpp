#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

// Reverse a Linked List (iterative + recursive).
Node *reverseList(Node *head)
{
    Node *curr = head, *prev = nullptr;

    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

// Detect Cycle in a Linked List
// Hint: Floyd’s Tortoise and Hare.
bool isCycleDetected(Node *head)
{

    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Meet at " << slow << " " << fast << " " << slow->value << " " << fast->value << '\n';

            return true;
        }
    }
    return false;
}

// Merge Two Sorted Linked Lists
// Hint: Dummy node technique.
void MergeLists(Node *&l1, Node *&l2)
{
}

// Remove Nth node from end
Node *removeNthFromEnd(Node *head, int n)
{

    Node *first = head, *second = head;

    for (int i = 0; i < n; ++i)
        first = first->next;

    if (first == nullptr)
        return head->next;

    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;

    return head;
}

int main()
{

    Node *head, n1, n2, n3, n4;

    head = &n1;

    n1.value = 1;
    n1.next = &n2;

    n2.value = 2;
    n2.next = &n3;

    n3.value = 3;
    n3.next = &n4;

    n4.value = 4;
    // n4.next = &n2; // cycle
    n4.next = nullptr;

    isCycleDetected(head);
    // head = reverseList(head);
    // cout << head->value << " " << head->next->next->value << '\n';

    // head = reverseList(head);
    // cout << head->value << " " << head->next->next->value << '\n';

    return 0;
}