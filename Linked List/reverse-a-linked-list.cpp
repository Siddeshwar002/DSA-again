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

// Approach 1 : Iterative Code 
// 3 Pointer Approach 
Node* reverseLinkedList(Node *head)
{
   Node* temp = head;  
   
   Node* prev = NULL;  
   
   while(temp != NULL){  
       Node* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front; 
   }
   
   return prev;  
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Approach 2 : Recursive code : 
// Short code
// Optimal code

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