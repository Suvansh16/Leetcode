class Solution {
public:
    void solve(vector<vector<int>>& adj, vector<bool>& visited, int start) {
        if (visited[start]) return;
        visited[start] = true;
        for (int i : adj[start]) {
            solve(adj, visited, i);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);  // FIXED: initialize with n
        for (auto& i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                solve(adj, visited, i);
            }
        }

        int edges = connections.size();
        if (edges < n - 1) return -1; // not enough edges
        return count - 1;
    }
};
