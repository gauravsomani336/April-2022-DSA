class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0;
        int end=nums.size()-1;
        
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            
            if(nums[mid]==target)
            {
                return mid;
            }
            
            //left part is sorted
            if(nums[mid]>=nums[st])
            {
                if(nums[st]<=target && target< nums[mid])
                {
                    end=mid-1;
                }
                else
                {
                    st=mid+1;
                }
            }
            
            //right part is sorted
            else
            {
                if(target>nums[mid]  && target<=nums[end])
                {
                    st=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        
        return -1;
    }
};