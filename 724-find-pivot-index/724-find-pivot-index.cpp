class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ps=0;
        for(auto it: nums)
        {
            ps+=it;
        }
        
        int Ls=0;
        int Rs=ps;
        
        for(int i=0;i<nums.size(); i++)
        {
            Rs=Rs-nums[i];
            
            if(Ls==Rs)
            {
                return i;
                
            }
            
            Ls+=nums[i];
        }
        
        return -1;
    }
};