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
    #define Not_needed 1
    #define No_camera 0
    #define Has_camera 2
    
    int ans=0;
    
    int dfs(TreeNode * root)
    {
        
        
        if(root==NULL)
        {
            return Not_needed;
        }
        
            int l=dfs(root->left);
            int r=dfs(root->right);
        
        if(l==No_camera || r==No_camera)
        {
            ans+=1;
            return Has_camera;
        }
        
        else if(l==Has_camera || r==Has_camera)
        {
            return Not_needed;
        }
        else    // when both left and right has condition not needed
        {
           return  No_camera;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==No_camera)
        {
            ans+=1;
        }
        
        return ans;
    }
};