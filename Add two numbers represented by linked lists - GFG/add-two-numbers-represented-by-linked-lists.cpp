//{ Driver Code Starts
// driver

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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* rev(Node*head){
        Node*prev=NULL,*curr=head,*nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node*p=rev(first);
        Node*q=rev(second);
        Node*head=NULL;
        Node*tail=NULL;
        int sum=0;
        int rem=0;
        int carry=0;
        while(p and q){
            sum=p->data+q->data+carry;
            rem=sum%10;
            carry=sum/10;
            if(head==NULL){
                head=new Node(rem);
                tail=head;
            }
            else{
                tail->next=new Node(rem);
                tail=tail->next;
            }
            p=p->next;
            q=q->next;
        }
        while(p){
            sum=p->data+carry;
            rem=sum%10;
            carry=sum/10;
            if(head==NULL){
                head=new Node(rem);
                tail=head;
            }
            else{
                tail->next=new Node(rem);
                tail=tail->next;
            }
            p=p->next;
        }
        while(q){
            sum=q->data+carry;
            rem=sum%10;
            carry=sum/10;
            if(head==NULL){
                head=new Node(rem);
                tail=head;
            }
            else{
                tail->next=new Node(rem);
                tail=tail->next;
            }
            q=q->next;
        }
        if(carry){
            tail->next=new Node(carry);
        }
        return rev(head);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends