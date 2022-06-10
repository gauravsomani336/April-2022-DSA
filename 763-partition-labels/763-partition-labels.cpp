class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>hash(26, 0);
        for(int i=0;i<s.length();i++)
        {
            hash[s[i]-'a']=i;
        }
        
        int start=0;
        vector<int>res;
        int last=INT_MIN;
        
        for(int i=0;i<s.length();i++)
        {
            last=max(last, hash[s[i]-'a']);
            if(last==i)
            {
                res.push_back(last-start+1);
                start=last+1;
            }
        }
        
        return res;
    }
};