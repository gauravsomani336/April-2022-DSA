class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++)
        {
            string s=strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(s);
            
        }
        
        for(auto it:mp)
        {
            res.push_back(it.second);
        }
        
        return res;
    }
};