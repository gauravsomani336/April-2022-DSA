class Solution {
public:
    int kthFactor(int n, int k) {
        set<int>s;
        
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                s.insert(i);
            
                if(i!=sqrt(n))
                {
                    s.insert(n/i);
                }
                
            }
        }
        
        if(s.size()<k)
        {
            return -1;
        }
        
        auto it= s.begin();
        while(k!=1)
        {
            it++;
            k-=1;
        }
        return *it;
    }
};