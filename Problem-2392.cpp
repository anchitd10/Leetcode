// Problem-2392: Build a matrix with conditions

// You are given a positive integer k. You are also given:
// 1. 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
// 2. 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.
// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.
// The matrix should also satisfy the following conditions:
// The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
// The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix
// Example:
// Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output: [[3,0,0],[0,0,1],[0,2,0]]
// Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
// The row conditions are the following:
// - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
// - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
// The column conditions are the following:
// - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
// - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
// Note that there may be multiple correct answers.

class Solution
{
public:
    vector<vector<int>> AdjMatrix(int k, vector<vector<int>> &Conditions)
    {
        vector<vector<int>> gr(k + 1);
        for (auto i : Conditions)
        {
            int u = i[0];
            int v = i[1];
            gr[u].push_back(v);
        }
        return gr;
    }
    vector<int> TopoSort(int k, vector<vector<int>> &gr)
    {
        vector<int> indeg(k + 1, 0);
        for (int node = 1; node <= k; node++)
        {
            for (auto i : gr[node])
                indeg[i]++;
        }
        queue<int> q;
        vector<int> visit(k + 1, 0);
        for (int node = 1; node <= k; node++)
        {
            if (indeg[node] == 0)
                q.push(node);
        }
        vector<int> topo;
        while (!q.empty())
        {
            int qs = q.size();
            while (qs--)
            {
                int node = q.front();
                q.pop();
                visit[node] = true;
                topo.push_back(node);
                for (auto i : gr[node])
                {
                    if (!visit[i])
                    {
                        indeg[i]--;
                        if (indeg[i] == 0)
                            q.push(i);
                    }
                }
            }
        }
        vector<int> notTopo;
        for (int node = 1; node <= k; node++)
        {
            if (indeg[node] != 0)
                return notTopo;
        }
        return topo;
    }
    void filltopoMatrix(int k, vector<int> &topo)
    {
        unordered_map<int, bool> vis;
        for (auto i : topo)
            vis[i] = true;
        for (int i = 1; i <= k; i++)
        {
            if (!vis[i])
                topo.push_back(i);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> rg = AdjMatrix(k, rowConditions);
        vector<vector<int>> cg = AdjMatrix(k, colConditions);
        vector<int> rowtopo = TopoSort(k, rg);
        vector<int> coltopo = TopoSort(k, cg);
        vector<vector<int>> ans;
        if (rowtopo.size() == 0 || coltopo.size() == 0)
            return ans;
        filltopoMatrix(k, rowtopo);
        filltopoMatrix(k, coltopo);
        unordered_map<int, int> colInd;
        for (int i = 0; i < k; i++)
            colInd[coltopo[i]] = i;
        ans = vector<vector<int>>(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
            ans[i][colInd[rowtopo[i]]] = rowtopo[i];
        return ans;
    }
};