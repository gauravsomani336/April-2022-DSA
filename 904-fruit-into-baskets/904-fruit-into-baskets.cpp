class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp;
        int len=INT_MIN;
        
        int start=0;
        for(int end=0;end<n;end++)
        {
           mp[fruits[end]]+=1;
            
            while(start<n && (int)mp.size()>2)
            {
                mp[fruits[start]]-=1;
                
                if(mp[fruits[start]]==0)
                {
                    mp.erase(fruits[start]);
                }
                start+=1;
            }
            
            len=max(len, end-start+1);
            
        }
        
        return len;
    }
};