class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>comb;
        vector<vector<int>>res;
        
        solve(1, n, k, comb, res);
        return res;
    }
    
    void solve(int start, int last, int k, vector<int>&comb, vector<vector<int>>&res)
    {
        if(comb.size()==k)
        {
            res.push_back(comb);
            return ;
        }
        
        for(int i=start;i<=last;i++)
        {
            comb.push_back(i);
            
            solve(i+1, last, k, comb, res);
            
            comb.pop_back();
        }
    }
};