class Solution {
public:
    void dfs(unordered_map<int, int>& dist, int start, int dis, unordered_set<int>& visited, vector<int>& edges) {
        if (start == -1 || visited.count(start)) return;
        dist[start] = dis;
        visited.insert(start);
        dfs(dist, edges[start], dis + 1, visited, edges);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, int> dist1, dist2;
        unordered_set<int> visited1, visited2;

        dfs(dist1, node1, 0, visited1, edges);
        dfs(dist2, node2, 0, visited2, edges);

        int ans = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < edges.size(); ++i) {
            if (dist1.count(i) && dist2.count(i)) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist || (maxDist == minDist && i < ans)) {
                    minDist = maxDist;
                    ans = i;
                }
            }
        }

        return ans;
    }
};
