class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevEnd= intervals[0][1];
        int res=0;
        
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            int start= intervals[i][0];
            if(start>= prevEnd)
            {
                prevEnd=intervals[i][1];
            }
            else
            {
                res+=1;
                prevEnd=min(intervals[i][1], prevEnd);
            }
        }
        
        return res;
    }
};