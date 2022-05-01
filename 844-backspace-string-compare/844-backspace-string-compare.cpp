class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1;
        string s2;
        
        int n= s.size();
        int m= t.size();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='#' )
            {
                if(s1!="")
                {
                    s1.pop_back();
                }
                else
                {
                    continue;
                }
            }
            else
            {
                s1.push_back(s[i]);
            }
        }
         for(int i=0;i<m;i++)
        {
            if(t[i]=='#')
            {
                if(s2!="")
                {
                    s2.pop_back();
                }
                else
                {
                    continue;
                }
            }
            else
            {
               
                  s2.push_back(t[i]);
            }
        }
        
        return s1==s2;
    }
};