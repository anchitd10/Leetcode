// Problem-380: Insert Delete GetRandom O(1)

// Implement the RandomizedSet class:
// - RandomizedSet() Initializes the RandomizedSet object.
// - bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
// - bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
// - int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
// You must implement the functions of the class such that each function works in average O(1) time complexity.
// Example 1:
// Input
// ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
// [[], [1], [2], [2], [], [1], [2], []]
// Output
// [null, true, false, true, 2, true, false, 2]



class RandomizedSet {
public:
    vector<int> randomSet;
    unordered_map<int, int> index;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(index.find(val) != index.end()){
            return false;
        }

        randomSet.push_back(val);
        index[val] = randomSet.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(index.find(val) == index.end()){
            return false;
        }

        int idx = index[val];
        int lastElement = randomSet.back();
        
        randomSet.back() = val;
        randomSet[idx] = lastElement;
        
        index[lastElement] = idx;
        randomSet.pop_back();
        index.erase(val);

        return true;
    }
    
    int getRandom() {
        int n = randomSet.size();
        int randomIndex = rand() % n;
        return randomSet[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */