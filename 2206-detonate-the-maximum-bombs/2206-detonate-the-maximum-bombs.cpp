class Solution {
public:
    typedef long long ll;

    int dfs(int start, vector<bool>& visited, unordered_map<int, vector<int>>& map) {
        visited[start] = true;
        int count = 1;
        for (int i = 0; i < map[start].size(); i++) {
            if (!visited[map[start][i]]) {
                count += dfs(map[start][i], visited, map);
            }
        }
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> map;
        int n = bombs.size();

        // Construct directed graph: i → j if i can detonate j
        for (int i = 0; i < n; i++) {
            ll x1 = bombs[i][0], y1 = bombs[i][1], r1 = 1LL * bombs[i][2] * bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                ll x2 = bombs[j][0], y2 = bombs[j][1];
                ll dx = x1 - x2, dy = y1 - y2;
                ll dist2 = dx * dx + dy * dy;
                if (dist2 <= r1) {
                    map[i].push_back(j); // i can detonate j
                }
            }
        }

        // Try detonating each bomb individually
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false); // reset for each start point
            int count = dfs(i, visited, map);
            ans = max(ans, count);
        }

        return ans;
    }
};
