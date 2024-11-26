class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        
        // Build the indegree for each node
        for (const auto& edge : edges) {
            indegree[edge[1]]++;
        }
        
        // Find the node with the minimum indegree
        int min_indegree = INT_MAX;
        int champion = -1;
        
        for (int i = 0; i < n; i++) {
            if (indegree[i] < min_indegree) {
                min_indegree = indegree[i];
                champion = i;
            }
        }
        
        // Count how many nodes have the same minimum indegree
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == min_indegree) {
                count++;
            }
        }
        
        // If more than one node has the minimum indegree, return -1
        return count > 1 ? -1 : champion;
    }
};
