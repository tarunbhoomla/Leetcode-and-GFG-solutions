// { Driver Code Starts
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
    
    Node *reverse(Node *head){
        if(!head || !head->next)return head;
        
        Node *new_head=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return new_head;
    }
    
    Node *pos(Node *head,int k){
        int count=0;
        Node *temp=head,*prev=NULL;
        while(temp){
            count++;
            if(count==k && prev)return prev;
            prev=temp;
            temp=temp->next;
            
        }
        
        return NULL;
    }
    
    Node* reverseBetween(Node* head, int m, int n)
    {
        if(!head)return NULL;
        if(m==n)return head;
        Node *rem=NULL;
        Node *start=pos(head,m);
        Node *end=pos(head,n);
        //cout<<end->data;
        if(end->next->next!=NULL)rem=end->next->next;
        
       
        if(end->next->next!=NULL)end->next->next=NULL;
        //to tackle condition if m is head
        if(!start){
            head=reverse(head);
            //cout<<"head";
        }
        else{
            start->next=reverse(start->next);
        }
        
        Node*temp=head;
        while(temp && temp->next){
            temp=temp->next;
        }
        
        temp->next=rem;
    
        
      return head;
        
    }
};
// { Driver Code Starts.

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