class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        
        unordered_map<int,int>mp;
        for(int i=0,num;i<numbers.size();i++)
        {
           num= target-numbers[i];
            
            
            if(mp.find(num)!=mp.end())
            {
               return {mp[num]+1, i+1};
            }
            
            mp[numbers[i]]=i;
            
        }
        
         return { 1453, 1071 }; 
    }
};