// Problem-2138: Divide a String Into Groups of Size k

// A string s can be partitioned into groups of size k using the following procedure:
// - The first group consists of the first k characters of the string, the second group consists of the next k characters of the string, and so on. Each element can be a part of exactly one group.
// - For the last group, if the string does not have k characters remaining, a character fill is used to complete the group.
// Note that the partition is done so that after removing the fill character from the last group (if it exists) and concatenating all the groups in order, the resultant string should be s.
// Given the string s, the size of each group k and the character fill, return a string array denoting the composition of every group s has been divided into, using the above procedure.
// Example:
// Input: s = "abcdefghij", k = 3, fill = "x"
// Output: ["abc","def","ghi","jxx"]
// Explanation:
// Similar to the previous example, we are forming the first three groups "abc", "def", and "ghi".
// For the last group, we can only use the character 'j' from the string. To complete this group, we add 'x' twice.
// Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".



class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        string temp;
        vector<string> result;
        int n = s.length();
        int i = 0;

        while(i < n){
            int j = (i + k - 1 >= n) ? (n-1) : (i + k - 1);

            string temp = s.substr(i, j-i+1);

            if(j-i+1 < k){
                int remaining = k - (j-i+1);
                temp += string(remaining, fill);
            }

            result.push_back(temp);

            i += k;
        }

        return result;
    }
};