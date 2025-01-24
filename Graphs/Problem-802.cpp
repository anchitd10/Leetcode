// Problem-802: Find Eventual Safe States

// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
// Example 1:
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.
// Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
// Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int n=graph.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for(int i=0; i<n ; i++){
            for(int j=graph[i].size()-1; j>=0; j--){
                int v=graph[i][j];
                adj[v].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;

        for(int i=n-1; i>=0; i--)
            if (indeg[i]==0) q.push(i);

        vector<bool> safe(n, 0);
        while(!q.empty()){
            int x=q.front();
        //    cout<<x<<"->";;
            q.pop();
            safe[x]=1;
            for(int y: adj[x]){
        //        cout<<y<<",";
                if (--indeg[y]==0)
                    q.push(y);
            }
        //    cout<<endl;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
            if (safe[i]) ans.push_back(i);
        return ans;
    }
};