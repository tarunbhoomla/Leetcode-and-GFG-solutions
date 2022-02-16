// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    if(!head1)
      return head2 ;
    if(!head2)
      return head1 ;

    Node* temp = NULL ;
    Node *head_real = NULL ;
    if(head1->data < head2->data)
     {
         temp = head1 ;
         head1 = head1->next ;
     }
    else
    {
     temp = head2 ;
     head2 = head2->next ;
    }
    
    head_real = temp ;
    while(head1 && head2)
    {
        if(head1->data <= head2->data)
        {
            temp->next = head1 ;
            temp = temp->next ;
            head1 = head1->next ;
        }
        else
        {
            temp->next = head2 ;
            temp = temp->next ;
            head2 = head2->next ;
        }
    }
    
    // while(head1)
    // {
    //     temp->next = head1 ;
    //     temp = temp->next ;
    //     head1 = head1->next ;
    // }
    
    if(head1)
      temp->next = head1 ;
    // while(head2)
    // {
    //     temp->next = head2 ;
    //     temp= temp->next ;
    //     head2 = head2->next ;
    // }
    if(head2)
      temp->next = head2 ;
    // temp->next = NULL ;
    return head_real ;
    
    // Node* a= head1;
    // Node* b= head2;
    // Node* ans=NULL;
    // Node * res=NULL;

    // bool f=0;
    // while(a && b)
    // {
    //     if(a->data <= b->data){

    //         if(f==0)
    //         {
    //              ans=a;
    //              res=ans;
    //              f=1;
    //         }else{
    //           ans->next=a; 
    //         }
    //         ans=ans->next;
    //         a=a->next;

    //     }else{
    //           if(f==0)
    //         {
    //              ans=b;
    //              res=ans;
    //              f=1;
    //         }else{
    //         ans->next=b;
    //         }
    //          ans=ans->next;
    //         b=b->next;
    //     }

    // }
    // // if(a!=NULL)
    // // {
    // //     ans->next=a;

    // // }
    // //  if(b!=NULL)
    // // {
    // //     ans->next=b;
    // // }

    // return ans;
}  