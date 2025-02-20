//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:
    Node*middle(Node*head){
        if(head==NULL or head->next==NULL)return head;
        Node*slow=head;
        Node*fast=head->next;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node*rev(Node*head){
        Node*prev=NULL;
        Node*curr=head;
        Node*nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(Node* head) {
        // Your code here
        Node*ans=new Node(-1);
        Node*tail=ans;
        Node*p=head;
        Node*x=middle(head);
        Node*q=x->next;
        x->next=NULL;
        q=rev(q);
        while(p and q){
            tail->next=p;
            tail=tail->next;
            p=p->next;
            tail->next=q;
            tail=tail->next;
            q=q->next;
        }
        while(p){
            tail->next=p;
            p=p->next;
            tail=tail->next;
        }
        // while(q){
        //     tail->next=q;
        //     tail=tail->next;
        //     q=q->next;
        // }
        // head=ans->next;
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends