//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    int len(Node*head){
        Node*p=head;
        int cnt=0;
        while(p){
            p=p->next;
            cnt++;
        }
        return cnt;
    }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        int l=len(head);
        k=k%l;
        if(k==0)
        return head;
        Node*p=head;
        Node*q=head;
        while(q->next){
            q=q->next;
        }
        k--;
        while(k--){
            p=p->next;
        }
        Node*ans=p->next;
        q->next=head;
        p->next=NULL;
        return ans;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends