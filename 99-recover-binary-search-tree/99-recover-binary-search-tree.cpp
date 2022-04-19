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
    
    TreeNode * firstel= NULL;
    TreeNode * secondel=NULL;
    TreeNode * prevel=NULL;
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        int temp=firstel->val;
        firstel->val= secondel->val;
        secondel->val=temp;
    }
    
    void inorder(TreeNode *root)
    {
        if(root==NULL)
        {
            return ;
        }
        
        inorder(root->left);
        
        if(prevel!=NULL)
        {
            if(firstel==NULL && prevel->val>root->val)
            {
                firstel=prevel;
            }
        }
        
        if(firstel!=NULL && prevel->val>root->val)
        {
            secondel=root;
        }
        
        prevel=root;
        
        inorder(root->right);
    }
};