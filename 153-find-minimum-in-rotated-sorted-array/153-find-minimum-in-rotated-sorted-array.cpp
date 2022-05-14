class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r= nums.size()-1;
        int res=INT_MAX;
        
        int mid = l+(r-l)/2;
        while(l<=r)
        {
            if(nums[l]< nums[r])
            {
                res=min(res, nums[l]);
                break;
            }
            
            if(nums[mid]>= nums[l])
            {
                res=min(res, nums[mid]);
                l=mid+1;
            }
            else
            {
                 res=min(res, nums[mid]);
                r=mid-1;
            }
            
            mid=l+(r-l)/2;
        }
        
        return res;
    }
};