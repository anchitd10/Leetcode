// Problem-1405: Longest Happy String

// A string s is called happy if it satisfies the following conditions:
// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.
// Example 1:
// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.

class Solution {
public:
    typedef pair<int, char> P;

    string longestDiverseString(int a, int b, int c) {
        priority_queue<P> pq;

        if(a > 0){
            pq.push({a, 'a'});
        }
        if(b > 0){
            pq.push({b, 'b'});
        }
        if(c > 0){
            pq.push({c, 'c'});
        }

        string result = "";

        while (!pq.empty()) {
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            // if two consecutive characters that are the same, use another character if available
            if (result.length() >= 2 && result.back() == currChar && result[result.length() - 2] == currChar) {
                if (pq.empty()) break;

                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;

                if (nextCount > 0){
                    pq.push({nextCount, nextChar});
                }

                pq.push({currCount, currChar});
            } else {
                result.push_back(currChar);
                currCount--;

                if (currCount > 0){
                    pq.push({currCount, currChar});
                }
            }
        }

        return result;
    }
};
