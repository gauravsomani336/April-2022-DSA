class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>perm;
        vector<vector<int>>res;
        vector<bool>used(nums.size(), false);
        solve(nums,perm,res, used);
        return res;
    }
    
   void solve(vector<int>& nums, vector<int>& perm, vector<vector<int>>&res,vector<bool>&used )
    {
        if(perm.size()==nums.size())
        {
            res.push_back(perm);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!used[i])   //valid choices
            {
                //make choices
                used[i]=true;
                perm.push_back(nums[i]);
                
                solve(nums,perm, res, used);
                //undo choices
                
                used[i]=false;
                perm.pop_back();
                
            }
        }
    }
};