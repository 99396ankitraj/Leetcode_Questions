class LRUCache {
public:
    list<int>dl;
    typedef pair<list<int>::iterator , int> p;
    int n ;
    unordered_map<int , p > mp;
    LRUCache(int capacity) {
        n = capacity;
    }
    void resetposition(int key){
        dl.erase(mp[key].first);
        dl.push_front(key);
        mp[key].first = dl.begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        resetposition(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
             mp[key].second = value;
             resetposition(key);
        }else{
             dl.push_front(key);
             mp[key] = {dl.begin() , value};
             n--;
        }

        //check for capacity
        if(n < 0){
            mp.erase(dl.back());
            dl.pop_back();
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