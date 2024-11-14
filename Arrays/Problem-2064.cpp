// Problem-2064: Minimized Maximum of Products Distributed to Any Store

// You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.
// You need to distribute all products to the retail stores following these rules:
// A store can only be given at most one product type but can be given any amount of it.
// After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
// Return the minimum possible x.
// Example 1:
// Input: n = 6, quantities = [11,6]
// Output: 3
// Explanation: One optimal way is:
// - The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
// - The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
// The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

class Solution {
public:
    bool possibleToDistrib(int x, vector<int>& quantities, int shops){
        for(int &products : quantities){
            shops -= (products + x - 1)/x;

            if(shops < 0){
                return false;
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();

        int l = 1;
        int r = *max_element(begin(quantities), end(quantities));
        int result = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(possibleToDistrib(mid, quantities, n)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};