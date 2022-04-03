class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto it: nums1)
        {
            mp[it]+=1;
        }
        
        for(auto x: nums2)
        {
           if(mp[x]>=1) 
           {
               res.push_back(x);
               mp[x]-=1;
           }
        }
        
        return res;
    }
};