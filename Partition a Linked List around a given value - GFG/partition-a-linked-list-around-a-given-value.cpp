// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
struct Node* partition(struct Node* head, int x) 
{
    
    if(!head) 
       return head;
       
    Node* currentNode = head;
    Node* smaller, *smallerHead;
    Node* equalHead, *equal;    
    Node* greater, *greaterHead;
 
    
    smaller = smallerHead = new Node(0);
    greater = greaterHead = new Node(0);
    equal = equalHead = new Node(0);
    
    while(currentNode) {
        if(currentNode->data < x){
            smaller->next = currentNode;
            smaller = smaller->next;
        } 
        else if(currentNode->data == x)
        {
            equal->next = currentNode;
            equal = equal->next;
        } 
        else 
        {
            greater->next = currentNode;
            greater = greater->next;
        }
        currentNode = currentNode->next;
    }

    greater->next = nullptr;
    equal->next = greaterHead->next;
    smaller->next = equalHead->next ;
    
    return smallerHead->next ;
}
// struct Node* partition(struct Node* head, int x) 
// {
//     Node* curr = head ;
//     Node* less = new Node(-1) ;
//     Node* smallest = less ;
//     while(curr)
//     {
//         if(curr->data < x )
//           {
//               less->next = curr ;
//               less = less->next ;
              
//           }
         
//          curr = curr->next ;
//     }
//     Node* curr3 = head ;
//     Node* equal = new Node(-1) ;
//     Node* equalest = big ;
//     while(curr3)
//     {
//         if(curr3->data > x )
//           {
//               equal->next = curr3 ;
//               equal = equal->next ;
              
//           }
         
//          curr3 = curr3->next ;
//     }   
    
//     curr3->next
    
//     Node* curr2 = head ;
//     Node* big = new Node(-1) ;
//     Node* biggest = big ;
//     while(curr2)
//     {
//         if(curr2->data > x )
//           {
//               big->next = curr2 ;
//               big = big->next ;
              
//           }
         
//          curr2 = curr2->next ;
//     }
    
//     // Node* tempest1 = smallest ;
//     // Node* tempest2 = biggest ;
    
//     smallest = smallest->next ;
//     biggest = biggest->next ;
//     // tempest1 =NULL ;
//     // tempest2 = NULL ;
//     // delete(tempest1) ;
//     // delete(tempest2) ;
//     curr->next = biggest ;
//     return head ;
    
// }