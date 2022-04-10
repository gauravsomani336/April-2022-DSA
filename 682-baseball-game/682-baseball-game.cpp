class Solution {
public:
    int calPoints(vector<string>& ops) {
          stack<int>st;
        int res=0;
        int n=ops.size();
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="+")
            {
               int x= st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                
                int z= x+y;
                st.push(z);
                
            }
            
            else if(ops[i]=="D")
            {
                int a= st.top();
                int ans= 2* a;
                st.push(ans);
            }
            else if(ops[i]=="C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(ops[i]));
            }
        }
        
        while(!st.empty())
        {
            int x= st.top();
            res+=x;
            st.pop();
        }
        
        return res;
        
    }
};