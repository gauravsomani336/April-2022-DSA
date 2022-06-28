// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // vector<int>res;
        // for(int i=1;i<=n;i++)
        // {
        //     res.push_back(i);
        // }
        
        int st=1;
        int end=n;
        int ans=-1;
        
        while(st<=end)
        {
            int mid= st+(end-st)/2;
            if(isBadVersion(mid)==true)
            {
                end=mid-1;
                ans=mid;
            }
            else if(isBadVersion(mid)==false)
            {
                st=mid+1;
            }
        }
        
        return ans;
    }
};