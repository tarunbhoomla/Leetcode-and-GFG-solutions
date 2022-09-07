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
    string tree2str(TreeNode* root) 
    {
         if(!root)
         {
             return "" ;
         }
         string leftt = tree2str(root->left) ;
         string rightt = tree2str(root->right) ;
        
         string str = "" ;
        str += to_string(root->val) ;
        if(leftt=="" && rightt !="")
        {
            str += "()" ;
        }
        if(leftt != "")
        {
            str += "(" + leftt + ")" ;
        }
        if(rightt != "")
        {
            str += "(" + rightt + ")" ;
        }
         
        
        return str ;
    }
};