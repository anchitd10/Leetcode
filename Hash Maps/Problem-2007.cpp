// Problem-2007: Find Original Array From Doubled Array

// An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
// Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.
// Example 1:
// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]
// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].

// Concept: Hash Map
// Tip: Use a hash map to store the frequency of each element in the changed array.
// Iterare through the changed array and for each element, check if its double exists in the hash map with a non-zero frequency.
// If it exists, add the element to the original array and decrement the frequency of both the element and its double in the hash map.

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 != 0) {
            return {};
        }

        map<int, int> mp;
        vector<int> result;

        sort(changed.begin(), changed.end());

        for (int& i : changed) {
            mp[i]++;
        }

        for (int& i : changed) {
            int twice = i*2;

            if(mp[i] == 0){
                continue;
            }

            if(mp.find(twice) == mp.end() || mp[twice] == 0){
                return {};
            }

            result.push_back(i);

            mp[i]--;
            mp[twice]--;
        }

        return result;
    }
};