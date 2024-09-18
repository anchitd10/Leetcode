// Problem-179: Largest Number

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.
// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

class Solution {
public:
    //the check function is defined as static to allow it to be passed as a comparator to the sort function
    static bool check(string &s1, string &s2){
        return (s1+s2) >= (s2+s1);
    }

    string largestNumber(vector<int>& nums) {
        //check if all elements are 0, then return 0
        int x=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) x++;
        }
        if(x == nums.size()) return "0";

        vector<string> s(nums.size());

        for(int i=0; i< nums.size(); i++){
            s[i] = to_string(nums[i]);
        }

        sort(s.begin(), s.end(), check);
        string ans = "";

        for(int i=0; i<s.size(); i++){
            ans += s[i];
        }
        return ans;
    }
};