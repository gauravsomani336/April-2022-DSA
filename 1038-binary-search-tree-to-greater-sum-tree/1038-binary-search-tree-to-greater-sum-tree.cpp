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
    TreeNode* bstToGst(TreeNode* root) {
        
       convert(root, 0);
        return root;
       
    }
    
    int convert(TreeNode * root, int sum)
    {
        if(root==NULL)
        {
            return sum;
        }
        
        int r=convert(root->right, sum);
        
      root->val= root->val+ r;
        
        int l=convert(root->left, root->val);
          // root->val= root->val+ r;
        return l;
        
        
    }
};