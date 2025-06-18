// Problem-146: LRU Cache

// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class:
// - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// - int get(int key) Return the value of the key if the key exists, otherwise return -1.
// - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.


class LRUCache {
public:
    list<int> dll; //key
    // map<int, pair<Address, Value>> mp;
    map<int, pair<list<int>::iterator, int>> mp;
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeRecentlyUsed(int key){
        // remove the recently used in map
        dll.erase(mp[key].first);

        // add the new key
        dll.push_front(key);

        // update the address of first key(the new recently used)
        mp[key].first = dll.begin();
    }

    int get(int key) {
        // key not found
        if(mp.find(key) == mp.end()){
            return -1;
        }

        makeRecentlyUsed(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        } else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if(n < 0){
            int key_to_del = dll.back();
            mp.erase(key_to_del);

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