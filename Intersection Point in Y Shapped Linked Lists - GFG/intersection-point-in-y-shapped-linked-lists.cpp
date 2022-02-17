// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
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

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    int size1 = 0 ;
    int size2 = 0 ;
    
    Node* temp1 = head1 ;
    Node* temp2 = head2 ;
    
    while(temp1)
    {
        size1++ ;
        temp1 = temp1->next ;
    }
    while(temp2)
    {
        size2++ ;
        temp2 = temp2->next;
    }
    int diff = 0 ;
    if(size1>size2)
    {
        diff = size1-size2 ;
        
        while(diff--)
          {head1 = head1->next ;}
    }
    else if(size2 >size1)
    {
        diff = size2-size1 ;
        
        while(diff--)
          {head2 = head2->next ;}
    }
    
    while(head1!=head2)
    {
        head1 = head1->next ;
        head2 = head2->next ;
    }
    
    if(!head1 || !head2)
       return -1 ;
       
    return head1->data ;
    
}

