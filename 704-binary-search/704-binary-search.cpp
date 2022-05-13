class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;
        int mid= lo + (hi-lo)/2;
        
        while(lo<=hi)
        {
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]< target)
            {
                lo+=1;
            }
            else 
            {
                hi-=1;
            }
            
            mid=lo+(hi-lo)/2;
        }
        
        return -1;
    }
};