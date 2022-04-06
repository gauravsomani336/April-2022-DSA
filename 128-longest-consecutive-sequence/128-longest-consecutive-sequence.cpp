class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        
        int mx=INT_MIN;
        for(auto it: s)
        {
            
            if(s.find(it-1)!=s.end())
            {
                continue;
            }
            
            int cur=1;
            while(s.find(it+1)!=s.end())
            {
                cur+=1;
                it+=1;
                
            }
            mx=max(mx, cur);
        }
        return mx==INT_MIN?0: mx;
    }
};