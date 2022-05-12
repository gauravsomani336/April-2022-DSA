class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0;
        int right=0;
        
        if(s2.size()< s1.size())
        {
            return false;
        }
        vector<int>hash(26,0);
        vector<int>phash(26,0);
        
        
        
        while(right<s1.size())
        {
            phash[s1[right]-'a']+=1;
            hash[s2[right]-'a']+=1;
            right+=1;
        }
        
        right-=1;
        
        while(right < s2.size())
        {
            if(phash==hash)
            {
                return true;
            }
            
            right+=1;
            if(right<s2.size())
            {
                hash[s2[right]-'a']+=1;
                hash[s2[left]-'a']-=1;
                
            }
            left+=1;
        }
        
        return false;
    }
};