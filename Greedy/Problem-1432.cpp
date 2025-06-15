// Problem-1432: Max Difference You Can Get From Changing an Integer

// You are given an integer num. You will apply the following steps to num two separate times:
// - Pick a digit x (0 <= x <= 9).
// - Pick another digit y (0 <= y <= 9). Note y can be equal to x.
// - Replace all the occurrences of x in the decimal representation of num by y.
// Let a and b be the two results from applying the operation to num independently.
// Return the max difference between a and b.
// Note that neither a nor b may have any leading zeros, and must not be 0.
// Example 1:
// Input: num = 555
// Output: 888
// Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
// The second time pick x = 5 and y = 1 and store the new integer in b.
// We have now a = 999 and b = 111 and max difference = 888



class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        int idx = str1.find_first_not_of('9');
        if(idx != string::npos){
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        for(int i=0; i<str2.length(); i++){
            char ch = str2[i];

            if(i == 0){
                if(ch != '1'){
                    replace(begin(str2), end(str2), ch, '1');
                    break;
                }
            } else if(ch != '0' && ch != str2[0]){
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }

        return stoi(str1) - stoi(str2);
    }
};