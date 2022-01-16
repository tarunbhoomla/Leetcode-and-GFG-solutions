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
TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        
        if(root->val >key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
           return root;
        }
       if(root->val==key)
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
             if(root->right==NULL && root->left!=NULL)
            {
                TreeNode* temp =root->left;
                delete root;
                return temp;
            }
            if(root->left==NULL && root->right!=NULL)
            {
                TreeNode* temp =root->right;
                delete root;
                return temp;
            }
            
            if(root->right!=NULL && root->left!=NULL)
            {
                TreeNode* replace=root->right;
                while(replace->left!=NULL)
                {
                    replace=replace->left;
                }
                root->val=replace->val;
                root->right = deleteNode(root->right,replace->val);
                return root;
                    
            }
            }
        
   return root;
   }
};