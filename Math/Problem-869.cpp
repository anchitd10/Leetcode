// Problem-869: Reordeed Power of 2

// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
// Return true if and only if we can do this so that the resulting number is a power of two.
// Example 1:
// Input: n = 1
// Output: true
// Example 2:
// Input: n = 10
// Output: false9: Reordered Power of 2

// Approach: sort the given number after converting it to string and check if the sorted string matches any of the sorted strings of powers of 2.


class Solution {
public:
    // another approach is to store the sorted powers of two using a set
    string sortStr(int n){
        string s = to_string(n);
        sort(begin(s), end(s));
        return s;
    }

    bool reorderedPowerOf2(int n) {
        string s = sortStr(n);

        for(int p=0; p <= 29; p++){
            if(s == sortStr(1 << p)){
                return true;
            }
        }

        return false;
    }
};