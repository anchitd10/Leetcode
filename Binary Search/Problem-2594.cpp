// Problem-2594: Minimum Time to Repair Cars

// You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.
// You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
// Return the minimum time taken to repair all the cars.
// Note: All the mechanics can repair the cars simultaneously.
// Example 1:
// Input: ranks = [4,2,3,1], cars = 10
// Output: 16
// Explanation: 
// - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
// - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
// - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
// - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
// It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

class Solution {
public:
    bool isPossible(vector<int>& ranks, long long mid, int cars){
        long long carsFixed = 0;

        for(int i=0; i<ranks.size(); i++){
            carsFixed += sqrt(mid/ranks[i]);
        }
        return carsFixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();

        long long l = 1;
        int maxRank = *max_element(begin(ranks), end(ranks));
        long long r = 1LL * maxRank * cars * cars;

        long long result = -1;
        while(l<=r){
            long long mid = l + (r-l)/2;

            if(isPossible(ranks, mid, cars)){
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