#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    void moveToFront(Node *node)
    {
        if (node == head)
        {
            return;
        }

        if (node == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->prev = nullptr;
        node->next = head;
        head->prev = node;
        head = node;
    }

    void evict()
    {
        cache.erase(tail->key);
        Node *temp = tail;
        tail = tail->prev;
        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    int get(int key)
    {
        if (cache.find(key) == cache.end())
        {
            return -1;
        }

        Node *node = cache[key];
        moveToFront(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            moveToFront(node);
        }
        else
        {
            Node *newNode = new Node(key, value);
            cache[key] = newNode;

            // * if this was the first element
            if (!head)
            {
                head = newNode;
                tail = newNode;
            }

            // * Insert in the beginning
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            // * if size overflow delete the last element
            if (cache.size() > capacity)
            {
                evict();
            }
        }
    }

    ~LRUCache()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
