class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<string>> solveNQueens(int n) {
     vector<string>board(n, string(n, '.'));
        unordered_set<int>cols;
         unordered_set<int>pos;
         unordered_set<int>neg;
         vector<vector<string>>res;
        
        backtrack(n,0, board, cols, pos, neg);
        return ans;
    }
    
    void backtrack(int n,int r,  vector<string>&board,  unordered_set<int>&cols,  unordered_set<int>&pos,  unordered_set<int>&neg)
    {
        if(r==n)
        {
            ans.push_back(board);
            return ;
        }
        
        for(int j=0;j<n;j++)
        {
            if(cols.find(j)!=cols.end() || pos.find(r+j)!=pos.end() || neg.find(r-j)!=neg.end())
            {
                continue;
            }
            
            // if(cols.count(j)==1 || pos.find(r+j)==1 || neg.find(r-j)==1)
            // {
            //     continue;
            // }
            
            cols.insert(j);
            pos.insert(r+j);
            neg.insert(r-j);
            board[r][j]='Q';
            
            backtrack(n,r+1, board, cols, pos, neg);
            
            cols.erase(j);
            pos.erase(r+j);
            neg.erase(r-j);
            board[r][j]='.';
        }
    }
};