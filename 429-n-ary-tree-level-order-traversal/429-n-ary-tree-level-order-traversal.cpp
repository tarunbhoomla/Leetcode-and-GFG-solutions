/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)
            return {} ;
        vector<vector<int>> res ;
        queue<Node*> q ;
        q.push(root) ;
        
        while(!q.empty())
        {
            int n = q.size() ;
            vector<int> tempoo ;
            tempoo.clear();
            for(int i=0 ;i<n ;i++)
            {
                Node* temp = q.front();
                q.pop() ;
                
                tempoo.push_back(temp->val) ;
                for(auto it:temp->children)
                {
                    if(it != NULL)
                        q.push(it) ;
                } 
            }
            
            res.push_back(tempoo) ;
        }
        
        return res ;
    }
};