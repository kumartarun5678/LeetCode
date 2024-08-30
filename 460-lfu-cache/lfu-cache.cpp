class LFUCache {
public:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; 
    map<int, list<vector<int>>> freq; 

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        auto &vec = *(mp[key]);
        int value = vec[1];
        makeLFU(key);
        return value;
    }
    
    void makeLFU(int key) {
        auto &vec = *(mp[key]);
        int value = vec[1];
        int f = vec[2];
        freq[f].erase(mp[key]);
        if(freq[f].empty()) {
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key, value, f});
        mp[key] = freq[f].begin();
    }
    
    void put(int key, int value) {
        if(cap == 0) {
            return;
        }
        if(mp.find(key) != mp.end()) {
            auto &vec = *(mp[key]);
            vec[1] = value;
            makeLFU(key);
        } else if(size < cap) {
            size++;
            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();
        } else {
            auto &lis = freq.begin()->second;
            int del = lis.back()[0];
            lis.pop_back();
            if(lis.empty()) {
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front({key, value, 1});
            mp.erase(del);
            mp[key] = freq[1].begin();
        }
    }
};
