// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
public:

vector<int>ans;
void Preorder(TreeNode *root)
{
    if(root==NULL)
    {
        return ;
        
    }
    
    ans.push_back(root->val);
    Preorder(root->left);
    Preorder(root->right);
}
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here\\\
        
        TreeNode * root= solve(nums, 0, nums.size()-1);
        
        Preorder(root);
        return ans;
       
    }
    
    TreeNode * solve(vector<int>nums, int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
         
        
        int mid=start+(end-start)/2;
        
        TreeNode * temp= new TreeNode(nums[mid]);
        
        temp->left= solve(nums, start, mid-1);
        temp->right= solve(nums, mid+1, end);
        
        return temp;
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends