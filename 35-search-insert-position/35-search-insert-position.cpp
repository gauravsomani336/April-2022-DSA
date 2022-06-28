class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int ans=-1;
        
        while(st<=end)
        {
            
            
            int mid=st+(end-st)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            
            else if(nums[mid]> target)
            {
                end=mid-1;
            }
            else
            {
                //ans=mid;
                st=mid+1;
            }
        }
        
        return st;
    }
};