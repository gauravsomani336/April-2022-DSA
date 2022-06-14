class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        int m=mat.size();
        int n=mat[0].size();
        
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(auto d : dir)
            {
                int nr=r+d[0];
                int nc= c+ d[1];
                
                if(nr<0 || nc<0 || nr>=m || nc>=n || mat[nr][nc]!=-1)
                {
                    continue;
                }
                
                mat[nr][nc]=1+mat[r][c];
                q.push({nr, nc});
            }
        }
        
        return mat;
        
    }
};