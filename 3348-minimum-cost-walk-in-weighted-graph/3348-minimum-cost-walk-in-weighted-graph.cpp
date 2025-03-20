class Solution {
public:
    vector<int> parent, rank, cost;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    void Union(int x, int y, int edge_cost) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                cost[rootX] &= cost[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                cost[rootY] &= cost[rootX];
            } else {
                parent[rootY] = rootX;
                cost[rootX] &= cost[rootY];
                rank[rootX]++;  // Increase rank only when merging equal rank sets
            }
        }
        cost[find(x)] &= edge_cost;  // Update the cost of the new representative
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        rank.resize(n, 1);
        cost.resize(n, -1);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int a = edge[0], b = edge[1], c = edge[2];
            Union(a, b, c);
        }

        vector<int> result;
        for (auto& q : query) {
            int a = q[0], b = q[1];
            if (a == b) {
                result.push_back(0);
            } else if (find(a) != find(b)) {
                result.push_back(-1);
            } else {
                result.push_back(cost[find(a)]);
            }
        }
        return result;
    }
};
