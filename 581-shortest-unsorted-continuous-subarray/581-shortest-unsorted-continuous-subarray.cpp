class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=-1;
        int end=-1;
        
        int cur_min=INT_MAX;
        int cur_max=INT_MIN;
        
        for(int i=n-1; i>=0;i--)
        {
            if(nums[i]< cur_min)
            {
                cur_min=nums[i];
            }
            if(nums[i]> cur_min)
            {
                start=i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>cur_max)
            {
                cur_max=nums[i];
            }
            if(nums[i]< cur_max)
            {
                end=i;
            }
        }
        
        if(end==-1)
        {
            return 0;
        }
        
        return end-start+1;
    }
};