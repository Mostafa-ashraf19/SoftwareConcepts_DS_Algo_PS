/*


The issue with your code lies in how you're modifying the std::list while iterating through it. Specifically, the problem is that you're erasing elements from the list while still using the iterator to traverse it. This can lead to undefined behavior, because after an element is erased, the iterator becomes invalid.

The issue in detail:
Erasing while iterating: When you erase an element from the list, the iterator i pointing to that element is invalidated. After erasing an element, the iterator i no longer points to a valid position, and continuing to use it leads to undefined behavior.

Iterator invalidation: In std::list, erasing an element shifts the list, and the iterator i becomes invalid. You cannot simply continue using the iterator after erasing an element from the list.

Solution:
You need to handle the iterator properly when you erase an element. One way to do this is to get the iterator to the next element before erasing the current element. std::list::erase returns an iterator pointing to the element following the one that was erased, which can be used in the next iteration.

Corrected Code:
cpp
Copy code
#include <iostream>
#include <list>

typedef std::list<int> _list;

extern bool bad(int);

int main() {

    _list l;

    for (_list::iterator i = l.begin(); i != l.end(); )  // Notice the different loop condition
    {
        if (bad(*i)) {
            i = l.erase(i);  // erase returns the iterator to the next element
        } else {
            ++i;  // only increment the iterator if no erase happened
        }
    }

    return 0;
}
Explanation of Changes:
Iterator Handling:
The iterator is updated in two ways:
If bad(*i) is true (i.e., the current element should be erased), i = l.erase(i) is called. This erases the current element and updates i to point to the next element (the iterator returned by erase).
If the element is not erased, the iterator is simply incremented (++i) to move to the next element.
Iterator Invalidation Avoided:
This approach ensures that the iterator i is always valid, because you either move to the next element after erasing, or you increment it normally when no element is erased.
Conclusion:
The key change is to update the iterator properly when erasing an element from the list. Always ensure that after an erase operation, you use the iterator returned by erase, which points to the element after the one that was just removed.





typedef std::list<int> _list;

extern bool bad(int);

int main() {

    _list l;

    for (_list::iterator i = l.begin(); i != l.end(); i++)
    {
        if(bad(*i))
            l.erase(i);
    }
    
    return 0;

}

*/

class A
{
protected:
    virtual void print();
};

class B
{
};

int main() {
    std::cout << "Size of Class(A) Empty class(with Virtual functions): " << sizeof(A) << '\n';
    std::cout << "Size of Class(B) Empty class(without Virtual functions): " << sizeof(B) << '\n';

}