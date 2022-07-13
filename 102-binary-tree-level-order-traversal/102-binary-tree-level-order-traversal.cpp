/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
             return {} ;
        vector<vector<int>>res ;
        queue<TreeNode *>q ;
        q.push(root) ;
        while(!q.empty())
        {
            vector<int>temp ;
            int n = q.size() ;
            for(int i=0 ;i<n ;i++)
            {
                TreeNode* nodde = q.front() ;
                q.pop() ;
                
                temp.push_back(nodde->val) ;
                if(nodde->left)
                     q.push(nodde->left);
                if(nodde->right)
                     q.push(nodde->right) ;
            }
            
            res.push_back(temp) ;
        }
        
        return res ;
    }
};