class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int size=nums.size()-k;
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto it: nums)
        {
            mp[it]+=1;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        
        for(auto it: mp)
        {
             pq.push({it.second, it.first});
            if( pq.size()>k)
            {
                pq.pop();
            }
            
           
        }
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
        
    }
};