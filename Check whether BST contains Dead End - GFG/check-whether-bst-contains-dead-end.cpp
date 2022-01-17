// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
unordered_map<int,int> m;
vector<int> vec;

void leafNode(Node* root,vector<int> &vec)
{
if(!root->left and !root->right)
{
	vec.push_back(root->data);
	return;
}
if(root->left) leafNode(root->left,vec);
if(root->right) leafNode(root->right,vec);
}

bool helper(Node* root)
{
    int n= vec.size();
    for(int i=0 ; i<n ; i++)
    {
         if(m[vec[i]-1] and m[vec[i]+1])
        {
            return true;
        }
    }
    return false;
}

void inorder(Node* root)
{
    if(root==NULL)
    return ;
  
    inorder(root->left);
    m[root->data] = 1;
    inorder(root->right);
}

bool isDeadEnd(Node *root)
{
    m.clear();
    vec.clear();
    leafNode(root,vec);
    m[0]=1;
    inorder(root);

    
    if(helper(root))
    {
        return true;
    }
    return false;
}