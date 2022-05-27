class Solution {
public:
    int numberOfSteps(int num) {
        int count=0;
        solve(num, count);
        return count;
    }
    
      void solve(int num, int& count)
    {
        if(num==0)
        {
            return ;
        }
        
        if(num%2==0)
        {
            count+=1;
            solve(num/2, count);
        }
        else
          {
            count+=1;
              solve(num-1, count);
          }
    }
};