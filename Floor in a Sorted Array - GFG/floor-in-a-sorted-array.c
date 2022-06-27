// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C

// Function to find floor of K
// arr[]: integer array of size N
// N: size of arr[]
// K: element whose floor is to find

#define ll long long 
int findFloor(long long int nums[], int n, long long int x) {
    ll int ans=-1;
    
    ll int st=0;
    ll int end=n-1;
    
    while(st<=end)
    {
        ll int mid=st+(end-st)/2;
        
        if(nums[mid]==x)
        {
            return mid;
        }
        
        else if(nums[mid]> x)
        {
            end=mid-1;
        }
        else
        {
            ans=mid;
            st=mid+1;
        }
    }
    
    return ans;
    
    
    //Your code here
}

// { Driver Code Starts.

int main() {
	
	long long int t;
	scanf("%lld", &t);
	
	while(t--){
	    int n;
	    scanf("%d", &n);
	    long long int x;
	    scanf("%lld", &x);
	    
	    long long int *arr;
		arr = (long long int *)malloc(n * sizeof(long long int));
	    
	    for(int i = 0;i<n;i++){
	        scanf("%lld", &arr[i]);
	    }
	    printf("%d\n", findFloor(arr, n, x) );
	   
	}
	
	return 0;
}

  // } Driver Code Ends