class MyHashMap {
public:
    vector<list<pair<int,int>>>m;
    int siz;
    MyHashMap() {
        siz=200;
        m.resize(siz);
    }
    
    int hash(int key)
    {
        return key % siz;
    }
    
    list<pair<int,int>>::iterator search(int key)
    {
        int i=hash(key);
        
        auto it= m[i].begin();
        while(it!=m[i].end())
        {
            if(it->first==key)
            {
                return it;
            }
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i=hash(key);
        remove(key);
        
        m[i].push_back({key, value});
    }
    
    int get(int key) {
        int i=hash(key);
        auto it=search(key);
        if(it==m[i].end())
        {
            return -1;
        }
        
        return it->second;
    }
    
    void remove(int key) {
        int i=hash(key);
        auto it= search(key);
        if(it!=m[i].end())
        {
            m[i].erase(search(key));
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */