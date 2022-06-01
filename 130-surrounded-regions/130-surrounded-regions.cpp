class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j)
    {
        return !(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]!='O');
    }
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if(isValid(board, i, j)==false)
        {
            return ;
        }
        
        board[i][j]='#';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
        
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c= board[0].size();
        
        // for traversing first amd last row
        
        for(int j=0;j<c;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(board, 0, j);
            }
            
            if(board[r-1][j]=='O')
            {
                dfs(board, r-1, j);
            }
        }
        
        for(int i=0;i<r;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board, i, 0);
            }
            
            if(board[i][c-1]=='O')
            {
                dfs(board, i, c-1);
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                // if(board[i][j]=='#')
                // {
                //     board[i][j]='O';
                // }
                // else
                // {
                //     board[i][j]='X';
                // }
                
                if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
            }
        }
        
        
    }
};