#include <bits/stdc++.h>
using namespace std;

class binarySearchTree
{
private:
    struct Node
    {
        int value;
        Node *left;
        Node *right;
    };

    Node *root;
    int _size;

    void insertHelper(Node *&node, Node *newNode);
    bool searchHelper(const Node *node, const int &value);

public:
    binarySearchTree();
    ~binarySearchTree();

    bool search(const int &value);
    void insert(const int &value);
    void remove(const int &value);

    // Breadth first traversal (level order) (Queue)
    void levelOrderTraversal();

    // Depth first traversal
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();

    void levelOrderTraversal(Node *node);
    void preOrderTraversal(Node *node);
    void inOrderTraversal(Node *node);
    void postOrderTraversal(Node *node);
};

binarySearchTree::binarySearchTree() : root{nullptr}, _size{0} {}

binarySearchTree::~binarySearchTree() {}

void binarySearchTree::insertHelper(Node *&node, Node *newNode)
{
    if (node == nullptr)
    {
        node = newNode;
        return;
    }
    else if (newNode->value <= node->value)
    {
        // left side of BST
        insertHelper(node->left, newNode);
    }
    else if (newNode->value > node->value)
    {
        // right side of BST
        insertHelper(node->right, newNode);
    }
}

void binarySearchTree::insert(const int &value)
{
    if (root == nullptr)
    {
        root = new Node{value, nullptr, nullptr};
    }
    else
    {
        Node *newNode = new Node{value, nullptr, nullptr};
        insertHelper(root, newNode);
    }
    ++_size;
}

void binarySearchTree::levelOrderTraversal(Node *node)
{
    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *currentNode = q.front();

        std::cout << currentNode->value << ' ';

        if (currentNode->left)
        {
            q.push(currentNode->left);
        }
        if (currentNode->right)
        {
            q.push(currentNode->right);
        }

        q.pop();
    }
}

void binarySearchTree::preOrderTraversal(Node *node)
{
    if (node == nullptr)
        return;
    std::cout << node->value << ' ';
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
void binarySearchTree::inOrderTraversal(Node *node)
{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    std::cout << node->value << ' ';
    inOrderTraversal(node->right);
}
void binarySearchTree::postOrderTraversal(Node *node)
{
    if (node == nullptr)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->value << ' ';
}

void binarySearchTree::levelOrderTraversal()
{
    // BFS - breadth-first search - (level order) solve usinf (Queue)
    levelOrderTraversal(root);
}

void binarySearchTree::preOrderTraversal()
{
    // root-left-right
    preOrderTraversal(root);
}

void binarySearchTree::inOrderTraversal()
{
    // left-root-right
    inOrderTraversal(root);
}

void binarySearchTree::postOrderTraversal()
{
    // left-right-root
    postOrderTraversal(root);
}

void binarySearchTree::remove(const int &value)
{
}

bool binarySearchTree::searchHelper(const Node *node, const int &value)
{
    if (node == nullptr)
        return false;

    if (node->value == value)
    {
        return true;
    }
    else if (value < node->value)
    {
        return searchHelper(node->left, value);
    }
    else if (value > node->value)
    {
        return searchHelper(node->right, value);
    }
    return false;
}

bool binarySearchTree::search(const int &value)
{
    return searchHelper(root, value);
}

int main(int argc, char **argv)
{

    binarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << bst.search(10) << '\n';
    cout << bst.search(50) << '\n';
    cout << bst.search(90) << '\n';
    cout << bst.search(40) << '\n';

    bst.preOrderTraversal();
    std::cout << std::endl;
    bst.inOrderTraversal();
    std::cout << std::endl;
    bst.postOrderTraversal();
    std::cout << std::endl;
    bst.levelOrderTraversal();
    std::cout << std::endl;
    return 0;
}

/*

Here are several method names that you might consider implementing for a Binary Search Tree (BST).

These methods cover common operations and features that you would typically find in a BST:

1. Basic Operations:
    insert(const T& value): Insert a value into the BST.
    remove(const T& value): Remove a value from the BST.
    search(const T& value): Search for a value in the BST.
    findMin(): Find the minimum value in the BST.
    findMax(): Find the maximum value in the BST.
    isEmpty(): Check if the BST is empty.
    clear(): Clear the entire BST.

2. Traversal Methods:
    inOrderTraversal(): Traverse the tree in in-order (left-root-right).
    preOrderTraversal(): Traverse the tree in pre-order (root-left-right).
    postOrderTraversal(): Traverse the tree in post-order (left-right-root).
    levelOrderTraversal(): Perform level-order traversal (breadth-first search).

3. Helper Methods:
    getHeight(): Get the height (or depth) of the tree.
    getSize(): Get the number of nodes in the tree.
    contains(const T& value): Check if the tree contains a specific value.
    isBalanced(): Check if the tree is balanced.
    getDepth(const T& value): Get the depth of a specific node.

4. Additional Operations:
    isBST(): Check if the tree is a valid binary search tree.
    getSuccessor(const T& value): Find the in-order successor of a given value.
    getPredecessor(const T& value): Find the in-order predecessor of a given value.
    deleteNode(const T& value): Helper function to remove a node, considering the three cases for node deletion.
    balance(): Balance the tree (for self-balancing BSTs like AVL or Red-Black trees).

5. Specialized for Tree Properties:
    printTree(): Print the tree in a visually appealing way (often for debugging).
    isLeaf(const T& value): Check if a specific node is a leaf (i.e., has no children).
    isFull(): Check if the tree is full (every node has either 0 or 2 children).
    isComplete(): Check if the tree is complete (every level except the last is fully filled).
    getLeftChild(const T& value): Get the left child of a given node.
    getRightChild(const T& value): Get the right child of a given node.

6. For Self-Balancing BSTs (like AVL or Red-Black Trees):
    rotateLeft(): Perform a left rotation on a subtree.
    rotateRight(): Perform a right rotation on a subtree.
    rebalance(): Rebalance the tree (for AVL trees or Red-Black trees).

7. Utility Methods (For Debugging/Testing):
    printInOrder(): Print the values of the tree using in-order traversal (usually for testing).
    validateTree(): Validate that the tree is indeed a valid BST.
    getAncestors(const T& value): Get the ancestors of a node.
    getDescendants(const T& value): Get the descendants of a node.

*/