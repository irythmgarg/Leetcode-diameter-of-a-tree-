class Solution {
public:
    // Main function to calculate the diameter of a tree given its edges
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;  // Total number of nodes in the tree

        // Step 1: Build the adjacency list from the edge list
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Step 2: Use two BFS passes to find the diameter of the tree
        return findDiameter(n, adj);
    }

private:
    // Function to compute diameter using two BFS traversals
    int findDiameter(int n, unordered_map<int, vector<int>>& adj) {
        // First BFS from an arbitrary node (0) to find the farthest node from it
        auto [farthestNode, _] = findFarthestNode(n, adj, 0);

        // Second BFS from the farthest node to determine the diameter
        auto [__, diameter] = findFarthestNode(n, adj, farthestNode);

        return diameter;
    }

    // Helper function to find the farthest node and its distance using BFS
    pair<int, int> findFarthestNode(int n, unordered_map<int, vector<int>>& adj, int start) {
        vector<bool> visited(n, false);
        queue<int> que;
        que.push(start);
        visited[start] = true;

        int maxDistance = 0;
        int farthestNode = start;

        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                int node = que.front();
                que.pop();
                farthestNode = node;  // Track the last node in the level

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        que.push(neighbor);
                    }
                }
            }
            if (!que.empty()) maxDistance++;
        }

        return {farthestNode, maxDistance};
    }
};
