class Solution {
public:
    struct comp{
        
        bool operator()(pair<int,int>&a,  pair<int,int>&b)
        {
            return a.second>b.second;
        }
    }cmpare;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(auto it: nums)
        {
            mp[it]+=1;
        }
        
        vector<pair<int,int>>vec;
        for(auto it: mp)
        {
            vec.push_back(it);
        }
        
        sort(vec.begin(), vec.end(), cmpare);
        
       for(auto it: vec)
        {
            if(k>0)
            {
                res.push_back(it.first);
                k-=1;
            }
        }
        
        return res;
    }
};