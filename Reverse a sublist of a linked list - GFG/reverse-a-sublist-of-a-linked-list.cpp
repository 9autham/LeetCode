//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        Node* dummy=new Node(-1);
        dummy->next=head;
        head=dummy;
        int maxi=max(m,n);
        Node*prev=dummy;
        Node*after=dummy;
        Node*start=head;
        Node*end=head;
        int i=0;
        Node*p=head;
        while(i<=n){
            if(i==(m-1)){
                prev=p;
            }
            if(i==m){
                start=p;
            }
            if(i==n){
                end=p;
            }
            i++;
            p=p->next;
        }
        after=end->next;
        Node*pvs=NULL;
        Node*curr=start;
        Node*nxt;
        while(curr!=after){
            // cout<<curr->data<<" ";
            nxt=curr->next;
            curr->next=pvs;
            pvs=curr;
            curr=nxt;
        }
        prev->next=end;
        start->next=after;
        return dummy->next;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends