class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto x:nums1)
        {
            if(mp.find(x)==mp.end())
            {
                mp[x]=1;
            }
        }
        
        for(auto y: nums2)
        {
            if(mp.find(y)!=mp.end())
            {
                res.push_back(y);
                mp.erase(y);
            }
        }
        return res;
    }
};