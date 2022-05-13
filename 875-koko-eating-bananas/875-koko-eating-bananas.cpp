class Solution {
public:
    int solve(vector<int>&piles, int x)
    {
        int hours=0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=(piles[i]/ x);
            if(piles[i]%x !=0)
            {
                hours+=1;
            }
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
      int max=INT_MIN;
        for(auto it : piles)
        {
            if(max< it)
            {
                max=it;
            }
        }
        
        int start=1;
        int end= max;
        
        int minh=INT_MAX;
        
        int mid=start+(end-start)/2;
        while(start<=end)
        {
            int totalh=solve(piles, mid);
            if(totalh<=h)
            {
                minh=min(minh, mid);
                end=mid-1;
            }
            else
            {
                start= mid+1;
            }
            
            mid=start+(end-start)/2;
            
        }
        
        return minh;
    }
};