class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it: nums)
        {
            mp[it]+=1;
        }
        
        vector<int>perm;
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        solve(nums, perm, res, mp);
        return res;
    }
    
    void solve(vector<int>&nums, vector<int>&perm, vector<vector<int>>&res, unordered_map<int, int>&mp)
    {
        if(perm.size()==nums.size())
        {
            res.push_back(perm);
            return ;
        }
        
        for(int i=0;i<nums.size(); i++)
        {
            if(mp[nums[i]]==0  || (i!=0 && nums[i]==nums[i-1]))
            {
                continue;
            }
            
            perm.push_back(nums[i]);
            mp[nums[i]]-=1;
            
            solve(nums, perm, res, mp);
            
           
            mp[nums[i]]+=1;
             perm.pop_back();
        }
        
        
        
    }
    // void backtrack2(vector<int>& nums, vector<int>& temp,
    //               vector<vector<int>>& res, unordered_map<int, int>& freq) {
    //     if (temp.size() == nums.size()) {
    //         res.push_back(temp);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (freq[nums[i]] == 0 || (i != 0 && nums[i] == nums[i - 1])) continue;
    //         temp.push_back(nums[i]);
    //         freq[nums[i]]--;
    //         backtrack2(nums, temp, res, freq);
    //         freq[nums[i]]++;
    //         temp.pop_back();
    //     }
    // }
};