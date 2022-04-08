class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map<char,int>mp;
        int res=0;
        int release=0;
        
        for(int acquire=0; acquire<n; acquire++)
        {
            while(mp.find(s[acquire])!=mp.end())
            {
                mp.erase(s[release]);
                release+=1;
            }
            
            mp[s[acquire]]=acquire;
            res=max(res, acquire-release+1);
        }
        
        return res;
    }
};