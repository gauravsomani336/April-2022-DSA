class Solution {
public:
    bool checkEquals(bitset<26>&a, bitset<26>&b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i] && b[i])
            {
                return true;
            }
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0;
        vector<bitset<26> >mp(n);
        for(int i=0;i<n;i++)
        {
              
            for(auto &ch: words[i])
            {
                mp[i][ch-'a']=1;
                
                
            }
            
            for(int j=0;j<i;j++)
            {
                if(!checkEquals(mp[i], mp[j]))
                {
                    ans=max(ans, int(size(words[i])* size(words[j])));
                }
            }
            
            
        }
        return ans;
    }
};