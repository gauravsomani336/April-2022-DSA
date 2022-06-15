class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>cidx;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='|')
            {
                cidx.push_back(i);
            }
        }
        
        vector<int>res;
        
        for(auto it : queries)
            
        {
            int l=it[0];
            int r= it[1];
            int firstidx= lower_bound(cidx.begin(), cidx.end(), l ) - cidx.begin();
            int lastidx= upper_bound(cidx.begin(), cidx.end(), r)- cidx.begin()-1;
            
            if(lastidx<= firstidx)
            {
                res.push_back(0);
                continue;
            }
            
            int temp= (cidx[lastidx]- cidx[firstidx]+1)- (lastidx-firstidx+1);
            res.push_back(temp);
            
        }
        
        return res;
    }
};