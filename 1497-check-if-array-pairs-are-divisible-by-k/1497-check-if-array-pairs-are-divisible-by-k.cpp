class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>num(k);
        int n=arr.size();
        
        for(auto it: arr)
        {
            int rem= ((it % k)+k)%k;
            
            num[rem]+=1;
        }
        
        for(int i=0;i<= k/2;i++)
        {
            if(i==0)
            {
                if(num[i]%2!=0)
                {
                    return false;
                }
            }
            else
            {
                int y=k-i;
                if(num[i]!=num[y])
                {
                    return false;
                }
            }
        }
        return true;
    }
};