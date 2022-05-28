class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int mx= nums.size();
        
        vector<int>res(mx+1,-1);
        
        for(auto x: nums)
        {
            res[x]=0;
        }
        
        int ans=-1;
        for(int i=0;i<mx+1;i++)
        {
            if(res[i]==-1)
            {
                ans=i;
                break;
            }
        }
        
        return ans;
    }
};