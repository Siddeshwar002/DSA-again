#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;   
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* reverseLinkedList(Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseLinkedList(head->next);

    Node* front = head->next;
    front->next = head;

    head->next = NULL;

    return newHead;
}

// Approach 1 : 
// Slow and Fast pointers
// Using stack to store first N/2 elements
// Time  : O(N)
// Space : O(1)


// Approach 2 :
// Slow and Fast pointers
// Reversing the second half of the linked list
// Time  : O(2N) 
// Space : O(1)
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) 
        return true; 
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        
        slow = slow->next;  
        fast = fast->next->next;  
    }
    
    // reach the mid portion and start reversing the linked list from the next node after the mid node
    // slow is pointing to middle node
    Node* newHead = reverseLinkedList(slow->next);
    
    Node* first = head;  
    Node* second = newHead;

    while (second != NULL) {
        
        if (first->data != second->data) {
            // found that linked list are not same
            // reverse the linked list to form them back in order
            reverseLinkedList(newHead);  
            return false;
        }

        // keep iterating    
        first = first->next; 
        second = second->next;  
    }

    // successullt traversed the linked list    
    reverseLinkedList(newHead);  
    
    return true;  
}



void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}