class Solution {
public:
    int countChar(string s, char ch)
    {
        int cnt=0;
        for(auto it: s)
        {
            if(it==ch)
            {
                cnt+=1;
            }
        }
        return cnt;
    }
    
    bool isSubset(string s, vector<int>freq)
    {
        for(char i='a';i<='z';i++)
        {
            if(countChar(s, i)<freq[i-'a'])
            {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq(26,0);
        vector<string>res;
        for(auto c: words2)
        {
            for(char i='a';i<='z';i++)
            {
                freq[i-'a']=max(freq[i-'a'], countChar(c, i));
            }
        }
        
        for(auto s: words1)
        {
            if(isSubset(s, freq))
            {
                res.push_back(s);
            }
        }
        
        return res;
    }
};