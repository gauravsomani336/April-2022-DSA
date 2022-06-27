// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    //int n=nums.size();
        // if(n<1)
        // {
        //     return {-1,-1};
        // }
        
        //vector<int>res={-1,-1};
        
        int first= firstOcur(nums, target,n);
        if(first==-1)
        {
            return 0;
        }
        
        int last= lastOcur(nums, target,n);
        
        return last-first+1;
        
    }
    
    int firstOcur(int nums[], int target, int n)
    {
        int st=0;
        int end=n-1;
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
    
     int lastOcur(int nums[], int target,int n)
    {
        int st=0;
        int end=n-1;
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

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends