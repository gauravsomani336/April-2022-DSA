// https://www.youtube.com/watch?v=pmQAtRZ3CuE

// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/1402272/C%2B%2B-oror-Recursion%2BMemoization

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size())
        {
            return -1;
        }
        vector<vector<int>>dp(11, vector<int>(301, -1));
        int n=jobDifficulty.size();
        return solve(jobDifficulty, n, 0, d, dp);
        
    }
    
    
    int solve(vector<int>&nums, int n, int idx, int d, vector<vector<int>>&dp)
    {
        if(d==1)
        {
            int mx=0;
            for(int i=idx;i<n;i++)
            {
                mx=max(mx, nums[i]);
            }
            return mx;
        }
        
        if(dp[d][idx]!=-1)
        {
            return dp[d][idx];
        }
        
        int mx=0;
        int res=INT_MAX;
        
        for(int i=idx;i<n-d+1;i++)
        {
            mx=max(mx, nums[i]);
            res=min(res, mx+solve(nums, n, i+1, d-1, dp));
        }
        
        return dp[d][idx]=res;
    }
};