class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++)
        {
            int li= res.back()[1];
            
            if(li>=intervals[i][0])
            {
                res.back()[0]= min(res.back()[0], intervals[i][0]);
                res.back()[1]= max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};