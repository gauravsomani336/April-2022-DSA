class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();
        
        int top=0;
        int bot=m-1;
        
        int mi= top+(bot-top)/2;
        
        while(top<=bot)
        {
            if(target> matrix[mi][n-1])
            {
                top=mi+1;
            }
            else if(target< matrix[mi][0])
            {
                bot=mi-1;
            }
            else
            {
                break;
            }
            
            mi=top+(bot-top)/2;
        }
        
        if(!(top<=bot))
        {
            return false;
        }
        
        int l=0;
        int r=n-1;
        
        int mid =l+(r-l)/2;
        
        while(l<=r)
        {
            if(target > matrix[mi][mid])
            {
                l=mid+1;
            }
            else if(target < matrix[mi][mid])
            {
                r=mid-1;
            }
            else
            {
                return true;
            }
            
            mid= l+(r-l)/2;
        }
        
        return false;
    }
};