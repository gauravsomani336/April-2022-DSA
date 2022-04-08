// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    //int acquire=0;
    int release=0;
    unordered_map<char,int>mp;
    int count=0;
    int res=0;
    int n= s.size();
    
    for(int acquire=0; acquire<n ;acquire++)
    {
        // if(mp.find(s[acquire] ) == mp.end() &&  mp.size()<k)
        // {
        //     mp[s[acquire]]=1;
        //     count+=1;
        // }
        
        
         if(mp.find(s[acquire])== mp.end()  && mp.size()>=k)
        {
            while( mp.size()>=k)
            {
                mp[s[release]]-=1;
                if(mp[s[release]]==0)
                {
                    mp.erase(s[release]);
                    count-=1;
                  
                }
                release+=1;
            }
        }
        // else if(mp.find(s[acquire]) != mp.end() )
        // {
        //     mp[s[acquire]]+=1;
        // }
        mp[s[acquire]]+=1;
        
        if(mp.size()==k)
            res=max(res, acquire-release+1);
    }
    
    
    
    return res==0?-1:res;
    
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends