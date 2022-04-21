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
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        vector<string>ans;
        
        solve(root, "", ans);
        return ans;
    }
    
    void solve(TreeNode * root, string cur, vector<string>&ans)
    {
        if(root==NULL)
        {
            
            return ;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            cur+=to_string(root->val);
            ans.push_back(cur);
        }
        
        solve(root->left, cur+to_string(root->val)+"->", ans);
        solve(root->right, cur+to_string(root->val)+"->" , ans);
        
        
        
    }
};