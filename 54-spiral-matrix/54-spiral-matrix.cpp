class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int>res;
        
        int tot=(matrix.size()* matrix[0].size());
        int cnt=0;
        
        int minr=0;
        int minc=0;
        
        int maxr=n-1;
        int maxc=m-1;
        
        while(cnt<tot)
        {
            //top row
            
            for(int i=minr,j=minc;j<=maxc && cnt<tot;j++)
            {
                res.push_back(matrix[i][j]);
                cnt+=1;
            }
            
            minr+=1;
            
            // right col
            
            for(int i=minr, j=maxc;i<=maxr && cnt<tot ;i++)
            {
                res.push_back(matrix[i][j]);
                cnt+=1;
                
            }
            maxc-=1;
            
            //bottom row
            
            for(int i=maxr,j=maxc;j>=minc && cnt<tot;j--)
            {
                res.push_back(matrix[i][j]);
                cnt+=1;
            }
            
            maxr-=1;
            
            //left col
            
            for(int i=maxr, j=minc;i>=minr && cnt<tot;i--)
            {
                res.push_back(matrix[i][j]);
                cnt+=1;
            }
            
            minc+=1;
        }
        
        return res;
    }
};