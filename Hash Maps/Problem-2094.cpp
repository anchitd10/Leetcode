// Problem-2094: Finding 3-Digit Even Numbers

// You are given an integer array digits, where each element is a digit. The array may contain duplicates.
// You need to find all the unique integers that follow the given requirements:
// - The integer consists of the concatenation of three elements from digits in any arbitrary order.
// - The integer does not have leading zeros.
// - The integer is even.
// For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
// Return a sorted array of the unique integers.
// Example 1:
// Input: digits = [2,1,3,0]
// Output: [102,120,130,132,210,230,302,310,312,320]
// Explanation: All the possible integers that follow the requirements are in the output array. 
// Notice that there are no odd integers or integers with leading zeros.



// Brute Force
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || j==k || i==k){
                        continue;
                    }

                    int num = digits[i]*100 + digits[j]*10 + digits[k];

                    if(num >= 100 && num%2 == 0){
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result(begin(st), end(st));
        sort(begin(result), end(result));

        return result;
    }
};


// Using Vector Map
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        vector<int> mp(10,0);

        for(int &digit : digits){
            mp[digit]++;
        }

        for(int i=1; i<=9; i++){
            if(mp[i] == 0) continue;
            mp[i]--;

            for(int j=0; j<=9; j++){
                if(mp[j] == 0) continue;
                mp[j]--;

                for(int k=0; k<=8; k += 2){
                    if(mp[k] == 0) continue;
                    mp[k]--;

                    int num = i*100 + j*10 + k;
                    result.push_back(num);
                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        return result;
    }
};