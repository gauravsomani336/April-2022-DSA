class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        int st=0, end=0;
        int n=nums.size();
        unordered_set<int>mp;
        int mx=INT_MIN;
        
        while(end<n)
        {
            while(mp.find(nums[end])!=mp.end())
            {
                mp.erase(nums[st]);
                
                sum-=nums[st];
                st+=1;
            }
            mp.insert(nums[end]);
            sum+=nums[end];
            mx=max(mx, sum);
            end+=1;
        }
        
        return mx;
    }
};