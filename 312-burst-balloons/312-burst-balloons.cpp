class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(),1);
        
        vector<vector<int>>dp(301, vector<int>(301,-1));
        
        return dfs(nums, 1, nums.size()-2,dp);
        
        
    }
    
    
    int dfs(vector<int>&nums, int l, int r, vector<vector<int>>&dp)
    {
        if(l>r)
        {
            return 0;
        }
        
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        
        int coins=0;
        int mx=0;
        for(int i=l;i<r+1;i++)
        {
           coins= nums[l-1]*nums[i]*nums[r+1];
           coins+= dfs(nums,l, i-1,dp)+ dfs(nums,i+1, r,dp);
            mx=max(mx, coins);
        }
        
        return dp[l][r]= mx;
    }
};