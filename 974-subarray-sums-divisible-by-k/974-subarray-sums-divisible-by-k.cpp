class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int ans=0;
        int sum=0;
        
        for(auto x: nums)
        {
            sum+=x;
            int rem= ((sum%k)+k)%k;
            
            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
                 mp[rem]+=1;
            }
            else
            {
                mp[rem]=1;
            }
           
        }
        
        return ans;
    }
};