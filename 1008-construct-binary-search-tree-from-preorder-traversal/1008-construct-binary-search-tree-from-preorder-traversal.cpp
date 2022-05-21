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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx[1]={0};
        
        return solve(preorder, idx, 1001);
    }
    
    TreeNode * solve(vector<int>&preorder, int idx[] , int limit)
    {
        if(idx[0]>= preorder.size() ||  preorder[idx[0]]> limit)
        {
            return NULL;
        }
        
        TreeNode * temp= new TreeNode(preorder[idx[0]]);
        idx[0]+=1;
        temp->left= solve(preorder, idx, temp->val-1);
        temp->right= solve(preorder, idx, limit);
        
        return temp;
    }
}; 