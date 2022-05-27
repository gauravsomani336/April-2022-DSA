class LRUCache {
public:
    map<int,int>mp;
    list<int>l;
    unordered_map<int, list<int>::iterator>address;
    int cap;
    int siz;
    LRUCache(int capacity) {
        
        cap=capacity;
        siz=0;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        
        l.erase(address[key]);
        address.erase(key);
        
        l.push_front(key);
        address[key]=l.begin();
        return mp[key];
        
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            siz-=1;
            
        }
        if(siz>=cap)
        {
            int k =l.back();
            l.erase(address[k]);
            address.erase(k);
            mp.erase(k);
            siz-=1;
        }
        
        
        l.push_front(key);
            address[key]=l.begin();
            mp[key]=value;
        siz+=1;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */