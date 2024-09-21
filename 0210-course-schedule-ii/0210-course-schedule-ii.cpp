class Solution {
public:
    bool solve(int node, unordered_map<int, vector<int>>& map, vector<bool>& visited, vector<bool>& dfsvisit, vector<int>& ans) {
        visited[node] = true;
        dfsvisit[node] = true;
        for (auto i : map[node]) {
            if (!visited[i]) {
                bool cycle = solve(i, map, visited, dfsvisit, ans);
                if (cycle)
                    return true;
            }
            else if (dfsvisit[i]) {
                return true;  // cycle detected
            }
        }
        dfsvisit[node] = false;
        ans.push_back(node); // Add after visiting all neighbors (for topological sort)
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int, vector<int>> map;
        
        // Constructing the adjacency list
        for (int i = 0; i < prerequisites.size(); i++) {
            map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        int n = numCourses;
        vector<bool> visited(n, false);
        vector<bool> dfsvisit(n, false);

        // Check for cycles and perform DFS for topological sort
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bool hasCycle = solve(i, map, visited, dfsvisit, ans);
                if (hasCycle)
                    return {}; // Return empty if cycle is detected
            }
        }
        
        return ans;
    }
};
