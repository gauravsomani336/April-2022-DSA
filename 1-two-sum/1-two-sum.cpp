class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            
            int temp=target-nums[i];
            
            if(mp.find(temp)!=mp.end())
            {
                res.insert(res.end(),{i, mp[temp]});
            }
            
            mp[nums[i]]=i;
            
        }
        
        return res;
        
    }
};