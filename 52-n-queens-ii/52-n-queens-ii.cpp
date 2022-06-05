class Solution {
public:
    int count=0;
    int totalNQueens(int n) {
       unordered_set<int>cols;
       unordered_set<int>pos;
    unordered_set<int>neg;
        vector<vector<int>>board(n, vector<int>(n,0));
        
        backtrack(n, 0, board, cols, pos, neg);
        return count;
    }
    
    void backtrack(int n, int r, vector<vector<int>>&board, unordered_set<int>&cols, unordered_set<int>&pos, unordered_set<int>&neg)
    {
        if(r==n)
        {
            count+=1;
            return;
        }
        
        
        
        for(int c=0;c<n;c++)
        {
            if(cols.find(c)!=cols.end() || pos.find(r+c)!=pos.end() || neg.find(r-c)!=neg.end())
            {
                continue;
            }
            cols.insert(c);
            pos.insert(r+c);
            neg.insert(r-c);
            board[r][c]=1;
            
            backtrack(n, r+1, board, cols, pos, neg);
            
            cols.erase(c);
            pos.erase(r+c);
            neg.erase(r-c);
            board[r][c]=0;
        }
    }
};