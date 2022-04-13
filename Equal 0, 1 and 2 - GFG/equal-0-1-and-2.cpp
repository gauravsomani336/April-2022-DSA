// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

using ll= long long;
class Solution {
  public:
    long long getSubstringWithEqual012(string s) {
        // code here
        long long ans=0;
        ll r0=0;
        ll r1=0;
        ll r2=0;
        
        unordered_map<string, int>mp;
        ll a= (r1-r0);
        ll b= (r2-r1);
         string str=to_string(a)+"#"+to_string(b);
         mp.insert({str, 1});
         
         for(char x: s)
         {
             if(x=='0')
             {
                 r0+=1;
                 
             }
             else if(x=='1')
             {
                 r1+=1;
             }
             else if(x=='2')
             {
                 r2+=1;
             }
             
             a= (r1-r0);    
             b= (r2-r1);
             str=to_string(a)+"#"+to_string(b);
             
             if(mp.find(str)!=mp.end())
             {
                 ans+=mp[str];
                 mp[str]+=1;
             }
             else
             {
                 mp[str]=1;
             }
             
             
             
         }
         
         return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends