class Solution {
public:
    int ans;

    void dfs(unordered_map<int, vector<pair<int, int>>>& map, int start, vector<bool>& visited) {
        visited[start] = true;
        
        for (pair<int, int>& p : map[start]) {
            int a = p.first;
            int b = p.second;

            // Update the minimum score
            ans = min(ans, b);

            // Continue DFS if the node has not been visited
            if (!visited[a]) {
                dfs(map, a, visited);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> map;

        // Build the adjacency list
        for (int i = 0; i < roads.size(); i++) {
            map[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            map[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<bool> visited(n + 1, false);
        ans = INT_MAX;

        // Start DFS from node 1
        dfs(map, 1, visited);

        return ans;
    }
};
