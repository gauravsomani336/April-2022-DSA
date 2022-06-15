class Solution {
public:
    long long solve(char c, string s)
    {
        int n=s.size();
        long long cnt=0ll, res=0ll;
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                res+=(1ll*cnt*(cnt+1)/2);
                cnt=0ll;
            }
            else
            {
                cnt+=1;
            }
        }
        
        res+=(1ll* cnt*(cnt+1)/2);
        return (1ll*n*(n+1)/2)-res;
    }
    
    long long appealSum(string s) {
        long long res=0ll;
        for(char c='a';c<='z';c++)
        {
            res+=solve(c, s);
        }
        
        return res;
    }
};