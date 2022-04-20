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
    bool c= true;
    bool isUnivalTree(TreeNode* root) {
        int x=root->val;
        check(root, x);
        
        return c;
    }
    
    void check(TreeNode * root, int x)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->val!=x)
        {
            c= false;
            
        }
        
        check(root->left, x);
        check(root->right, x);
        
    }
};