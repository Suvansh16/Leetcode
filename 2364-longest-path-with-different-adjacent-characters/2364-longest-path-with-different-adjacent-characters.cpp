class Solution {
public:
    int ans = 1;

    int dfs(int node, unordered_map<int, vector<int>>& adj, string& s, int parent) {
        int max1 = 0, max2 = 0; // Top two longest valid child paths

        for (int child : adj[node]) {
            if (child == parent) continue;
            int len = dfs(child, adj, s, node);
            if (s[child] != s[node]) {
                if (len > max1) {
                    max2 = max1;
                    max1 = len;
                } else if (len > max2) {
                    max2 = len;
                }
            }
        }

        ans = max(ans, 1 + max1 + max2); // Path through this node
        return 1 + max1; // Return longest single path going down
    }

    int longestPath(vector<int>& parent, string s) {
        unordered_map<int, vector<int>> adj;
        int n = parent.size();

        for (int i = 1; i < n; ++i) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        dfs(0, adj, s, -1);
        return ans;
    }
};
