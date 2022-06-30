class Solution {
public:
    int mySqrt(int x) {
       long int st=0;
       long int end=x;
       long int ans=-1;
        
        while(st<=end)
        {
           long int mid= st+(end-st)/2;
            
            if(mid*mid==x)
            {
                return mid;
            }
            
            if(mid*mid < x)
            {
                ans=mid;
                st=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        
        return (int) ans;
    }
};