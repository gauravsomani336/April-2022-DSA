class Solution {
public:
    string getString(string s, int l, int r)
    {
        string res="";
        while(l<=r)
        {
            res+=s[l];
            l+=1;
        }
        return res;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int mx=INT_MIN;
        int len;
        string res;
        for(int i=0;i<n;i++)
        {
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                len= r-l+1;
                if(len>mx)
                {
                    res= getString(s, l ,r);
                    mx=len;
                }
                l-=1;
                r+=1;
            }
            
            l=i;
            r=i+1;
             while(l>=0 && r<n && s[l]==s[r])
            {
                len= r-l+1;
                if(len>mx)
                {
                    res= getString(s, l ,r);
                    mx=len;
                }
                l-=1;
                r+=1;
            }
        }
        
        return res;
    }
};