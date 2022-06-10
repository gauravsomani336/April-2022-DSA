class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>hash(60,0);
        int n=time.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int a= time[i]%60;
            if(a==0)
            {
                count+=hash[a];
            }
            else
            {
                count+=hash[60-a];
            }
            
            hash[a]+=1;
        }
        
        return count;
    }
};