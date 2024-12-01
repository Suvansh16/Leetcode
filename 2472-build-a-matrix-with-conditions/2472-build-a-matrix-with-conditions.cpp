class Solution {
public:
    bool solve(vector<int>& ans, vector<bool>& visited, vector<bool>& inrecursion, int val, unordered_map<int, vector<int>>& graph) {
        visited[val] = true;
        inrecursion[val] = true;

        for (auto neighbor : graph[val]) {
            if (!visited[neighbor]) {
                if (!solve(ans, visited, inrecursion, neighbor, graph)) {
                    return false; // Cycle detected
                }
            } else if (inrecursion[neighbor]) {
                return false; // Cycle detected via recursion stack
            }
        }

        inrecursion[val] = false; // Mark node as backtracked
        ans.push_back(val); // Add node to topological order
        return true;
    }

    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        unordered_map<int, vector<int>> graph;
        for (auto& condition : conditions) {
            graph[condition[0]].push_back(condition[1]);
        }

        vector<bool> visited(k + 1, false);
        vector<bool> inrecursion(k + 1, false);
        vector<int> ans;

        for (int i = 1; i <= k; i++) {
            if (!visited[i]) {
                if (!solve(ans, visited, inrecursion, i, graph)) {
                    return {}; // Cycle detected
                }
            }
        }

        reverse(ans.begin(), ans.end()); // Reverse to get the correct topological order
        return ans;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        // Get topological orders for rows and columns
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.empty() || colOrder.empty()) {
            return {}; // If a cycle is detected in either condition, return an empty matrix
        }

        // Map the order of elements to their positions
        unordered_map<int, int> rowPos, colPos;
        for (int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        // Build the matrix
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            matrix[rowPos[i]][colPos[i]] = i;
        }

        return matrix;
    }
};
