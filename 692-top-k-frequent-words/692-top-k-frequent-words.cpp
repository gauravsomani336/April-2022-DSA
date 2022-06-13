
class Solution {
public:
    struct cmp{
        
        bool operator()(pair<string, int>&a, pair<string, int>&b)
        {
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
           
             return a.second > b.second;
            
        }
        
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        for(auto it: words)
        {
            mp[it]+=1;
        }
        
        priority_queue<pair<string, int> , vector<pair<string, int>>, cmp >minH;
        int cnt=0;
        
        for(auto it: mp)
        {
            minH.push(it);
             cnt+=1;   
            if(cnt>k)
            {
                minH.pop();
                cnt-=1;
            }
                
        }
        
        vector<string>res;
        while(!minH.empty())
        {
            auto it= minH.top();
            res.push_back(it.first);
            minH.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};