class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int i, int j)
    {
        return !(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!=1);
    }
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(isValid(grid, i, j)==true)
        {
            grid[i][j]=0;
            
            return 1+ dfs(grid, i+1, j)+ dfs(grid, i-1,j)+ dfs(grid, i,j+1)+ dfs(grid, i, j-1);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r= grid.size();
        int c=grid[0].size();
        int maxArea=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    maxArea=max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
        
    }
};