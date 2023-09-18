class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0}; // Special case: only one node, it's the root of the minimum height tree.
        }

        vector<vector<int>> graph(n);  // Adjacency list
        vector<int> indegree(n, 0);    // Indegree of nodes
        vector<int> ans;               // Answer array

        // Build the adjacency list and compute the indegree for each node
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 1) {
                q.push(i); // Initialize the queue with leaf nodes (indegree 1)
            }
        }

        while (!q.empty()) {
            int s = q.size();
            ans.clear(); // We only want to store the last level of nodes

            for (int i = 0; i < s; ++i) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                // Reduce the indegree of the neighbors and add them to the queue if their indegree becomes 1
                for (int neighbor : graph[node]) {
                    if (--indegree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return ans;
    }
};