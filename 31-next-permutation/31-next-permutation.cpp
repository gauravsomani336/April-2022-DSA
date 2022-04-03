class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        int idx=n-2;
        while(idx>=0 && nums[idx]>=nums[idx+1])
        {
            idx-=1;
        }
        
        int i=n-1;
        
        if(idx>=0)
        {
            while(i>=0)
            {
                if(nums[i]>nums[idx])
                {
                    swap(nums[i], nums[idx]);
                    break;
                 }
                i-=1;
             }
        }
        
        reverse(nums.begin()+idx+1, nums.end());
    }
};