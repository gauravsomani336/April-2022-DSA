class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                continue;
            }
            else
            {
                string temp="";
                while(i<s.size()  && s[i]!=' ')
                {
                    temp+=s[i];
                    i+=1;
                }
                
                st.push(temp);
            }
        }
        
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
            
            if(!st.empty())
            {
                res+=" ";
            }
        }
        
        return res;
    }
};