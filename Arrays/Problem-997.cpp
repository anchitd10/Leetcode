// Problem-997: Find the Town Judge

// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
// If the town judge exists, then:
// - The town judge trusts nobody.
// - Everybody (except for the town judge) trusts the town judge.
// - There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.
// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
// Example 1:
// Input: n = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1
// Example 2:
// Input: n = 2, trust = [[1,2]]
// Output: 2


// Approach-1:
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1);  // 1-based indexing
        vector<int> outdegree(n + 1);

        for (vector<int>& vec : trust) {
            int a = vec[0];
            int b = vec[1];

            outdegree[a]++;
            indegree[b]++;
        }

        for (int i = 1; i <= n; i++) {  // 1-based indexing
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};