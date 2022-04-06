// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
       unordered_map<int,int>mp;
       mp.insert({0,-1});
       int prefix=0;
       int mx=INT_MIN;
       for(int i=0;i<n;i++)
       {
           prefix+=nums[i];
           if(mp.find(prefix)!=mp.end())
           {
               int tmp=i-mp[prefix];
               mx=max(mx, tmp);
           }
           else
           {
               mp[prefix]=i;
           }
       }
       
       return mx==INT_MIN?0:mx;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends