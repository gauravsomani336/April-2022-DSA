class Solution {
public:
    vector<vector<string>>res;
    string getString(string s , int i, int j)
    {
        string r="";
        while(i<=j)
        {
            r+=s[i];
            i+=1;
        }
        return r;
    }
    
    bool checkPalindrome(string p)
    {
        int i=0;
        int j=p.length()-1;
        
        while(i<=j)
        {
            if(p[i]!=p[j])
            {
                return false;
            }
            i+=1;
            j-=1;
        }
        
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string>pal;
        
        solve(s, 0, pal);
        return res;
    }
    
    void solve(string s, int i, vector<string>&pal)
    {
        int n=s.length();
        
        if(i>=n)
        {
            res.push_back(pal);
            return ;
        }
        
        for(int j=i;j<n;j++)
        {
            string p= getString(s, i, j);
            
            if(checkPalindrome(p))
            {
                pal.push_back(p);
                solve(s, j+1, pal);
                pal.pop_back();
            }
        }
    }
};