#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    unordered_map<Node *, Node *> copiedNodes;

    // First Pass: Create a copy of each node and store in the hash map
    Node *original = head;
    while (original != nullptr)
    {
        Node *copy = new Node(original->val);
        copiedNodes[original] = copy;
        original = original->next;
    }

    // Second Pass: Update next and random pointers of copied nodes
    original = head;
    while (original != nullptr)
    {
        copiedNodes[original]->next = copiedNodes[original->next];
        copiedNodes[original]->random = copiedNodes[original->random];
        original = original->next;
    }

    // Return the head of the copied linked list
    return copiedNodes[head];
}
