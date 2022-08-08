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
//     int res = 0 ;
//     int fun(TreeNode* root , int targetSum ,long long int curr = 0)
//     {
//         if(!root)
//             return 0 ;
        
//         curr += root->val ;
//         if(curr == targetSum)
//         {
//             res++ ;
//         }
//         return fun(root->left, targetSum ,curr) + fun(root->right , targetSum ,curr) ;
//     }
//     int pathSum(TreeNode* root, int targetSum)
//     {
//         if(!root)
//             return 0 ;
        
//         int left = pathSum(root->left ,targetSum) ;
//         int right = pathSum(root->right ,targetSum) ;
        
//         int x = fun(root , targetSum) ;
        
//         return res ;
//     }
       void fun(TreeNode* root ,int target , unordered_map<long long,int>&mp ,int &res ,long long curr)
       {
           if(!root)
               return ;
           
           curr += root->val ;
           
           if(mp.find(curr-target) != mp.end())
           {
               res += mp[curr-target] ;
           }
           mp[curr]++ ;
           
           fun(root->left ,target ,mp ,res ,curr) ;
           fun(root->right ,target ,mp ,res ,curr) ;
           
           mp[curr]-- ;
           // curr -= root->val ;
       }
    
       int pathSum(TreeNode* root, int targetSum)
       {
           if(!root)
               return 0 ;
           unordered_map<long long,int>mp ;
           mp[0]=1 ;
           int res = 0 ;
           fun(root ,targetSum ,mp ,res ,0) ;
           
           return res ;
       }
};