class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        
        int mid=s+(e-s)/2;
        
        while(s<=e)
        {
            if(target==nums[mid])
            {
                return mid;
            }
            //left sorted portion
            if(nums[s]<= nums[mid])
            {
                if((target> nums[mid]) || target< nums[s])
                {
                   s=mid+1;
                }
                else 
                {
                    e=mid-1;
                }
            }
            //right sorted portion
            else
            {
                if((target < nums[mid] ) || target > nums[e])
                   {
                       e=mid-1;
                   }
                   else
                   {
                       s=mid+1;
                   }
            }
            
            mid=s+(e-s)/2;
            
            
        }
        
        return -1;
    }
};