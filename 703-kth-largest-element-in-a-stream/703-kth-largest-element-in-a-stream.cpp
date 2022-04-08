class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>mh;
    int siz;
    KthLargest(int k, vector<int>& nums) {
       
        siz=k;
        for(auto it: nums)
        {
            add(it);
        }
    }
    
    int add(int val) {
        
        if(mh.size()<siz)
        {
            mh.push(val);
        }
        else
        {
            if(val> mh.top())
            {
                mh.pop();
                mh.push(val);
            }
        }
        
        return mh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */