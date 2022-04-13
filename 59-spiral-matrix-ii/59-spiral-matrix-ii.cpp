class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int minc=0;
        int minr=0;
        vector<vector<int>>ans(n,vector<int>(n,0));
        
       int maxr=n-1;
        int maxc=n-1;
        
        int cnt=1;
        int tot=n*n;
        
        while(cnt<=tot)
        {
            //top
            vector<int>res;
            for(int i=minr,j=minc; j<=maxc && cnt<=tot; j++)
            {
                ans[i][j]=cnt;
                cnt+=1;
            }
            
            minr+=1;
            
            //right
            for(int i=minr,j=maxc; i<=maxr && cnt<=tot; i++)
            {
                 ans[i][j]=cnt;
                cnt+=1;
            }
             maxc-=1;
            
            //bottom
            for(int i=maxr, j=maxc; j>=minc && cnt<=tot;j--)
            {
                 ans[i][j]=cnt;
                cnt+=1;
            }
            
            maxr-=1;
            
            
            //left
            for(int i=maxr, j=minc; i>=minr && cnt<=tot; i--)
            {
               ans[i][j]=cnt;
                cnt+=1;
            }
            minc+=1;
            
            
        }
        
        return ans;
    }
};