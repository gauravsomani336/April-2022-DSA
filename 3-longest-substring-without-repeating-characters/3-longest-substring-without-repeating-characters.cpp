class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int res=0;
        int release=0;
        unordered_map<char,int>mp;
        for(int acquire=0;acquire<n;acquire++)
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