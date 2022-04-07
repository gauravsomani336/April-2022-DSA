class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()>1)
        {
            sort(stones.begin(), stones.end());
            // auto val = a.back();
            //   a.pop_back();
           
            int j=stones.back();
            stones.pop_back();
            int k=stones.back();
            stones.pop_back();
            if(j!=k)
            {
            int temp=j-k;
                stones.push_back(temp);
                
            }
        }
        
         int n=stones.size();
        return n==1?stones[0]:0;
        
    }
};