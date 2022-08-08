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
    int res = 0 ;
    int fun(TreeNode* root , int targetSum ,long long int curr = 0)
    {
        if(!root)
            return 0 ;
        
        curr += root->val ;
        if(curr == targetSum)
        {
            res++ ;
        }
        return fun(root->left, targetSum ,curr) + fun(root->right , targetSum ,curr) ;
    }
    int pathSum(TreeNode* root, int targetSum)
    {
        if(!root)
            return 0 ;
        
        int left = pathSum(root->left ,targetSum) ;
        int right = pathSum(root->right ,targetSum) ;
        
        int x = fun(root , targetSum) ;
        
        return res ;
    }
};