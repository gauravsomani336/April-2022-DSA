class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto it: answers)
        {
           mp[it]+=1;
        }
        
        double ans=0;
        
        for(auto it: mp)
        {
            double key= it.first+1;
            
            double num= ceil(it.second / key);
            ans+= (num*key);
            
        }
        
        return (int)ans;
    }
};