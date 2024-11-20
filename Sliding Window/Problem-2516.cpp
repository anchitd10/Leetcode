// Problem-2516: Take K of Each Character From Left and Right

// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
// Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
// Example 1:
// Input: s = "aabaaaacaabc", k = 2
// Output: 8
// Explanation: 
// Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
// Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
// A total of 3 + 5 = 8 minutes is needed.
// It can be proven that 8 is the minimum number of minutes needed.

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();

        int count_a = 0;
        int count_b = 0;
        int count_c = 0;
        for(char &ch : s){
            if(ch == 'a'){
                count_a++;
            }
            else if(ch == 'b'){
                count_b++;
            }
            else{
                count_c++;
            }
        }

        if(count_a < k || count_b < k || count_c < k){
            return -1;
        }

        int i = 0;
        int j = 0;
        int notDeletedWindowSize = 0;

        while(j < n){
            if(s[j] == 'a'){
                count_a--;
            }
            else if(s[j] == 'b'){
                count_b--;
            }
            else if(s[j] == 'c'){
                count_c--;
            }

            while(i <= j && (count_a < k || count_b < k || count_c < k)){
                if(s[i] == 'a'){
                    count_a++;
                }
                else if(s[i] == 'b'){
                    count_b++;
                }
                else{
                    count_c++;
                }
                i++;
            }
            notDeletedWindowSize = max(notDeletedWindowSize, j-i+1);
            j++;
        }
        return n - notDeletedWindowSize;
    }
};