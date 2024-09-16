// Problem-1371: Find the Longest Substring Containing Vowels in Even Counts

// Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// Example 1:
// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;
        vector<int> vowelState(5,0);
        
        string currState = "00000";
        mp[currState] = -1;

        int result = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a'){
                vowelState[0] = (vowelState[0] + 1)%2;
            }
            else if(s[i] == 'e'){
                vowelState[1] = (vowelState[1] + 1)%2;
            }
            else if(s[i] == 'i'){
                vowelState[2] = (vowelState[2] + 1)%2;
            }
            else if(s[i] == 'o'){
                vowelState[3] = (vowelState[3] + 1)%2;
            }
            else if(s[i] == 'u'){
                vowelState[4] = (vowelState[4] + 1)%2;
            }

            currState = "";
            for(int j=0; j<5; j++){
                currState += to_string(vowelState[j]);
            }

            if(mp.find(currState) != mp.end()){    //see if we have seen this currState in the past and in which index
                result = max(result, i - mp[currState]);  //(i - mp[currState]) --> to check the length of the current state from the past state, hence getting the length
            }
            else{   //else if state is found for the first time then add the pair in the map(string state and it's index)
                mp[currState] = i;
            }
        }
        return result;
    }
};

// 2nd approach
// use XOR operator instead of adding for every vowelState that way we dont need modulo
// if XOR for even count then automatically 0

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<string, int> mp;
        vector<int> vowelState(5,0);
        
        string currState = "00000";
        mp[currState] = -1;

        int result = 0;

        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a'){
                vowelState[0] = (vowelState[0] ^ 1);
            }
            else if(s[i] == 'e'){
                vowelState[1] = (vowelState[1] ^ 1);
            }
            else if(s[i] == 'i'){
                vowelState[2] = (vowelState[2] ^ 1);
            }
            else if(s[i] == 'o'){
                vowelState[3] = (vowelState[3] ^ 1);
            }
            else if(s[i] == 'u'){
                vowelState[4] = (vowelState[4] + 1)%2;
            }

            currState = "";
            for(int j=0; j<5; j++){
                currState += to_string(vowelState[j]);
            }

            if(mp.find(currState) != mp.end()){
                result = max(result, i - mp[currState]);
            }
            else{
                mp[currState] = i;
            }
        }
        return result;
    }
};