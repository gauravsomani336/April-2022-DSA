class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
         int n=nums.size();
        // if(n<1)
        // {
        //     return {-1,-1};
        // }
        
        //vector<int>res={-1,-1};
        
        sort(nums.begin(), nums.end());
        
        int first= firstOcur(nums, target);
        int last= lastOcur(nums, target);
        
        if(first==-1)
        {
            return {};
        }
        
        vector<int>res;
        for(int i=first;i<=last;i++)
        {
            res.push_back(i);
        }
        return res;
    }
    
    int firstOcur(vector<int>&nums, int target)
    {
        int st=0;
        int end=nums.size()-1;
        int first=-1;
        
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            
            if(nums[mid]==target)
            {
                first=mid;
                end=mid-1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        
        return first;
    }
    
     int lastOcur(vector<int>&nums, int target)
    {
        int st=0;
        int end=nums.size()-1;
        int last=-1;
        
        while(st<=end)
        {
            int mid=st+(end-st)/2;
            
            if(nums[mid]==target)
            {
                last=mid;
                st=mid+1;
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        
        return last;
    }
    
};