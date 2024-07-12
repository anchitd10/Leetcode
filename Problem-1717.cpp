// Problem-1717: Maximum Score from removing substrings

// You are given a string s and two integers x and y. You can perform two types of operations any number of times.
// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.
// Example 1:
// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19
// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.

class Solution {
public:
    int pointsForString(string& s, string targetString, int point){
        int totalPoints = 0, n = s.length();
        stack<char> myStack;

        for(int i=0; i<n; i++){
            if(myStack.empty()){
                myStack.push(s[i]);
            }
            else{
                if(s[i] == targetString[1] && myStack.top() == targetString[0]){
                    myStack.pop();
                    totalPoints += point;
                }
                else{
                    myStack.push(s[i]);
                }
            }
        }
        s = "";
        while(!myStack.empty()){
            s += myStack.top();
            myStack.pop();
        }

        reverse(s.begin(),s.end());
        return totalPoints;
    }
    
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if(x < y){
            swap(s1,s2), swap(x,y);
        }
        return pointsForString(s, s1, x) + pointsForString(s, s2, y);
        // first calling s1 which will have higher scrore and then calling s2 with lower score
    }
};