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
    int countNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int count=1;
         solve(root, count);
        return count;
    }
    
     void  solve(TreeNode * root, int & cnt)
     {
         if(root==NULL)
         {
             return ;
         }
         
         if(root->left!=NULL)
         {
             cnt+=1;
             solve(root->left, cnt);
         }
         
         if(root->right!=NULL)
         {
             cnt+=1;
             solve(root->right, cnt);
         }
     }
};