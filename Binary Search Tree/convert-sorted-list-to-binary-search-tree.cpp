#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    ListNode *findMiddlenode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnecting the List
        if (prev != nullptr)
            prev->next = nullptr;

        return slow;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *mid = findMiddlenode(head);
        TreeNode *root = new TreeNode(mid->val);
        if (mid == head)
            return root;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};

// Fast than the previous code :
// Combining the two functions into one single function

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *root = new TreeNode(slow->val);

        // Base case: If only one element in the list, return the root
        if (prev == nullptr)
            return root;

        // Disconnect the list at the middle to split it into two halves
        prev->next = nullptr;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
