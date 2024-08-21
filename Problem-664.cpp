// Problem-664: Strange Printer

// There is a strange printer with the following two special properties:
// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
// Given a string s, return the minimum number of turns the printer needed to print it.
// Example:
// Input: s = "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.

class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(int l, int r, string &s){
        if(l == r){
            return 1;
        }
        if(l > r){
            return 0;
        }

        if(t[l][r] != -1){
            return t[l][r];
        }

        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;

        if(i == r+1){
            return 1;
        }
        int basic = 1 + solve(i, r, s);

        int lalach = INT_MAX;

        for(int j = i; j<=r; j++){
            if(s[j] == s[l]){
                int ans = solve(i, j-1, s) + solve(j, r, s);
                lalach = min(lalach, ans);
            }
        }
        return t[l][r] = min(basic, lalach);
    }

    int strangePrinter(string s) {
        n = s.length();
        t.resize(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, s);
    }
};