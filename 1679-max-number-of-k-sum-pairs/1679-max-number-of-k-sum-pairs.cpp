class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i=0;
        int n= nums.size();
        int j=n-1;
        int count=0;
         sort(nums.begin(), nums.end());
        while(j>i)
        {
            int temp= nums[i]+ nums[j];
            if(temp==k)
            {
                count+=1;
                i+=1;
                j-=1;
            }
            else if(temp<k)
            {
                i+=1;
            }
            else
            {
                j-=1;
            }
            
        }
        
        return count;
    }
};