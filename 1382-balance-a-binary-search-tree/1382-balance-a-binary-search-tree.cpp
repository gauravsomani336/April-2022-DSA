// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void Inorder(vector<TreeNode*>&ans, TreeNode * root)
//     {
//         if(root==NULL)
//         {
//             return ;
//         }
        
//          Inorder(ans, root->left);
//         ans.push_back(root);
//         Inorder(ans,root->right);
        
//     }
//     TreeNode* balanceBST(TreeNode* root) {
//         if(root==NULL)
//             return NULL;
//         vector<TreeNode*>ans;
        
//         Inorder(ans, root);
       
//         TreeNode * temp= solve(ans, 0, ans.size()-1);
//         return temp;
//     }
    
//     TreeNode * solve(vector<TreeNode*>ans, int start, int end)
//     {
//         if(start> end)
//         {
//             return NULL;
//         }
        
//         int mid=(start+end)/2;
        
//         TreeNode * newNode= (ans[mid]);
        
//         newNode->left= solve(ans, start, mid-1);
//         newNode->right= solve(ans, mid+1, end);
        
//         return newNode;
        
//     }
// };

class Solution {
public:
    vector<TreeNode*> inorder;
    void findInorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        findInorder(root->left);
        inorder.push_back(root);
        findInorder(root->right);
    }
    TreeNode* buildTree(int start,int end)
    {
        if(start>end)
            return NULL;
        int mid=(start+end)/2;
        TreeNode* root=inorder[mid];
        root->left=buildTree(start,mid-1);
        root->right=buildTree(mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        if(root==NULL)
            return NULL;
        findInorder(root);
        int n=inorder.size();
        root=buildTree(0,n-1);
        return root;
    }
};