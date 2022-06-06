class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int n=cardPoints.size();
        int l=0;
        int r= n-k;
        
        int tot=0;
        for(int i=r;i<n;i++)
        {
            tot+=cardPoints[i];
        }
       // r=r-1;
        int mx=tot;
        while(r<n)
        {
            tot+=cardPoints[l];
            tot-=cardPoints[r];
            mx=max(tot, mx);
            l+=1;
            r+=1;
        }
        
        return mx;
    }
};