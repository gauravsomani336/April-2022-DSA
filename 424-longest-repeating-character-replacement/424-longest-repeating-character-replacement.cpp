class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int mostRepeating=INT_MIN;
        int len=INT_MIN;
        
        unordered_map<char,int>mp;
        int start=0;
        for(int end=0;end<n;end++)
        {
            mp[s[end]]+=1;
           mostRepeating= max(mostRepeating, mp[s[end]]);
            
            if(end-start+1- mostRepeating > k)
            {
                mp[s[start]]-=1;
                start+=1;
            }
            
            len=max(len, end-start+1);
            
        }
        
        return len;
    }
};