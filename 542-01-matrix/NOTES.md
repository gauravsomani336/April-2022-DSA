int dfs(vector<vector<int>>& mat,int i, int j, vector<vector<bool>>&visited)
{
if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || visited[i][j])
{
return 100000;
}
if(mat[i][j]==0 )
{
return 0;
}
visited[i][j]=true;
int val=1+ min(  min(dfs(mat, i+1,j,visited), dfs(mat, i-1, j, visited))  ,
min(dfs(mat, i, j+1,visited), dfs(mat, i, j-1, visited)) );
visited[i][j]=false;
return val;
}
};
```
```
​
​
​