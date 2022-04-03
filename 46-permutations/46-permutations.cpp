class Solution {
public:
    int factorial(int n)
    {
        if(n<=1)
        {
            return n;        
        }
        
        
       int ans=n*factorial(n-1);
        return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        int x= factorial(n);
        
        vector<vector<int>>res;
        
        for(int i=0;i<x;i++)
        {
            int idx=n-2;
            while(idx>=0 && nums[idx]>=nums[idx+1])
            {
                idx-=1;
            }
            
            int x=n-1;
         if(idx>=0)
         {
            while(i>=0)
            {
                if(nums[x]>nums[idx])
                {
                    swap(nums[x],nums[idx]);
                    break;
                }
                x-=1;
                
            }
         }
            reverse(nums.begin()+idx+1, nums.end());
            
            res.push_back(nums);
        }
        return res;
    }
};