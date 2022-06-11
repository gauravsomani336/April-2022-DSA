class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        if(sum<x)
        {
            return -1;
        }
        
        int st=0, end=0, window=0;
        while(end<n)
        {
            window+=nums[end];
            while(window> sum-x)
            {
                window-=nums[st];
                st+=1;
            }
            
            if(window==(sum-x))
            {
                ans=min(ans, n-(end-st+1));
            }
            end+=1;
        }
        
        return ans==INT_MAX?-1:ans;
        
    }
};