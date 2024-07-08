// Problem-350: Intersection of two array-II

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        unordered_map<int,int> um;
        
        for(auto num: nums1){
            um[num]++;
        }

        for(auto num: nums2){
            if(um[num]>0){
                arr.push_back(num);
                um[num]--;
            }
        }
        return arr;
    }
};