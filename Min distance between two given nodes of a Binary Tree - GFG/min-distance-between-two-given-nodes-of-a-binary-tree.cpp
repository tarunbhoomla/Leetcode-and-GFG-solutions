// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root)
         return NULL ;
        
      if(root->data==n1 || root->data==n2)
         return root ;
       
       Node* lnode =lca(root->left,n1,n2) ;
       Node* rnode =lca(root->right,n1,n2) ;
       
       if(lnode==NULL && rnode==NULL)
           return NULL;

       if(lnode && rnode)
          return root ;
       
       return (lnode!=NULL) ? lnode:rnode ;
         
    }
    int height(Node* root , int x)
    {
        if(!root)
          return -1 ;
          
         if(root->data == x)
           return 0 ;
         
        int hl =  height(root->left , x) ;
        int hr = height(root->right , x) ;
        
        if(hl == -1 && hr == -1)
          return -1 ;
        
        if(hl >= 0 )
          return hl+1 ;
        else
          return hr+1 ;
    }
    int findDist(Node* root, int a, int b) 
    {
        Node* ancestor = lca(root , a, b) ;
        // cout<<"LCA is " << ancestor->data<<endl ;
        int h1 = height(ancestor , a) ;
        int h2 = height(ancestor , b) ;
        
        return h1+h2 ;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends