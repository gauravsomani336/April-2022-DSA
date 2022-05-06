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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        addLeftTree(root, st);
        
        while(!st.empty())
        {
            TreeNode* cur= st.top();
            st.pop();
            ans.push_back(cur->val);
            if(cur->right!=NULL)
            {
                addLeftTree(cur->right, st);
            }
        }
        
        return ans;
    }
    
    void addLeftTree(TreeNode * node , stack<TreeNode*>&st)
    {
        st.push(node);
        
        while(node->left!=NULL)
        {
            st.push(node->left);
            node=node->left;
        }
    }
};