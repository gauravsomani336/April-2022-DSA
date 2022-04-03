class Solution {
public:
    bool checkValidString(string s) {
        int m=s.length();
        //vector<vector<int>dp(m+1,vector<int)
        unordered_map<string, bool>dp;
        return solve(s, 0, 0,m,dp);
    }
    
    bool solve( string s, int cur, int count , int m, unordered_map<string, bool>&dp)
    {
        if(cur>=m && count==0)
        {
            return true;
        }
        
        if(cur>=m && count>=1)
        {
            return false;
        }
        
        if(s[cur]==')' && count==0)
        {
            return false;
        }
        
        string curkey= to_string(cur)+"-"+to_string(count);
        if(dp.find(curkey)!=dp.end())
        {
            return dp[curkey];
        }
        
        bool ways=false;
        if(s[cur]=='(')
        {
            ways= solve(s,cur+1, count+1, m,dp);
        }
        else if(s[cur]==')' )
        {
            ways= solve(s, cur+1, count-1, m,dp);
        }
        else if(s[cur]=='*')
        {
            ways= solve(s, cur+1, count+1, m,dp) || count!=0 && solve(s, cur+1, count-1, m,dp) || solve(s, cur+1, count,m,dp);
        }
        
        return dp[curkey]= ways;
    }
};