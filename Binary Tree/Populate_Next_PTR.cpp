#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right, *next;
};

// ! WRONG CODE --> REFER BELOW CODE
Node *connect(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();

        if (cur == NULL and q.empty())
            break;

        else if (cur == NULL)
        {
            q.push(NULL);
            continue;
        }

        cur->next = q.front();

        if (!cur->left)
            q.push(cur->left);
        if (!cur->right)
            q.push(cur->right);
    }
    return root;
}

// * CORRECT CODE
    
Node *connect(Node *root)
{
    if (!root)
        return root; // Return NULL for an empty tree

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();

        if (cur != NULL)
        {
            cur->next = q.front(); // Set the next pointer

            // Enqueue the children if they exist
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        else if (!q.empty())
        {                 // If cur is NULL and the queue is not empty
            q.push(NULL); // Add a marker for the end of the level
        }
    }
    return root;
}