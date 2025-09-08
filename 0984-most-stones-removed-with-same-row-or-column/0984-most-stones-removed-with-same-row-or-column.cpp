class Solution {
public:
    int solve(int start, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph) {
        int count = 1;
        visited.insert(start);

        for (int nei : graph[start]) {
            if (visited.find(nei) == visited.end()) {
                count += solve(nei, visited, graph);
            }
        }
        return count;
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        unordered_map<int,vector<int>> graph;

        for (int i = 0; i < stones.size(); i++) {
            int a = stones[i][0], b = stones[i][1];

            if (row.find(a) != row.end()) {
                graph[i].push_back(row[a]);
                graph[row[a]].push_back(i);
            } else {
                row[a] = i;
            }

            if (col.find(b) != col.end()) {
                graph[i].push_back(col[b]);
                graph[col[b]].push_back(i);
            } else {
                col[b] = i;
            }
        }

        unordered_set<int> visited;
        int ans = 0;

        for (int i = 0; i < stones.size(); i++) {
            if (visited.find(i) == visited.end()) {
                int l = solve(i, visited, graph);
                ans += (l - 1);  // ✅ add instead of max
            }
        }
        return ans;
    }
};
