class LRUCache {
public:
    list<int>dll;
    map<int, pair<list<int>::iterator,int>>mpp;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;
        makeMLRU(key);
        return mpp[key].second;
    }
    void makeMLRU(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            mpp[key].second=value;
            makeMLRU(key);
        }
        else{
            dll.push_front(key);
            mpp[key] = {dll.begin(),value};
            n--;
        }
        if(n<0){
            int keydelete = dll.back();
            mpp.erase(keydelete);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */