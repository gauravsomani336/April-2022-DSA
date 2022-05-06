class Solution {
public:
    int firstOcc(vector<int>&nums, int t)
    {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int res=-1;
        
        while(s<=e)
        {
               if(nums[mid]==t)
                {
                    res=mid;
                    e=mid-1;
                }
                else if(nums[mid]> t)
                {
                    e=mid-1;
                }
                else if(nums[mid]<t)
                {
                    s=mid+1;
                }

                    mid=s+(e-s)/2;
        }
        return res;        
    }
    int lastOcc(vector<int>&nums, int t)
    {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int res=-1;
        
        while(s<=e)
        {
               if(nums[mid]==t)
                {
                    res=mid;
                    s=mid+1;
                }
                else if(nums[mid]> t)
                {
                    e=mid-1;
                }
                else if(nums[mid]<t)
                {
                    s=mid+1;
                }

                    mid=s+(e-s)/2;
        }
        return res;        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,0);
        ans[0]=firstOcc(nums, target);
        ans[1]=lastOcc(nums, target);
        
        return ans;
    }
};