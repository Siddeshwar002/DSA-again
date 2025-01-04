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

Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next; 
    }

    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    return dummyNode->next;
}

Node* findMiddle(Node* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    // this change is necessary to always make sure that the slow lands on the middle node
    // Node* fast = head; fails the case when there are only 2 nodes in the list 
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* sortLL(Node* head){

    // if it's a single node - just return that node 
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    
    // find the middle node
    Node* middle = findMiddle(head);
    
    // get the right portion
    Node* right = middle->next;

    // mark the current node->next = null
    middle->next = nullptr;

    // assign left to the starting node
    Node* left = head;
    
    // Split the lists left and right 
    // divide
    left = sortLL(left);
    right = sortLL(right);
    
    // once they are back in soreted order 
    // merge them
    return mergeTwoSortedLinkedLists(left, right);
}
