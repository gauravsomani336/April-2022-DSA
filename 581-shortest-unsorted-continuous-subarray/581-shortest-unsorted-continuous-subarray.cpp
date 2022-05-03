class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        int start=0, end=-1;
        int cur_min=INT_MAX;
        int cur_max=INT_MIN;
        
        while(j>=0)
        {
            if(nums[i]>= cur_max)
            {
                cur_max=nums[i];
            }
            else
            {
                end=i;
            }
            
            if(nums[j]<=cur_min)
            {
                cur_min=nums[j];
                
            }
            else
            {
                start=j;
            }
            
            ++i;
            --j;
        }
    
        
        
        return end - start +1;
    }
};