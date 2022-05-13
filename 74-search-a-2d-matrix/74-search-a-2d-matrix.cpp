class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        int m=matrix.size();
        
        int lo=0;
        int hi=matrix.size()-1;
        
        int mi= lo+(hi-lo)/2;
        
        while(lo<=hi)
        {
            if(target< matrix[mi][0])
            {
                hi=mi-1;
            }
            
            else if(target > matrix[mi][n-1])
            {
                lo=mi+1;
            }
            else
            {
                break;
            }
            
            mi= lo+(hi-lo)/2;
        }
        
        if(!(lo<=hi))
        {
            return false;
        }
        
        int top=0;
        int bot=n-1;
        
        int mid=top +(bot-top)/2;
        
        while(top<=bot)
        {
            if(target == matrix[mi][mid])
            {
                return true;
            }
            else if(target < matrix[mi][mid])
            {
                bot= mid-1;
            }
            else if(target > matrix[mi][mid])
            {
                top =mid+1;
            }
            
            mid= top +(bot-top)/2;
        }
        
        return false;
        
    }
};