// { Driver Code Starts
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
    struct Node* reverseList(struct Node *head)
    {
        Node* prev = NULL ;
        Node* temp = head->next ;

        while(temp)
        {
            head->next = prev ;
            prev = head ;
            head = temp ;
            temp = head->next ;
        }
        head->next = prev ;
        
        return head ;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseList(first);
        second = reverseList(second) ;

        int carry = 0 ;
        int div = 0 ;
        
        int sum = first->data + second->data ;
        div = (sum+carry)%10 ;
        carry = (sum+carry)/10 ;
        Node* res = new Node( div) ;
            
        first = first->next ;
        second = second->next ;
        Node* head_final = res ;
        while(first && second)
        {
            int sum = first->data + second->data ;
            div = (sum+carry)%10 ;
            carry = (sum+carry)/10 ;
            res->next = new Node( div) ;
            res = res->next ;
            first = first->next ;
            second = second->next ;
            
        }
        while(first)
           {
            int sum = first->data ;
            div = (sum+carry)%10 ;
            carry = (sum+carry)/10 ;
            res->next = new Node( div) ;
            res = res->next ;
            first = first->next ;

           }
        while(second)
           {
            int sum = second->data ;
            div = (sum+carry)%10 ;
            carry = (sum+carry)/10 ;
            res->next = new Node( div) ;
            res = res->next ;
            second = second->next ;

           }
         if(carry != 0)
           res->next = new Node(carry) ;
        //  res = res->next ;
        //  res->next = NULL ;
         
         head_final = reverseList(head_final) ;
         
         
         return head_final ;
         
           
    }
};


// { Driver Code Starts.

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